/*
	Name: ITK_fnc_Insurgency_JammerInit
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		0:OBJECT - unit carrying
		1:OBJECT - Jammer
	
	Returns:
		Nothing
	
	Example:
		[player,JammerObject] call ITK_fnc_Insurgency_JammerInit;
*/
if (isClass (configFile >> "CfgVehicles" >> (typeof (_this select 1))) and {getNumber(configFile >> "CfgVehicles" >> (typeof (_this select 1)) >> "ITK_JammerRange") > 0}) then
{
	private ["_found"];
	_found = false;
	{
		if ((_x select 2) == (_this select 1)) exitWith
		{
			_x set [0, (_this select 0)];
			_found = true;
		};
	} count ITK_Jammers;
	if !(_found) then
	{
		ITK_Jammers set [count ITK_Jammers, [(_this select 0), getNumber(configFile >> "CfgVehicles" >> (typeof (_this select 1)) >> "ITK_JammerRange"),(_this select 1)]];
	};
	publicVariable "ITK_Jammers";
	private "_check";
	_check = (_this select 1) getVariable "ITK_JammerCharge";
	if (isNil "_check") then {
		(_this select 1) setVariable ["ITK_JammerCharge", getNumber(configFile >> "CfgVehicles" >> (typeof (_this select 1)) >> "ITK_JammerMaxCharge"), true];
	};
	_check = (_this select 1) getVariable "ITK_JammerEnabled";
	if (isNil "_check") then {
		(_this select 1) setVariable ["ITK_JammerEnabled", false, true];
	};
};