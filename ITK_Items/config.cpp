class CfgPatches
{
	class ITK_Items
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Weapons_F_Explosives"};
		author[] = {"Garth 'LH' de Wet", "Burga"};
	};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"

class CfgMineTriggers
{
	class RangeTrigger;
	class ITK_RangeTriggerLong:RangeTrigger
	{
		mineDelay = 2;
	};
	class ITK_RangeTriggerShort:RangeTrigger
	{
		mineDelay = 0.5;
	};
	
	class WireTrigger;
	class ITK_WireTrigger_Short:WireTrigger
	{
		mineDelay = 0.5;
	};
	class ITK_WireTrigger_Long:WireTrigger
	{
		mineDelay = 1.5;
	};
};