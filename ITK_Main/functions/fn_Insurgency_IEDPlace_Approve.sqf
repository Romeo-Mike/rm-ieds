/*
	Name: ITK_fnc_Insurgency_IEDPlace_Approve
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		spawn ITK_fnc_Insurgency_IEDPlace_Approve;
*/
["ITK_IED_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
if (ITK_IED_Setup getVariable ["ITK_IED", ""] != "") then
{
	private ["_pos", "_oldPos", "_limiter"];
	_pos = -5;
	_oldPos = -1;
	_limiter = 0;
	ITK_IED_Setup enableSimulation true;
	while {_pos != _oldPos AND _limiter < 10} do
	{
		sleep 0.1;
		_oldPos = _pos;
		_pos = (GetPosATL ITK_IED_Setup) select 2;
		_limiter = _limiter + 0.1;
	};
	// Position, AMMO Class, code
	[GetPosATL ITK_IED_Setup, ITK_IED_Setup getVariable "ITK_IED", ITK_IED_Setup getVariable "ITK_IED_Code", 180 + (getDir ITK_IED_Setup)] call ITK_fnc_Insurgency_PlaceIED;
	call ITK_fnc_Insurgency_RemoveIED_Components;
	deleteVehicle ITK_IED_Setup;
};
ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
ITK_IED_Setup = objNull;