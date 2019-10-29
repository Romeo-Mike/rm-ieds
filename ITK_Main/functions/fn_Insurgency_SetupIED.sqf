/*
	Name: ITK_fnc_Insurgency_SetupIED
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Starts the setup process for the passed IED.
	
	Parameters:
		0: OBJECT - Unit placing IED.
		1: STRING - Classname of IED to place. (CfgMagazine class)
	
	Returns:
		Nothing
	
	Example:
		[player, "ITK_IED_Remote_Mag"] call ITK_fnc_Insurgency_SetupIED;
*/
//if ((_this select 1) call ITK_fnc_Insurgency_IsValidIEDMagazine == "") exitWith{false};
_this spawn {
	private ["_IEDclass", "_code", "_unit", "_count"];
	_IEDclass = _this select 1;
	_unit = _this select 0;
	sleep 0.03;
	_code = str(round (random 9999));
	_count = 4 - count (toArray _code);
	while {_count > 0} do
	{
		_code = "0" + _code;
		_count = _count - 1;
	};

	ITK_IED_Setup = getText(ConfigFile >> "CfgMagazines" >> _IEDclass >> "ITK_IED_SetupObject") createVehicleLocal [0,0,-10000];
	ITK_IED_Setup enableSimulation false;
	ITK_IED_Setup setVariable ["ITK_IED", _IEDclass];
	ITK_IED_Setup setVariable ["ITK_IED_Code", _code];

	["ITK_IED_Placement","OnEachFrame", {
		ITK_IED_Setup setPos (positionCameraToWorld [0,0,1]);
	}] call BIS_fnc_addStackedEventHandler;
	if (_unit != (vehicle _unit)) then
	{
		call ITK_fnc_Insurgency_IEDPlace_Cancel;
	};
};
true