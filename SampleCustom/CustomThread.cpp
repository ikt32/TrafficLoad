#include "CustomThread.h"
#include "Scripting.h"
#include "../ScriptHook/Log.h"

#include <iostream>
#include <string>
#include <map>
#include <windows.h>

#define countof( array ) ( sizeof( array )/sizeof( array[0] ) )

// Pull in all our scripting functions/types
using namespace Scripting;
using std::string;

CustomThread::CustomThread()
{
    // Give your own name here!
	SetName("TrafficLoad");
}

void CustomThread::RunTick()
{
	Wait(5000);									// Script executes every 5 seconds.
	count = 0;									// Reset the counter, recounting will happen in the tick.

	// Read TrafficLoad.ini
	int CustomDensity = GetPrivateProfileInt(TEXT("Options"),TEXT("CustomDensity"),0,TEXT("./TrafficLoad.ini"));
	int PedMult = GetPrivateProfileInt(TEXT("Options"),TEXT("PedDensityMultiplier"),100,TEXT("./TrafficLoad.ini"));
	int CarMult = GetPrivateProfileInt(TEXT("Options"),TEXT("CarDensityMultiplier"),100,TEXT("./TrafficLoad.ini"));
	int CarsPerCycle = GetPrivateProfileInt(TEXT("Options"),TEXT("CarsPerCycle"),10,TEXT("./TrafficLoad.ini"));
	int CustomCars = GetPrivateProfileInt(TEXT("AddedCars"),TEXT("Enable"),0,TEXT("./TrafficLoad.ini"));

	// Initializing and getting player info
	Player PlayerIndex = ConvertIntToPlayerIndex(GetPlayerId());
	Ped PlayerChar;
    GetPlayerChar(PlayerIndex, &PlayerChar);
	GetCharCoordinates(PlayerChar, &x, &y, &z);
	b8 airport = IsCharInArea2D(PlayerChar, 2165.92f, 912.35f, 2924.75f, -145.64f, false);
	b8 police = IsWantedLevelGreater(PlayerIndex, 3);
	
	// Liberty City traffic
	eModel veh[] = { MODEL_ADMIRAL, MODEL_AMBULANCE, MODEL_BANSHEE, MODEL_BENSON, MODEL_BIFF, MODEL_BLISTA, MODEL_BOBCAT, MODEL_BOXVILLE, MODEL_BUCCANEER, MODEL_BURRITO, MODEL_BURRITO2, MODEL_BUS, MODEL_CAVALCADE, MODEL_CHAVOS, MODEL_COGNOSCENTI, MODEL_COMET, MODEL_COQUETTE, MODEL_DF8, MODEL_DILETTANTE, MODEL_DUKES, MODEL_E109, MODEL_EMPEROR, MODEL_EMPEROR2, MODEL_ESPERANTO, MODEL_FACTION, MODEL_FBI, MODEL_FELTZER, MODEL_FEROCI, MODEL_FIRETRUK, MODEL_FLATBED, MODEL_FORTUNE, MODEL_FUTO, MODEL_FXT, MODEL_HABANERO, MODEL_HAKUMAI, MODEL_HUNTLEY, MODEL_INFERNUS, MODEL_INGOT, MODEL_INTRUDER, MODEL_LANDSTALKER, MODEL_LOKUS, MODEL_MANANA, MODEL_MARBELLA, MODEL_MERIT, MODEL_MINIVAN, MODEL_MOONBEAM, MODEL_MRTASTY, MODEL_MULE, MODEL_ORACLE, MODEL_PACKER, MODEL_PATRIOT, MODEL_PERENNIAL, MODEL_PERENNIAL2, MODEL_PEYOTE, MODEL_PHANTOM, MODEL_PINNACLE, MODEL_PMP600, MODEL_POLICE, MODEL_POLICE2, MODEL_PONY, MODEL_PREMIER, MODEL_PRES, MODEL_PRIMO, MODEL_PSTOCKADE, MODEL_RANCHER, MODEL_REBLA, MODEL_ROMERO, MODEL_RUINER, MODEL_SABRE, MODEL_SABRE2, MODEL_SABREGT, MODEL_SCHAFTER, MODEL_SENTINEL, MODEL_SOLAIR, MODEL_SPEEDO, MODEL_STALION, MODEL_STEED, MODEL_STOCKADE, MODEL_STRATUM, MODEL_STRETCH, MODEL_SULTAN, MODEL_SULTANRS, MODEL_SUPERGT, MODEL_TRASH, MODEL_TURISMO, MODEL_URANUS, MODEL_VIGERO, MODEL_VIGERO2, MODEL_VINCENT, MODEL_VIRGO, MODEL_VOODOO, MODEL_WASHINGTON, MODEL_WILLARD, MODEL_YANKEE, MODEL_BOBBER, MODEL_FAGGIO, MODEL_HELLFURY, MODEL_NRG900, MODEL_PCJ, MODEL_SANCHEZ, MODEL_ZOMBIEB };
	GenerateRandomIntInRange(0, countof(veh) - 1, &vrand);
	
	// Transport
	eModel service[] = { MODEL_BUS };
	GenerateRandomIntInRange(0, /*countof(service) - 1*/11, &srand);
	
	// Taxi, We want to see less of these and the game has them loaded anyway
	eModel taxi[] = { MODEL_TAXI, MODEL_TAXI2, MODEL_CABBY };

	// Special police vehicles
	eModel policeveh[] = { MODEL_NOOSE, MODEL_NSTOCKADE, MODEL_POLPATRIOT };

	// Stuff allowed to spawn at the airport
	eModel airportveh[] = { MODEL_AIRTUG, MODEL_FEROCI2, MODEL_PERENNIAL2, MODEL_BUS, MODEL_CABBY, MODEL_RIPLEY, MODEL_BENSON, MODEL_BOXVILLE, MODEL_FORKLIFT, MODEL_MULE, MODEL_PACKER, MODEL_PONY, MODEL_STOCKADE, MODEL_SPEEDO, MODEL_YANKEE, MODEL_STEED };
	GenerateRandomIntInRange(0, countof(airportveh) - 1, &arand);

	// Stuff exclusively spawning at the airport
	eModel airportvehex[] = { MODEL_AIRTUG, MODEL_FEROCI2, MODEL_PERENNIAL2, MODEL_RIPLEY};

	if (CustomDensity == 1) {
		SetRandomCarDensityMultiplier(f32(CarMult/100));
		SetPedDensityMultiplier(f32(PedMult/100));
	}
	
	// Count everything
	for (int i = 0; i < countof(veh); i++){
		if (HasModelLoaded(veh[i])) {
			count++;
		}
	}
	for (int i = 0; i < countof(airportvehex); i++){
		if (HasModelLoaded(airportvehex[i])) {
			count++;
		}
	}
	for (int i = 0; i < countof(policeveh); i++){
		if (HasModelLoaded(policeveh[i])) {
			count++;
		}
	}
	for (int i = 0; i < countof(taxi); i++){
		if (HasModelLoaded(taxi[i])) {
			count++;
		}
	}

	// Custom cars from the .ini are read. Behind the counting for the added cars to be counted with everything else
	if (CustomCars == 1) {
		int AmountAdded = GetPrivateProfileInt(TEXT("AddedCars"), TEXT("Amount"), 0, TEXT("./TrafficLoad.ini")); //counts added cars
		char Carm[128][128]; //defines the carm variable
		char thing[128]; //defines the temporary name thing
		for (int n = AmountAdded; n>0; n--){ //loop thingy to get the car names
			sprintf_s(thing, "%d", n); //number to string
			GetPrivateProfileString("addedcars", thing, NULL, Carm[n], 128, "./TrafficLoad.ini"); //gets names and saves for future use
		}

		for (int n = AmountAdded; n>0 ; n--){
			if (HasModelLoaded(GetModelHash(Carm[n]))) {
				count++;
			}
		}

		if ((int(count) >= CarsPerCycle) || police || airport) {
			for (int n = AmountAdded; n>0; n--) {
				MarkModelAsNoLongerNeeded(GetModelHash(Carm[n])); //SHOULD unload all called cars
			}
		}

		//loading added models with its down random integer
		for (int n = AmountAdded; n > 0; n--) {
			GenerateRandomIntInRange(1, 5, &customrand);
			if (((HasModelLoaded(GetModelHash(Carm[n]))) == false) && (customrand == 2)) {
				RequestModel(GetModelHash(Carm[n]));
			}
		}
	}


	// Debug info, display exact number of loaded cars including added cars
	PrintHelpWithNumber("NUMBER", count);

	// Try to not load anything while the game is not finished unloading models, player has wantedlevel >=3 or is in airport
	if ((int(count) < CarsPerCycle) && !police && !airport) {
		// Service cars, have more of a chance to load (Only loads bus now), chance is 1/12th per 5 seconds.
		for (int i = 0; i < countof(service); i++){
			if ((HasModelLoaded(service[i]) == false) && (srand == i)) {
				RequestModel(service[i]);
			}
		}

		// Normal traffic
		for (int i = 0; i < countof(veh); i++){
			if ((HasModelLoaded(veh[i]) == false) && (vrand == i)) {
				RequestModel(veh[i]);
			}
		}
	}

	// Airport traffic
	if ((int(count) < CarsPerCycle) && airport) {
		for (int i = 0; i < countof(airportveh); i++){
			if ((HasModelLoaded(airportveh[i]) == false)) {
				RequestModel(airportveh[i]);
			}
		}
	}
	else {
		for (int i = 0; i < countof(airportvehex); i++){
			MarkModelAsNoLongerNeeded(airportvehex[i]);
		}
	}
	
	// If more cars are loaded than the number given in TrafficLoad.ini, try to unload all unused models
	if ((int(count) >= CarsPerCycle)/* || police*/ || airport) {
		for (int i = 0; i < countof(veh); i++){
			MarkModelAsNoLongerNeeded(veh[i]);
		}
		for (int i = 0; i < countof(taxi); i++){
			MarkModelAsNoLongerNeeded(taxi[i]);
		}
		for (int i = 0; i < countof(airportvehex); i++){
			MarkModelAsNoLongerNeeded(airportvehex[i]);
		}
		for (int i = 0; i < countof(policeveh); i++){
			MarkModelAsNoLongerNeeded(policeveh[i]);
		}
	}
	/*
	for (auto eModel : veh){

	}
	*/
	

	// Unloads on all cycles because these load too damn often anyway
	for (int i = 0; i < countof(taxi); i++){
		MarkModelAsNoLongerNeeded(taxi[i]);
	}
}
