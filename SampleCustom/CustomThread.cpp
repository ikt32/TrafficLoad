#include "CustomThread.h"
#include "Scripting.h"
#include "../ScriptHook/Log.h"

#include <iostream>
#include <string>
#include <map>
#include <windows.h>

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
	countloaded = 0;
	timer++;									// Stars a timer ticking away.
	GenerateRandomIntInRange(1, 150, &rand);	// Random number generator for car choosing purposes
	GenerateRandomIntInRange(1, 24, &bikerand);	// 

	// Custom density reading
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
	b8 playing = DoesCharExist(PlayerChar);
	//b8 airportunload;

	//DisplayTextWithNumber(0.8, 0.8, "NUMBER", count);
	//DisplayTextWithNumber(0.8, 0.9, "NUMBER", countloaded);
	PrintWith2NumbersNow("NUMBER", count, countloaded, 5000, true);
	if (airport == true) {
	PrintStringWithLiteralStringNow("STRING", "In Airport", 5000, true);
	}

	if (CustomDensity == 1) {
		SetRandomCarDensityMultiplier(f32(CarMult/100));
		SetPedDensityMultiplier(f32(PedMult/100));
	}

	if (CustomCars == 1) {
		int AmountAdded = GetPrivateProfileInt(TEXT("AddedCars"),TEXT("Amount"),0,TEXT("./TrafficLoad.ini")); //counts added cars
		char Carm[128][128]; //defines the carm variable
		char thing[128]; //defines the temporary name thing
		for(int n=AmountAdded; n>0; n--){ //loop thingy to get the car names
			sprintf_s(thing, "%d", n); //number to string
			GetPrivateProfileString("addedcars",thing,NULL,Carm[n],128,"./TrafficLoad.ini"); //gets names and saves for future use
		}
		

		if ((/*(police == true) || */(playing == false) || (IsPlayerDead(PlayerIndex) == true)) || ((int(count) >= CarsPerCycle))) {
			for(int n=AmountAdded; n>0; n--) {
				MarkModelAsNoLongerNeeded(GetModelHash(Carm[n])); //SHOULD unload all called cars
			}
		}

		//loading added models with its down random integer
		for (int n=AmountAdded; n>0; n--) {
			GenerateRandomIntInRange(1, 5, &rand2);
			if ( ((HasModelLoaded(GetModelHash(Carm[n]))) == false) && (rand2 == 2) ) {
				RequestModel(GetModelHash(Carm[n]));
				count++;
			}
		}
	}

	if ((airport == true) && (police == false)) {
		airportunload = true;
		RequestModel(MODEL_FEROCI2);
		RequestModel(MODEL_BUS); 
		RequestModel(MODEL_PERENNIAL2); 
		RequestModel(MODEL_CABBY);
	}
	else if (airportunload == true){
		if (HasModelLoaded(MODEL_PERENNIAL2)){ MarkModelAsNoLongerNeeded(MODEL_PERENNIAL2); }
		if (HasModelLoaded(MODEL_FEROCI2)) { MarkModelAsNoLongerNeeded(MODEL_FEROCI2); }
		if ( (HasModelLoaded(MODEL_FEROCI2) && HasModelLoaded(MODEL_PERENNIAL2)) == false ) { airportunload = false; }
	}

	//if (timer >= 5) {
	//	for (int i=timer;i=0;i--)
	//	{
			MarkModelAsNoLongerNeeded(MODEL_TAXI);
			MarkModelAsNoLongerNeeded(MODEL_TAXI2);
			MarkModelAsNoLongerNeeded(MODEL_CABBY);
	//	timer2++;
	//	if (timer2 >= 40) {
	//		timer2 = 0;
	//		timer = 0;
	//	}
	//		MarkModelAsNoLongerNeeded(MODEL_TAXI2);
	//		MarkModelAsNoLongerNeeded(MODEL_CABBY);
	//	}
	//	timer = 0;
	//}

	// Count everything
	if (HasModelLoaded(MODEL_BUS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_TAXI)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_TAXI2)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_CABBY)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_ADMIRAL)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BLISTA)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BOBCAT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BUCCANEER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BURRITO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_CAVALCADE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_CHAVOS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_DF8)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_DILETTANTE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_E109)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_EMPEROR)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_ESPERANTO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FACTION)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FEROCI)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FORTUNE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FUTO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FXT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_HABANERO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_HAKUMAI)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_HUNTLEY)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_INGOT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_INTRUDER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_LANDSTALKER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_LOKUS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MANANA)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PEYOTE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MARBELLA)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MERIT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MINIVAN)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MOONBEAM)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PERENNIAL)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PINNACLE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PREMIER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PRES)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PRIMO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_REBLA)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_RUINER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SABRE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SOLAIR)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SPEEDO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_STRATUM)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SULTAN)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_URANUS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_VIGERO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_VINCENT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_VIRGO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_WASHINGTON)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_WILLARD)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PATRIOT)) {
		countloaded++;
	} 
	if (HasModelLoaded(MODEL_BANSHEE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_COMET)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_COQUETTE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_DUKES)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FELTZER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_INFERNUS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SABREGT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SENTINEL)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_STALION)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SULTANRS)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SUPERGT)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_TURISMO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_CAVALCADE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_COGNOSCENTI)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_MRTASTY)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_ORACLE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PMP600)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SCHAFTER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_STRETCH)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PEYOTE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BURRITO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BURRITO2)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_EMPEROR2)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_VIGERO2)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BENSON)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BIFF)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BOXVILLE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BURRITO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BURRITO2)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FLATBED)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PHANTOM)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PONY)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_STEED)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_STOCKADE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_TRASH)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_YANKEE)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PACKER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_BOBBER)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_FAGGIO)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_HELLFURY)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_NRG900)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_SANCHEZ)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_PCJ)) {
		countloaded++;
	}
	if (HasModelLoaded(MODEL_ZOMBIEB)) {
		countloaded++;
	}


	if ( (police == true) || (playing == false) || (IsPlayerDead(PlayerIndex) == true) || (int(count) >= CarsPerCycle) ) {
		MarkModelAsNoLongerNeeded(MODEL_PACKER);
		MarkModelAsNoLongerNeeded(MODEL_PATRIOT);
		MarkModelAsNoLongerNeeded(MODEL_ADMIRAL);
		MarkModelAsNoLongerNeeded(MODEL_BLISTA);
		MarkModelAsNoLongerNeeded(MODEL_BOBCAT);
		MarkModelAsNoLongerNeeded(MODEL_BUCCANEER);
		MarkModelAsNoLongerNeeded(MODEL_BURRITO);
		MarkModelAsNoLongerNeeded(MODEL_CAVALCADE);
		MarkModelAsNoLongerNeeded(MODEL_CHAVOS);
		MarkModelAsNoLongerNeeded(MODEL_DF8);
		MarkModelAsNoLongerNeeded(MODEL_DILETTANTE);
		MarkModelAsNoLongerNeeded(MODEL_E109);
		MarkModelAsNoLongerNeeded(MODEL_EMPEROR);
		MarkModelAsNoLongerNeeded(MODEL_ESPERANTO);
		MarkModelAsNoLongerNeeded(MODEL_FACTION);
		MarkModelAsNoLongerNeeded(MODEL_FEROCI);
		MarkModelAsNoLongerNeeded(MODEL_FORTUNE);
		MarkModelAsNoLongerNeeded(MODEL_FUTO);
		MarkModelAsNoLongerNeeded(MODEL_FXT);
		MarkModelAsNoLongerNeeded(MODEL_HABANERO);
		MarkModelAsNoLongerNeeded(MODEL_HAKUMAI);
		MarkModelAsNoLongerNeeded(MODEL_HUNTLEY);
		MarkModelAsNoLongerNeeded(MODEL_INGOT);
		MarkModelAsNoLongerNeeded(MODEL_INTRUDER);
		MarkModelAsNoLongerNeeded(MODEL_LANDSTALKER);
		MarkModelAsNoLongerNeeded(MODEL_LOKUS);
		MarkModelAsNoLongerNeeded(MODEL_MANANA);
		MarkModelAsNoLongerNeeded(MODEL_PEYOTE);
		MarkModelAsNoLongerNeeded(MODEL_MARBELLA);
		MarkModelAsNoLongerNeeded(MODEL_MERIT);
		MarkModelAsNoLongerNeeded(MODEL_MINIVAN);
		MarkModelAsNoLongerNeeded(MODEL_MOONBEAM);
		MarkModelAsNoLongerNeeded(MODEL_PERENNIAL);
		MarkModelAsNoLongerNeeded(MODEL_PINNACLE);
		MarkModelAsNoLongerNeeded(MODEL_PREMIER);
		MarkModelAsNoLongerNeeded(MODEL_PRES);
		MarkModelAsNoLongerNeeded(MODEL_PRIMO);
		MarkModelAsNoLongerNeeded(MODEL_REBLA);
		MarkModelAsNoLongerNeeded(MODEL_RUINER);
		MarkModelAsNoLongerNeeded(MODEL_SABRE);
		MarkModelAsNoLongerNeeded(MODEL_SOLAIR);
		MarkModelAsNoLongerNeeded(MODEL_SPEEDO);
		MarkModelAsNoLongerNeeded(MODEL_STRATUM);
		MarkModelAsNoLongerNeeded(MODEL_SULTAN);
		MarkModelAsNoLongerNeeded(MODEL_URANUS);
		MarkModelAsNoLongerNeeded(MODEL_VIGERO);
		MarkModelAsNoLongerNeeded(MODEL_VINCENT);
		MarkModelAsNoLongerNeeded(MODEL_VIRGO);
		MarkModelAsNoLongerNeeded(MODEL_WASHINGTON);
		MarkModelAsNoLongerNeeded(MODEL_WILLARD);
		MarkModelAsNoLongerNeeded(MODEL_BANSHEE);
		MarkModelAsNoLongerNeeded(MODEL_COMET);
		MarkModelAsNoLongerNeeded(MODEL_COQUETTE);
		MarkModelAsNoLongerNeeded(MODEL_DUKES);
		MarkModelAsNoLongerNeeded(MODEL_FELTZER);
		MarkModelAsNoLongerNeeded(MODEL_INFERNUS);
		MarkModelAsNoLongerNeeded(MODEL_SABREGT);
		MarkModelAsNoLongerNeeded(MODEL_SENTINEL);
		MarkModelAsNoLongerNeeded(MODEL_STALION);
		MarkModelAsNoLongerNeeded(MODEL_SULTANRS);
		MarkModelAsNoLongerNeeded(MODEL_SUPERGT);
		MarkModelAsNoLongerNeeded(MODEL_TURISMO);
		MarkModelAsNoLongerNeeded(MODEL_CAVALCADE);
		MarkModelAsNoLongerNeeded(MODEL_COGNOSCENTI);
		MarkModelAsNoLongerNeeded(MODEL_MRTASTY);
		MarkModelAsNoLongerNeeded(MODEL_ORACLE);
		MarkModelAsNoLongerNeeded(MODEL_PMP600);
		MarkModelAsNoLongerNeeded(MODEL_SCHAFTER);
		MarkModelAsNoLongerNeeded(MODEL_STRETCH);
		MarkModelAsNoLongerNeeded(MODEL_PEYOTE);
		MarkModelAsNoLongerNeeded(MODEL_BURRITO);
		MarkModelAsNoLongerNeeded(MODEL_BURRITO2);
		MarkModelAsNoLongerNeeded(MODEL_EMPEROR2);
		MarkModelAsNoLongerNeeded(MODEL_VIGERO2);
		MarkModelAsNoLongerNeeded(MODEL_BENSON);
		MarkModelAsNoLongerNeeded(MODEL_BIFF);
		MarkModelAsNoLongerNeeded(MODEL_BOXVILLE);
		MarkModelAsNoLongerNeeded(MODEL_BURRITO);
		MarkModelAsNoLongerNeeded(MODEL_BURRITO2);
		MarkModelAsNoLongerNeeded(MODEL_FLATBED);
		MarkModelAsNoLongerNeeded(MODEL_PHANTOM);
		MarkModelAsNoLongerNeeded(MODEL_PONY);
		MarkModelAsNoLongerNeeded(MODEL_STEED);
		MarkModelAsNoLongerNeeded(MODEL_STOCKADE);
		MarkModelAsNoLongerNeeded(MODEL_TRASH);
		MarkModelAsNoLongerNeeded(MODEL_YANKEE);
		MarkModelAsNoLongerNeeded(MODEL_BUS);
		MarkModelAsNoLongerNeeded(MODEL_TAXI);
		MarkModelAsNoLongerNeeded(MODEL_TAXI2);
		MarkModelAsNoLongerNeeded(MODEL_CABBY);
		MarkModelAsNoLongerNeeded(MODEL_BOBBER);
		MarkModelAsNoLongerNeeded(MODEL_FAGGIO);
		MarkModelAsNoLongerNeeded(MODEL_HELLFURY);
		MarkModelAsNoLongerNeeded(MODEL_NRG900);
		MarkModelAsNoLongerNeeded(MODEL_SANCHEZ);
		MarkModelAsNoLongerNeeded(MODEL_PCJ);
		MarkModelAsNoLongerNeeded(MODEL_ZOMBIEB);
		count = 0;
	}

	//Service cars
	if (HasModelLoaded(MODEL_BUS) == false) { RequestModel(MODEL_BUS); }
	if ((HasModelLoaded(MODEL_TAXI) == false) && ((rand > 10) && (rand < 20))) { RequestModel(MODEL_TAXI); }
	if ((HasModelLoaded(MODEL_TAXI2) == false) && ((rand > 70) && (rand < 80))) { RequestModel(MODEL_TAXI2); }
	if ((HasModelLoaded(MODEL_CABBY) == false) && ((rand > 130) && (rand < 140))) { RequestModel(MODEL_CABBY); }
	
	//Normal cars
	if (((HasModelLoaded(MODEL_ADMIRAL)) == false) && (rand == 1 || rand == 2)){ RequestModel(MODEL_ADMIRAL);
	count++;}
	if (((HasModelLoaded(MODEL_BLISTA)) == false) && (rand == 3 || rand == 4)){ RequestModel(MODEL_BLISTA);
	count++;}
	if (((HasModelLoaded(MODEL_BOBCAT)) == false)  && (rand == 5 || rand == 6)){ RequestModel(MODEL_BOBCAT);
	count++;}
	if (((HasModelLoaded(MODEL_BUCCANEER)) == false) && (rand == 7 || rand == 8)){ RequestModel(MODEL_BUCCANEER);
	count++;}
	if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 9 || rand == 10)){ RequestModel(MODEL_BURRITO);
	count++;}
	if (((HasModelLoaded(MODEL_CAVALCADE)) == false) && (rand == 11 || rand == 12)){ RequestModel(MODEL_CAVALCADE);
	count++;}
	if (((HasModelLoaded(MODEL_CHAVOS)) == false) && (rand == 13 || rand == 14)){ RequestModel(MODEL_CHAVOS);
	count++;}
	if (((HasModelLoaded(MODEL_DF8)) == false) && (rand == 15 || rand == 16)){ RequestModel(MODEL_DF8);
	count++;}
	if (((HasModelLoaded(MODEL_DILETTANTE)) == false) && (rand == 17 || rand == 18)){ RequestModel(MODEL_DILETTANTE);
	count++;}
	if (((HasModelLoaded(MODEL_E109)) == false)  && (rand == 21 || rand == 22)){ RequestModel(MODEL_E109);
	count++;}
	if (((HasModelLoaded(MODEL_EMPEROR)) == false) && (rand == 23 || rand == 24)){ RequestModel(MODEL_EMPEROR);
	count++;}
	if (((HasModelLoaded(MODEL_ESPERANTO)) == false) && (rand == 25 || rand == 26)){ RequestModel(MODEL_ESPERANTO);
	count++;}
	if (((HasModelLoaded(MODEL_FACTION)) == false) && (rand == 27 || rand == 28)){ RequestModel(MODEL_FACTION);
	count++;}
	if (((HasModelLoaded(MODEL_FEROCI)) == false) && (rand == 29 || rand == 30)){ RequestModel(MODEL_FEROCI);
	count++;}
	if (((HasModelLoaded(MODEL_FORTUNE)) == false) && (rand == 31 || rand == 32)){ RequestModel(MODEL_FORTUNE);
	count++;}
	if (((HasModelLoaded(MODEL_FUTO)) == false) && (rand == 33 || rand == 34)){ RequestModel(MODEL_FUTO);
	count++;}
	if (((HasModelLoaded(MODEL_FXT)) == false) && (rand == 35 || rand == 36)){ RequestModel(MODEL_FXT);
	count++;}
	if (((HasModelLoaded(MODEL_HABANERO)) == false) && (rand == 37 || rand == 38)){ RequestModel(MODEL_HABANERO);
	count++;}
	if (((HasModelLoaded(MODEL_HAKUMAI)) == false) && (rand == 39 || rand == 40)){ RequestModel(MODEL_HAKUMAI);
	count++;}
	if (((HasModelLoaded(MODEL_HUNTLEY)) == false) && (rand == 41 || rand == 42)){ RequestModel(MODEL_HUNTLEY);
	count++;}
	if (((HasModelLoaded(MODEL_INGOT)) == false) && (rand == 43 || rand == 44)){ RequestModel(MODEL_INGOT);
	count++;}
	if (((HasModelLoaded(MODEL_INTRUDER)) == false) && (rand == 45 || rand == 46)){ RequestModel(MODEL_INTRUDER);
	count++;}
	if (((HasModelLoaded(MODEL_LANDSTALKER)) == false) && (rand == 47 || rand == 48)){ RequestModel(MODEL_LANDSTALKER);
	count++;}
	if (((HasModelLoaded(MODEL_LOKUS)) == false) && (rand == 49 || rand == 50)){ RequestModel(MODEL_LOKUS);
	count++;}
	if (((HasModelLoaded(MODEL_MANANA)) == false) && (rand == 51 || rand == 52)){ RequestModel(MODEL_MANANA);
	count++;}
	if (((HasModelLoaded(MODEL_PEYOTE)) == false) && (rand == 53 || rand == 54)){ RequestModel(MODEL_PEYOTE);
	count++;}
	if (((HasModelLoaded(MODEL_MARBELLA)) == false) && (rand ==55 || rand == 56)){ RequestModel(MODEL_MARBELLA);
	count++;}
	if (((HasModelLoaded(MODEL_MERIT)) == false) && (rand == 57 || rand == 58)){ RequestModel(MODEL_MERIT);
	count++;}
	if (((HasModelLoaded(MODEL_MINIVAN)) == false) && (rand == 59 || rand == 60)){ RequestModel(MODEL_MINIVAN);
	count++;}
	if (((HasModelLoaded(MODEL_MOONBEAM)) == false) && (rand == 61 || rand == 62)){ RequestModel(MODEL_MOONBEAM);
	count++;}
	if (((HasModelLoaded(MODEL_PERENNIAL)) == false) && (rand == 65 || rand == 66)){ RequestModel(MODEL_PERENNIAL);
	count++;}
	if (((HasModelLoaded(MODEL_PINNACLE)) == false) && (rand == 67 || rand == 68)){ RequestModel(MODEL_PINNACLE);
	count++;}
	if (((HasModelLoaded(MODEL_PREMIER)) == false) && (rand == 69 || rand == 70)){ RequestModel(MODEL_PREMIER);
	count++;}
	if (((HasModelLoaded(MODEL_PRES)) == false) && (rand == 71 || rand == 72)){ RequestModel(MODEL_PRES);
	count++;}
	if (((HasModelLoaded(MODEL_PRIMO)) == false) && (rand == 73 || rand == 74)){ RequestModel(MODEL_PRIMO);
	count++;}
	if (((HasModelLoaded(MODEL_REBLA)) == false) && (rand == 75 || rand == 76)){ RequestModel(MODEL_REBLA);
	count++;}
	if (((HasModelLoaded(MODEL_RUINER)) == false) && (rand == 77 || rand == 78)){ RequestModel(MODEL_RUINER);
	count++;}
	if (((HasModelLoaded(MODEL_SABRE)) == false) && (rand == 79 || rand == 80)){ RequestModel(MODEL_SABRE);
	count++;}
	if (((HasModelLoaded(MODEL_SOLAIR)) == false) && (rand == 85 || rand == 86)){ RequestModel(MODEL_SOLAIR);
	count++;}
	if (((HasModelLoaded(MODEL_SPEEDO)) == false) && (rand == 87 || rand == 88)){ RequestModel(MODEL_SPEEDO);
	count++;}
	if (((HasModelLoaded(MODEL_STRATUM)) == false) && (rand == 89 || rand == 90)){ RequestModel(MODEL_STRATUM);
	count++;}
	if (((HasModelLoaded(MODEL_SULTAN)) == false) && (rand == 91 || rand == 92)){ RequestModel(MODEL_SULTAN);
	count++;}
	if (((HasModelLoaded(MODEL_URANUS)) == false) && (rand == 93 || rand == 94)){ RequestModel(MODEL_URANUS);
	count++;}
	if (((HasModelLoaded(MODEL_VIGERO)) == false) && (rand == 95 || rand == 96)){ RequestModel(MODEL_VIGERO);
	count++;}
	if (((HasModelLoaded(MODEL_VINCENT)) == false) && (rand == 97 || rand == 98)){ RequestModel(MODEL_VINCENT);
	count++;}
	if (((HasModelLoaded(MODEL_VIRGO)) == false) && (rand == 99 || rand == 100)){ RequestModel(MODEL_VIRGO);
	count++;}
	if (((HasModelLoaded(MODEL_WASHINGTON)) == false) && (rand == 101 || rand == 102)){ RequestModel(MODEL_WASHINGTON);
	count++;}
	if (((HasModelLoaded(MODEL_WILLARD)) == false) && (rand == 103 || rand == 104)){ RequestModel(MODEL_WILLARD);
	count++;}
	if (((HasModelLoaded(MODEL_PATRIOT)) == false) && ((rand == 110) || (rand == 143))){ RequestModel(MODEL_PATRIOT);
	count++;}
	
	//Sports cars
	if (((HasModelLoaded(MODEL_BANSHEE)) == false) && (rand == 105)){ RequestModel(MODEL_BANSHEE);
	count++;}
	if (((HasModelLoaded(MODEL_COMET)) == false) && (rand == 106)){ RequestModel(MODEL_COMET);
	count++;}
	if (((HasModelLoaded(MODEL_COQUETTE)) == false) && (rand == 107)){ RequestModel(MODEL_COQUETTE);
	count++;}
	if (((HasModelLoaded(MODEL_DUKES)) == false) && (rand == 108)){ RequestModel(MODEL_DUKES);
	count++;}
	if (((HasModelLoaded(MODEL_FELTZER)) == false) && (rand == 109)){ RequestModel(MODEL_FELTZER);
	count++;}
	if (((HasModelLoaded(MODEL_INFERNUS)) == false) && (rand == 111)){ RequestModel(MODEL_INFERNUS);
	count++;}
	if (((HasModelLoaded(MODEL_SABREGT)) == false) && (rand == 112)){ RequestModel(MODEL_SABREGT);
	count++;}
	if (((HasModelLoaded(MODEL_SENTINEL)) == false) && (rand == 113)){ RequestModel(MODEL_SENTINEL);
	count++;}
	if (((HasModelLoaded(MODEL_STALION)) == false) && (rand == 114)){ RequestModel(MODEL_STALION);
	count++;}
	if (((HasModelLoaded(MODEL_SULTANRS)) == false) && (rand == 116)){ RequestModel(MODEL_SULTANRS);
	count++;}
	if (((HasModelLoaded(MODEL_SUPERGT)) == false) && (rand == 117)){ RequestModel(MODEL_SUPERGT);
	count++;}
	if (((HasModelLoaded(MODEL_TURISMO)) == false) && (rand == 118)){ RequestModel(MODEL_TURISMO);
	count++;
	}
	
	//Exclusive models and less appearing cars
	if (((HasModelLoaded(MODEL_CAVALCADE)) == false) && (rand == 119)){ RequestModel(MODEL_CAVALCADE);
	count++;}
	if (((HasModelLoaded(MODEL_COGNOSCENTI)) == false) && (rand == 120)){ RequestModel(MODEL_COGNOSCENTI);
	count++;}
	if (((HasModelLoaded(MODEL_MRTASTY)) == false) && (rand == 122)){ RequestModel(MODEL_MRTASTY);
	count++;}
	if (((HasModelLoaded(MODEL_ORACLE)) == false) && (rand == 123)){ RequestModel(MODEL_ORACLE);
	count++;}
	if (((HasModelLoaded(MODEL_PMP600)) == false) && (rand == 124)){ RequestModel(MODEL_PMP600);
	count++;}
	if (((HasModelLoaded(MODEL_SCHAFTER)) == false) && (rand == 125)){ RequestModel(MODEL_SCHAFTER);
	count++;}
	if (((HasModelLoaded(MODEL_STRETCH)) == false) && (rand == 126)){ RequestModel(MODEL_STRETCH);
	count++;}
	if (((HasModelLoaded(MODEL_PEYOTE)) == false) && (rand == 127)){ RequestModel(MODEL_PEYOTE);
	count++;}
	
	//Industrial vehicles
	if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 128)){ RequestModel(MODEL_BURRITO);
	count++;}
	if (((HasModelLoaded(MODEL_BURRITO2)) == false) && (rand == 129)){ RequestModel(MODEL_BURRITO2);
	count++;}
	if (((HasModelLoaded(MODEL_EMPEROR2)) == false) && (rand == 130)){ RequestModel(MODEL_EMPEROR2);
	count++;}
	if (((HasModelLoaded(MODEL_VIGERO2)) == false) && (rand == 131)){ RequestModel(MODEL_VIGERO2);
	count++;}
	if (((HasModelLoaded(MODEL_BENSON)) == false) && (rand == 132)){ RequestModel(MODEL_BENSON);
	count++;}
	if (((HasModelLoaded(MODEL_BIFF)) == false) && (rand == 133)){ RequestModel(MODEL_BIFF);
	count++;}
	if (((HasModelLoaded(MODEL_BOXVILLE)) == false) && (rand == 134)){ RequestModel(MODEL_BOXVILLE);
	count++;}
	if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 135)){ RequestModel(MODEL_BURRITO);
	count++;}
	if (((HasModelLoaded(MODEL_BURRITO2)) == false) && (rand == 136)){ RequestModel(MODEL_BURRITO2);
	count++;}
	if (((HasModelLoaded(MODEL_FLATBED)) == false) && (rand == 137)){ RequestModel(MODEL_FLATBED);
	count++;}
	if (((HasModelLoaded(MODEL_PHANTOM)) == false) && (rand == 138)){ RequestModel(MODEL_PHANTOM);
	count++;}
	if (((HasModelLoaded(MODEL_PONY)) == false) && (rand == 139)){ RequestModel(MODEL_PONY);
	count++;}
	if (((HasModelLoaded(MODEL_STEED)) == false) && (rand == 140)){ RequestModel(MODEL_STEED);
	count++;}
	if (((HasModelLoaded(MODEL_STOCKADE)) == false) && (rand == 141)){ RequestModel(MODEL_STOCKADE);
	count++;}
	if (((HasModelLoaded(MODEL_TRASH)) == false) && (rand == 142)){ RequestModel(MODEL_TRASH);
	count++;}
	if (((HasModelLoaded(MODEL_YANKEE)) == false) && (rand == 144)){ RequestModel(MODEL_YANKEE);
	count++;}
	if (((HasModelLoaded(MODEL_PACKER)) == false) && (rand == 102)){ RequestModel(MODEL_PACKER);
	count++;}

	//Motorbikes



	if (((HasModelLoaded(MODEL_BOBBER)) == false) && ((rand < 30) && (bikerand == 3))){ RequestModel(MODEL_BOBBER);
	count++;}
	if (((HasModelLoaded(MODEL_FAGGIO)) == false) && ((rand > 30) && (rand < 60) && (bikerand == 6))){ RequestModel(MODEL_FAGGIO);
	count++;}
	if (((HasModelLoaded(MODEL_HELLFURY)) == false) && ((rand > 60) && (rand < 90) && (bikerand == 9))){ RequestModel(MODEL_HELLFURY);
	count++;}
	if (((HasModelLoaded(MODEL_NRG900)) == false) && ((rand > 90) && (rand < 120) && (bikerand == 12))){ RequestModel(MODEL_NRG900);
	count++;}
	if (((HasModelLoaded(MODEL_SANCHEZ)) == false) && ((rand > 120) && (rand < 150) && (bikerand == 15))){ RequestModel(MODEL_SANCHEZ);
	count++;}
	if (((HasModelLoaded(MODEL_PCJ)) == false) && ((rand > 120) && (rand < 150) && (bikerand == 18))){ RequestModel(MODEL_PCJ);
	count++;}
	if (((HasModelLoaded(MODEL_ZOMBIEB)) == false) && ((rand > 120) && (rand < 150) && (bikerand == 21))){ RequestModel(MODEL_ZOMBIEB);
	count++;}
	MarkModelAsNoLongerNeeded(MODEL_TAXI);
	MarkModelAsNoLongerNeeded(MODEL_TAXI2);
	MarkModelAsNoLongerNeeded(MODEL_CABBY);
}
