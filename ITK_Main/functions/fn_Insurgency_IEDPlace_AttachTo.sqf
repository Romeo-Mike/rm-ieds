/*
	Name: ITK_fnc_Insurgency_IEDPlace_AttachTo
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		OBJECT: Object to attach to.
	
	Returns:
		Nothing
	
	Example:
		cursorTarget call ITK_fnc_Insurgency_IEDPlace_AttachTo;
*/
["ITK_IED_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
if(ITK_IED_Setup getVariable ["ITK_IED", ""] != "") then
{
	private "_IED";
	_IED = [getPosATL ITK_IED_Setup, ITK_IED_Setup getVariable "ITK_IED", ITK_IED_Setup getVariable "ITK_IED_Code", 180 + (getDir ITK_IED_Setup)] call ITK_fnc_Insurgency_PlaceIED;
	call ITK_fnc_Insurgency_RemoveIED_Components;
	deleteVehicle ITK_IED_Setup;
	ITK_Null = [_IED,_this] spawn {
		sleep 0.1;
		(_this select 0) attachTo [(_this select 1)];
	};
};
ITK_IED_Setup = objNull;
ITK_IED_Creation = [["",""],["",""],["",""],["",""]];