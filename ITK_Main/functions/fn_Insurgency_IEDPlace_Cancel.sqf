/*
	Name: ITK_fnc_Insurgency_IEDPlace_Cancel
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call ITK_fnc_Insurgency_IEDPlace_Cancel;
*/
["ITK_IED_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
if (ITK_IED_Setup getVariable ["ITK_IED", ""] != "") then
{
	call ITK_fnc_Insurgency_RemoveIED_Components;
	if (player canAdd (ITK_IED_Setup getVariable "ITK_IED")) then
	{
		player addMagazine (ITK_IED_Setup getVariable "ITK_IED");
	}
	else
	{
		private ["_holder", "_pos"];
		_pos = player modelToWorld [0,0.25,0];
		_holder = createVehicle ["WeaponHolder_Single_limited_magazine_F", _pos, [],0, "NONE"];
		_holder setPosATL _pos;
		_holder addMagazineCargoGlobal [(ITK_IED_Setup getVariable "ITK_IED"),1];
	};
	deleteVehicle ITK_IED_Setup;
};
ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
ITK_IED_Setup = objNull;