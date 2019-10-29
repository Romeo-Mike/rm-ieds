/*
	Name: ITK_fnc_Insurgency_Initialise
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises the Insurgency mod.
	
	Parameters:
		None
	
	Returns:
		None
	
	Example:
		None
*/
if (isServer) then
{
	if (isNil "ITK_IEDs") then
	{
		ITK_IEDs = [];
		publicVariable "ITK_IEDs";
	};
	if (isNil "ITK_Jammers") then
	{
		ITK_Jammers = [];
		publicVariable "ITK_Jammers";
	};
};
if !(hasInterface) exitWith {};
ITK_IED_YourCount = 0;
ITK_IED_Setup = objNull;
ITK_IED_CurrentSpeedDial=-1;
ITK_IED_SpeedDial = [];
ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
ITK_IED_ShiftDown = false;
ITK_null=[] spawn {
	waitUntil {sleep 0.1;player == player };
	ITK_Insurgency_InventoryHandle = [] spawn {
		waitUntil {sleep 0.5;!isNull(findDisplay 46)};
		(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call ITK_fnc_Insurgency_HandleScrollWheel"];
		(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {ITK_IED_ShiftDown = true;};"];
		(findDisplay 46) displayAddEventHandler ["KeyUp", "ITK_IED_ShiftDown = false;"];
		while {true} do
		{
			waitUntil {sleep 0.1;!(isNull (findDisplay 602))};
			((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
			((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
			((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
			waitUntil {sleep 0.5;isNull (findDisplay 602)};
		};
	};

	player AddAction [localize "STR_ITK_INSURGENCY_SuicideVest_Detonate", "player call ITK_fnc_Insurgency_DetonateVest;", nil, -25, false, true, "", "(_this == _target) AND {getNumber(ConfigFile >> 'CfgWeapons' >> (vest _target) >> 'ITK_SuicideVest') == 1}"];
	
	player addAction [localize "STR_ITK_INSURGENCY_IED_AttachTo", "cursorTarget call ITK_fnc_Insurgency_IEDPlace_AttachTo;", nil, 22, false, true, "","!isNull(ITK_IED_Setup) AND {cursorTarget isKindOf 'Car'} AND {(cursorTarget distance ITK_IED_Setup) < 2.5}"];
	player addAction [localize "STR_ITK_INSURGENCY_IED_Place", "[] spawn ITK_fnc_Insurgency_IEDPlace_Approve;", nil, 21, false, true, "","!isNull(ITK_IED_Setup)"];
	player addAction [localize "STR_ITK_INSURGENCY_IED_Cancel", "call ITK_fnc_Insurgency_IEDPlace_Cancel;", nil, 20, false, true, "","!isNull(ITK_IED_Setup)"];
	
	player addAction [localize "STR_ITK_INSURGENCY_IED_deadman_Release", "[player,(player getVariable 'ITK_Deadman'), true, true] call ITK_fnc_Insurgency_DetonateIED;player setVariable ['ITK_Deadman', [],true];", nil, 20, false, true, "","player call ITK_fnc_Insurgency_IED_DeadManCheck"];
	
	player addAction [localize "STR_A3_IEDJammer_TurnOn", {(unitBackpack player) setVariable ["ITK_JammerEnabled", true, true];}, nil, -15, false, true, "","(_this == _target) and {((isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'ITK_JammerRange') > 0})) and !((unitBackpack player) getVariable [""ITK_JammerEnabled"", false])}"];
	player addAction [localize "STR_A3_IEDJammer_TurnOff", {(unitBackpack player) setVariable ["ITK_JammerEnabled", false, true];}, nil, -15, false, true, "","(_this == _target) and {((isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'ITK_JammerRange') > 0})) and ((unitBackpack player) getVariable [""ITK_JammerEnabled"", false])}"];

	player SetVariable ["ITK_Clacker", [], true];
	player addEventHandler ["Killed", {
		if ((_this select 0) call ITK_fnc_Insurgency_IED_DeadManCheck) then
		{
			[(_this select 0),((_this select 0) getVariable "ITK_Deadman"), true, true] call ITK_fnc_Insurgency_DetonateIED;
		};
		ITK_IED_Setup = objNull;
		ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
	}];
	player addEventHandler ["Respawn", {
		ITK_IED_YourCount = 0;
		ITK_IED_CurrentSpeedDial=-1;
		ITK_IED_SpeedDial = [];
		player setVariable ["ITK_Clacker", [], true];
	}];

	player addEventHandler ["Take", {
		if ((_this select 2) == "ITK_IED_ClackerTriggerComponent") then
		{
			private ["_clacker1"];
			_clacker1 = (_this select 1) getVariable ["ITK_Clacker", []];
			(_this select 0) SetVariable ["ITK_Clacker", ((_this select 0) getVariable ["ITK_Clacker", []]) + _clacker1, true];
			if !("ITK_IED_ClackerTriggerComponent" in items (_this select 1)) then
			{
				(_this select 1) setVariable ["ITK_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "ITK_JammerRange") > 0}) then
		{
			[(_this select 0),unitBackpack (_this select 0)] call ITK_fnc_Insurgency_JammerInit;
		};
	}];
	player addEventHandler ["Put", {
		if ((_this select 2) == "ITK_IED_ClackerTriggerComponent") then
		{
			private ["_clacker1"];
			_clacker1 = (_this select 0) getVariable ["ITK_Clacker", []];
			(_this select 1) SetVariable ["ITK_Clacker", ((_this select 1) getVariable ["ITK_Clacker", []]) + _clacker1, true];
			if !("ITK_IED_ClackerTriggerComponent" in items (_this select 0)) then
			{
				(_this select 0) setVariable ["ITK_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "ITK_JammerRange") > 0}) then
		{
			{
				if ((_x select 0) == (_this select 0)) exitWith
				{
					_x set [0, (_this select 1)];
				};
			} count ITK_Jammers;
			publicVariable "ITK_Jammers";
		};
	}];
};