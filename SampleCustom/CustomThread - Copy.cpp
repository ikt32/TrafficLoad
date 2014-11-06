#include "CustomThread.h"
#include "Scripting.h"
#include "../ScriptHook/Log.h"

#include <windows.h>

// Pull in all our scripting functions/types
using namespace Scripting;

CustomThread::CustomThread()
{
    // Give your own name here!
	SetName("TrafficLoad");
}

void CustomThread::RunTick()
{
	Wait(1000);
	u32 rand;
	GenerateRandomIntInRange(1, 144, &rand);

	SetPedDensityMultiplier(2.0);
	SetRandomCarDensityMultiplier(3.5);

	Player PlayerIndex = ConvertIntToPlayerIndex(GetPlayerId());
	Ped PlayerChar;
    GetPlayerChar(PlayerIndex, &PlayerChar);
	GetCharCoordinates(PlayerChar, &x, &y, &z);
	b8 caek = IsCharInArea2D(PlayerChar, 2165.92f, 912.35f, 2924.75f, -145.64f, false);
	b8 koek = IsWantedLevelGreater(PlayerIndex, 1);

	PrintWithNumberNow("NUMBER",count,999,1);
	//DisplayTextWithNumber(0.8, 0.8, "NUMBER", count);

	if ((koek != true) && (caek == true))
	{
		if (rand > 30)
		{
			RequestModel(MODEL_FEROCI2);
			count++;
		}
		if ((rand < 77) && (rand > 30))
		{
			RequestModel(MODEL_BUS);
			count++;
		}
		if ((rand > 30) && (rand <110))
		{
			RequestModel(MODEL_PERENNIAL2);
			count++;
		}
		if ((rand < 30) || (rand > 80))
		{
			RequestModel(MODEL_CABBY);
			count++;
		}
	}
	else
	{
		MarkModelAsNoLongerNeeded(MODEL_PERENNIAL2);
		MarkModelAsNoLongerNeeded(MODEL_FEROCI2);
	}

	if ((koek != true) && (caek != true))
	{
		
		//Service cars, always loaded because they are badass and you know it.
		if (HasModelLoaded(MODEL_BUS) == false)
		{
			RequestModel(MODEL_BUS);
		}
		if (HasModelLoaded(MODEL_TAXI) == false)
		{
			RequestModel(MODEL_TAXI);
		}
		if (HasModelLoaded(MODEL_TAXI2) == false)
		{
			RequestModel(MODEL_TAXI2);
		}
		if (HasModelLoaded(MODEL_CABBY) == false)
		{
			RequestModel(MODEL_CABBY);
		}


		//Let's delete some (all) cars!
		if (count > 27)
		{
			PrintStringWithLiteralStringNow("STRING", "Removed", 1000, true);
			if ((HasModelLoaded(MODEL_ADMIRAL)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_ADMIRAL);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BLISTA)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BLISTA);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BOBCAT)) == true) 
			{
				MarkModelAsNoLongerNeeded(MODEL_BOBCAT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BUCCANEER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BUCCANEER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BURRITO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BURRITO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_CAVALCADE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_CAVALCADE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_CHAVOS)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_CHAVOS);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_DF8)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_DF8);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_DILETTANTE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_DILETTANTE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_E109)) == true) 
			{
				MarkModelAsNoLongerNeeded(MODEL_E109);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_EMPEROR)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_EMPEROR);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_ESPERANTO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_ESPERANTO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FACTION)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FACTION);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FEROCI)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FEROCI);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FORTUNE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FORTUNE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FUTO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FUTO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FXT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FXT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_HABANERO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_HABANERO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_HAKUMAI)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_HAKUMAI);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_HUNTLEY)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_HUNTLEY);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_INGOT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_INGOT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_INTRUDER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_INTRUDER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_LANDSTALKER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_LANDSTALKER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_LOKUS)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_LOKUS);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MANANA)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MANANA);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PEYOTE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PEYOTE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MARBELLA)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MARBELLA);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MERIT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MERIT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MINIVAN)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MINIVAN);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MOONBEAM)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MOONBEAM);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PERENNIAL)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PERENNIAL);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PINNACLE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PINNACLE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PREMIER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PREMIER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PRES)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PRES);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PRIMO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PRIMO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_REBLA)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_REBLA);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_RUINER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_RUINER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SABRE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SABRE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SOLAIR)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SOLAIR);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SPEEDO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SPEEDO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_STRATUM)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_STRATUM);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SULTAN)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SULTAN);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_URANUS)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_URANUS);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_VIGERO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_VIGERO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_VINCENT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_VINCENT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_VIRGO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_VIRGO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_WASHINGTON)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_WASHINGTON);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_WILLARD)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_WILLARD);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BANSHEE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BANSHEE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_COMET)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_COMET);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_COQUETTE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_COQUETTE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_DUKES)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_DUKES);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FELTZER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FELTZER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_INFERNUS)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_INFERNUS);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SABREGT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SABREGT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SENTINEL)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SENTINEL);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_STALION)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_STALION);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SULTANRS)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SULTANRS);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SUPERGT)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SUPERGT);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_TURISMO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_TURISMO);
				count--;
				
			}

			if ((HasModelLoaded(MODEL_CAVALCADE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_CAVALCADE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_COGNOSCENTI)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_COGNOSCENTI);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_MRTASTY)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_MRTASTY);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_ORACLE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_ORACLE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PMP600)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PMP600);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_SCHAFTER)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_SCHAFTER);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_STRETCH)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_STRETCH);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_PEYOTE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PEYOTE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BURRITO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BURRITO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BURRITO2)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BURRITO2);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_EMPEROR2)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_EMPEROR2);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_VIGERO2)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_VIGERO2);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BENSON)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BENSON);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BIFF)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BIFF);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BOXVILLE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BOXVILLE);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BURRITO)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BURRITO);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_BURRITO2)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_BURRITO2);
				count--;
				
			}
			if ((HasModelLoaded(MODEL_FLATBED)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_FLATBED);
				count--;				
			}
			if ((HasModelLoaded(MODEL_PHANTOM)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PHANTOM);
				count--;				
			}
			if ((HasModelLoaded(MODEL_PONY)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_PONY);
				count--;				
			}
			if ((HasModelLoaded(MODEL_STEED)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_STEED);
				count--;				
			}
			if ((HasModelLoaded(MODEL_STOCKADE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_STOCKADE);
				count--;
			}
			if ((HasModelLoaded(MODEL_TRASH)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_TRASH);
				count--;
			}
			if ((HasModelLoaded(MODEL_YANKEE)) == true)
			{
				MarkModelAsNoLongerNeeded(MODEL_YANKEE);
				count--;
			}
		}

		// And now let's load some cars!
		if (count < 30)
		{
			//Normal cars
			if (((HasModelLoaded(MODEL_ADMIRAL)) == false) && (rand == 1 || rand == 2))
			{
				RequestModel(MODEL_ADMIRAL);
				count++;
			}
			if (((HasModelLoaded(MODEL_BLISTA)) == false) && (rand == 3 || rand == 4))
			{
				RequestModel(MODEL_BLISTA);
				count++;
			}
			if (((HasModelLoaded(MODEL_BOBCAT)) == false)  && (rand == 5 || rand == 6))
			{
				RequestModel(MODEL_BOBCAT);
				count++;
			}
			if (((HasModelLoaded(MODEL_BUCCANEER)) == false) && (rand == 7 || rand == 8))
			{
				RequestModel(MODEL_BUCCANEER);
				count++;
			}
			if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 9 || rand == 10))
			{
				RequestModel(MODEL_BURRITO);
				count++;
			}
			if (((HasModelLoaded(MODEL_CAVALCADE)) == false) && (rand == 11 || rand == 12))
			{
				RequestModel(MODEL_CAVALCADE);
				count++;
			}
			if (((HasModelLoaded(MODEL_CHAVOS)) == false) && (rand == 13 || rand == 14))
			{
				RequestModel(MODEL_CHAVOS);
				count++;
			}
			if (((HasModelLoaded(MODEL_DF8)) == false) && (rand == 15 || rand == 16))
			{
				RequestModel(MODEL_DF8);
				count++;
			}
			if (((HasModelLoaded(MODEL_DILETTANTE)) == false) && (rand == 17 || rand == 18))
			{
				RequestModel(MODEL_DILETTANTE);
				count++;
			}
			if (((HasModelLoaded(MODEL_E109)) == false)  && (rand == 21 || rand == 22))
			{
				RequestModel(MODEL_E109);
				count++;
			}
			if (((HasModelLoaded(MODEL_EMPEROR)) == false) && (rand == 23 || rand == 24))
			{
				RequestModel(MODEL_EMPEROR);
				count++;
			}
			if (((HasModelLoaded(MODEL_ESPERANTO)) == false) && (rand == 25 || rand == 26))
			{
				RequestModel(MODEL_ESPERANTO);
				count++;
			}
			if (((HasModelLoaded(MODEL_FACTION)) == false) && (rand == 27 || rand == 28))
			{
				RequestModel(MODEL_FACTION);
				count++;
			}
			if (((HasModelLoaded(MODEL_FEROCI)) == false) && (rand == 29 || rand == 30))
			{
				RequestModel(MODEL_FEROCI);
				count++;
			}
			if (((HasModelLoaded(MODEL_FORTUNE)) == false) && (rand == 31 || rand == 32))
			{
				RequestModel(MODEL_FORTUNE);
				count++;
			}
			if (((HasModelLoaded(MODEL_FUTO)) == false) && (rand == 33 || rand == 34))
			{
				RequestModel(MODEL_FUTO);
				count++;
			}
			if (((HasModelLoaded(MODEL_FXT)) == false) && (rand == 35 || rand == 36))
			{
				RequestModel(MODEL_FXT);
				count++;
			}
			if (((HasModelLoaded(MODEL_HABANERO)) == false) && (rand == 37 || rand == 38))
			{
				RequestModel(MODEL_HABANERO);
				count++;
			}
			if (((HasModelLoaded(MODEL_HAKUMAI)) == false) && (rand == 39 || rand == 40))
			{
				RequestModel(MODEL_HAKUMAI);
				count++;
			}
			if (((HasModelLoaded(MODEL_HUNTLEY)) == false) && (rand == 41 || rand == 42))
			{
				RequestModel(MODEL_HUNTLEY);
				count++;
			}
			if (((HasModelLoaded(MODEL_INGOT)) == false) && (rand == 43 || rand == 44))
			{
				RequestModel(MODEL_INGOT);
				count++;
			}
			if (((HasModelLoaded(MODEL_INTRUDER)) == false) && (rand == 45 || rand == 46))
			{
				RequestModel(MODEL_INTRUDER);
				count++;
			}
			if (((HasModelLoaded(MODEL_LANDSTALKER)) == false) && (rand == 47 || rand == 48))
			{
				RequestModel(MODEL_LANDSTALKER);
				count++;
			}
			if (((HasModelLoaded(MODEL_LOKUS)) == false) && (rand == 49 || rand == 50))
			{
				RequestModel(MODEL_LOKUS);
				count++;
			}
			if (((HasModelLoaded(MODEL_MANANA)) == false) && (rand == 51 || rand == 52))
			{
				RequestModel(MODEL_MANANA);
				count++;
			}
			if (((HasModelLoaded(MODEL_PEYOTE)) == false) && (rand == 53 || rand == 54))
			{
				RequestModel(MODEL_PEYOTE);
				count++;
			}
			if (((HasModelLoaded(MODEL_MARBELLA)) == false) && (rand ==55 || rand == 56))
			{
				RequestModel(MODEL_MARBELLA);
				count++;
			}
			if (((HasModelLoaded(MODEL_MERIT)) == false) && (rand == 57 || rand == 58))
			{
				RequestModel(MODEL_MERIT);
				count++;
			}
			if (((HasModelLoaded(MODEL_MINIVAN)) == false) && (rand == 59 || rand == 60))
			{
				RequestModel(MODEL_MINIVAN);
				count++;
			}
			if (((HasModelLoaded(MODEL_MOONBEAM)) == false) && (rand == 61 || rand == 62))
			{
				RequestModel(MODEL_MOONBEAM);
				count++;
			}
			if (((HasModelLoaded(MODEL_PERENNIAL)) == false) && (rand == 65 || rand == 66))
			{
				RequestModel(MODEL_PERENNIAL);
				count++;
			}
			if (((HasModelLoaded(MODEL_PINNACLE)) == false) && (rand == 67 || rand == 68))
			{
				RequestModel(MODEL_PINNACLE);
				count++;
			}
			if (((HasModelLoaded(MODEL_PREMIER)) == false) && (rand == 69 || rand == 70))
			{
				RequestModel(MODEL_PREMIER);
				count++;
			}
			if (((HasModelLoaded(MODEL_PRES)) == false) && (rand == 71 || rand == 72))
			{
				RequestModel(MODEL_PRES);
				count++;
			}
			if (((HasModelLoaded(MODEL_PRIMO)) == false) && (rand == 73 || rand == 74))
			{
				RequestModel(MODEL_PRIMO);
				count++;
			}
			if (((HasModelLoaded(MODEL_REBLA)) == false) && (rand == 75 || rand == 76))
			{
				RequestModel(MODEL_REBLA);
				count++;
			}
			if (((HasModelLoaded(MODEL_RUINER)) == false) && (rand == 77 || rand == 78))
			{
				RequestModel(MODEL_RUINER);
				count++;
			}
			if (((HasModelLoaded(MODEL_SABRE)) == false) && (rand == 79 || rand == 80))
			{
				RequestModel(MODEL_SABRE);
				count++;
			}
			if (((HasModelLoaded(MODEL_SOLAIR)) == false) && (rand == 85 || rand == 86))
			{
				RequestModel(MODEL_SOLAIR);
				count++;
			}
			if (((HasModelLoaded(MODEL_SPEEDO)) == false) && (rand == 87 || rand == 88))
			{
				RequestModel(MODEL_SPEEDO);
				count++;
			}
			if (((HasModelLoaded(MODEL_STRATUM)) == false) && (rand == 89 || rand == 90))
			{
				RequestModel(MODEL_STRATUM);
				count++;
			}
			if (((HasModelLoaded(MODEL_SULTAN)) == false) && (rand == 91 || rand == 92))
			{
				RequestModel(MODEL_SULTAN);
				count++;
			}
			if (((HasModelLoaded(MODEL_URANUS)) == false) && (rand == 93 || rand == 94))
			{
				RequestModel(MODEL_URANUS);
				count++;
			}
			if (((HasModelLoaded(MODEL_VIGERO)) == false) && (rand == 95 || rand == 96))
			{
				RequestModel(MODEL_VIGERO);
				count++;
			}
			if (((HasModelLoaded(MODEL_VINCENT)) == false) && (rand == 97 || rand == 98))
			{
				RequestModel(MODEL_VINCENT);
				count++;
			}
			if (((HasModelLoaded(MODEL_VIRGO)) == false) && (rand == 99 || rand == 100))
			{
				RequestModel(MODEL_VIRGO);
				count++;
			}
			if (((HasModelLoaded(MODEL_WASHINGTON)) == false) && (rand == 101 || rand == 102))
			{
				RequestModel(MODEL_WASHINGTON);
				count++;
			}
			if (((HasModelLoaded(MODEL_WILLARD)) == false) && (rand == 103 || rand == 104))
			{
				RequestModel(MODEL_WILLARD);
				count++;
			}

			//AWESOME CARS
			if (((HasModelLoaded(MODEL_BANSHEE)) == false) && (rand == 105))
			{
				RequestModel(MODEL_BANSHEE);
				count++;
			}
			if (((HasModelLoaded(MODEL_COMET)) == false) && (rand == 106))
			{
				RequestModel(MODEL_COMET);
				count++;
			}
			if (((HasModelLoaded(MODEL_COQUETTE)) == false) && (rand == 107))
			{
				RequestModel(MODEL_COQUETTE);
				count++;
			}
			if (((HasModelLoaded(MODEL_DUKES)) == false) && (rand == 108))
			{
				RequestModel(MODEL_DUKES);
				count++;
			}
			if (((HasModelLoaded(MODEL_FELTZER)) == false) && (rand == 109))
			{
				RequestModel(MODEL_FELTZER);
				count++;
			}
			if (((HasModelLoaded(MODEL_INFERNUS)) == false) && (rand == 111))
			{
				RequestModel(MODEL_INFERNUS);
				count++;
			}
			if (((HasModelLoaded(MODEL_SABREGT)) == false) && (rand == 112))
			{
				RequestModel(MODEL_SABREGT);
				count++;
			}
			if (((HasModelLoaded(MODEL_SENTINEL)) == false) && (rand == 113))
			{
				RequestModel(MODEL_SENTINEL);
				count++;
			}
			if (((HasModelLoaded(MODEL_STALION)) == false) && (rand == 114))
			{
				RequestModel(MODEL_STALION);
				count++;
			}
			if (((HasModelLoaded(MODEL_SULTANRS)) == false) && (rand == 116))
			{
				RequestModel(MODEL_SULTANRS);
				count++;
			}
			if (((HasModelLoaded(MODEL_SUPERGT)) == false) && (rand == 117))
			{
				RequestModel(MODEL_SUPERGT);
				count++;
			}
			if (((HasModelLoaded(MODEL_TURISMO)) == false) && (rand == 118))
			{
				RequestModel(MODEL_TURISMO);
				count++;
			}

			//X-CLUSIVZ
			if (((HasModelLoaded(MODEL_CAVALCADE)) == false) && (rand == 119))
			{
				RequestModel(MODEL_CAVALCADE);
				count++;
			}
			if (((HasModelLoaded(MODEL_COGNOSCENTI)) == false) && (rand == 120))
			{
				RequestModel(MODEL_COGNOSCENTI);
				count++;
			}
			if (((HasModelLoaded(MODEL_MRTASTY)) == false) && (rand == 122))
			{
				RequestModel(MODEL_MRTASTY);
				count++;
			}
			if (((HasModelLoaded(MODEL_ORACLE)) == false) && (rand == 123))
			{
				RequestModel(MODEL_ORACLE);
				count++;
			}
			if (((HasModelLoaded(MODEL_PMP600)) == false) && (rand == 124))
			{
				RequestModel(MODEL_PMP600);
				count++;
			}
			if (((HasModelLoaded(MODEL_SCHAFTER)) == false) && (rand == 125))
			{
				RequestModel(MODEL_SCHAFTER);
				count++;
			}
			if (((HasModelLoaded(MODEL_STRETCH)) == false) && (rand == 126))
			{
				RequestModel(MODEL_STRETCH);
				count++;
			}
			if (((HasModelLoaded(MODEL_PEYOTE)) == false) && (rand == 127))
			{
				RequestModel(MODEL_PEYOTE);
				count++;
			}

			//Aardappels
			if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 128))
			{
				RequestModel(MODEL_BURRITO);
				count++;
			}
			if (((HasModelLoaded(MODEL_BURRITO2)) == false) && (rand == 129))
			{
				RequestModel(MODEL_BURRITO2);
				count++;
			}
			if (((HasModelLoaded(MODEL_EMPEROR2)) == false) && (rand == 130))
			{
				RequestModel(MODEL_EMPEROR2);
				count++;
			}
			if (((HasModelLoaded(MODEL_VIGERO2)) == false) && (rand == 131))
			{
				RequestModel(MODEL_VIGERO2);
				count++;
			}
			if (((HasModelLoaded(MODEL_BENSON)) == false) && (rand == 132))
			{
				RequestModel(MODEL_BENSON);
				count++;
			}
			if (((HasModelLoaded(MODEL_BIFF)) == false) && (rand == 133))
			{
				RequestModel(MODEL_BIFF);
				count++;
			}
			if (((HasModelLoaded(MODEL_BOXVILLE)) == false) && (rand == 134))
			{
				RequestModel(MODEL_BOXVILLE);
				count++;
			}
			if (((HasModelLoaded(MODEL_BURRITO)) == false) && (rand == 135))
			{
				RequestModel(MODEL_BURRITO);
				count++;
			}
			if (((HasModelLoaded(MODEL_BURRITO2)) == false) && (rand == 136))
			{
				RequestModel(MODEL_BURRITO2);
				count++;
			}
			if (((HasModelLoaded(MODEL_FLATBED)) == false) && (rand == 137))
			{
				RequestModel(MODEL_FLATBED);
				count++;
			}
			if (((HasModelLoaded(MODEL_PHANTOM)) == false) && (rand == 138))
			{
				RequestModel(MODEL_PHANTOM);
				count++;
			}
			if (((HasModelLoaded(MODEL_PONY)) == false) && (rand == 139))
			{
				RequestModel(MODEL_PONY);
				count++;
			}
			if (((HasModelLoaded(MODEL_STEED)) == false) && (rand == 140))
			{
				RequestModel(MODEL_STEED);
				count++;
			}
			if (((HasModelLoaded(MODEL_STOCKADE)) == false) && (rand == 141))
			{
				RequestModel(MODEL_STOCKADE);
				count++;
			}
			if (((HasModelLoaded(MODEL_TRASH)) == false) && (rand == 142))
			{
				RequestModel(MODEL_TRASH);
				count++;
			}
			if (((HasModelLoaded(MODEL_YANKEE)) == false) && (rand == 144))
			{
				RequestModel(MODEL_YANKEE);
				count++;
			}
		}



	}
}
