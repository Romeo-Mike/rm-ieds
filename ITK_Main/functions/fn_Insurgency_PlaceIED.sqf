/*
	Name: ITK_fnc_Insurgency_PlaceIED
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		0: POSITION - Position to place IED
		1: STRING - Ammo class
		2: STRING - Code for remote IEDs
		3: NUMBER - Rotation
	
	Returns:
		OBJECT: Placed IED
	
	Example:
		// cellphone IED
		_IED = [player modelToWorld [0,0.5, 0.1], "ITK_IED_Cellphone_Short_Mortar_12VBattery", "13112", 134] call ITK_fnc_Insurgency_PlaceIED;
		// Clacker IED
		_IED = [player modelToWorld [0,0.5, 0.1], "ITK_IED_Clacker_Short_Mortar_12VBattery", "", 45] call ITK_fnc_Insurgency_PlaceIED;
*/
#include "\ITK_Items\IEDTypes.hpp"
private ["_pos", "_ammo", "_IED", "_code"];
_pos = _this select 0;
_ammo = getText(configFile >> "CfgMagazines" >> (_this select 1) >> "ammo");
_code = _this select 2;

_IED = createVehicle [_ammo, _pos, [], 0, "NONE"];
_IED setDir (_this select 3);
_IED setPosATL _pos;

if (getText(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_IED_OnCreate") != "") then
{
	_IED spawn compile (getText(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_IED_OnCreate"));
};

private "_deadman";
_deadman = player getVariable ["ITK_Deadman",[]];
if (count _deadman > 0) then
{
	_deadman call ITK_fnc_Insurgency_DetonateIED;
	player setVariable ["ITK_Deadman",[],true];
};

switch (getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_Type")) do
{
	case TYPE_Cellphone:
	{
		ITK_IEDs set [count ITK_IEDs, [_IED,_code,getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_FuseTime"),getNumber (configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_IED_MaxDistance")]];
		publicVariable "ITK_IEDs";
		ITK_IED_YourCount = ITK_IED_YourCount + 1;
		[format ["IED %1", ITK_IED_YourCount],_code] call ITK_fnc_Insurgency_AddCodeToSpeedDial;
		player sideChat format [localize "STR_ITK_INSURGENCY_IED_DetonateCode", _code];
	};
	case TYPE_Clacker:
	{
		private "_clacker";
		_clacker = player getVariable ["ITK_Clacker", []];
		_clacker set [count _clacker, [_IED, getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_FuseTime"),getNumber (configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_IED_MaxDistance")]];
		player setVariable ["ITK_Clacker", _clacker, true];
	};
	case TYPE_DeadmanTrigger:
	{
		player setVariable ["ITK_Deadman", [_IED,getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_FuseTime"),getNumber (configFile >> "CfgMagazines" >> (_this select 1) >> "ITK_IED_MaxDistance")], true];
	};
	default
	{
	};
};

_IED