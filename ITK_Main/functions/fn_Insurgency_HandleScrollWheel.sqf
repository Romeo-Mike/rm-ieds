/*
 	Name: ITK_fnc_Insurgency_HandleScrollWheel
 	
 	Author(s):
		L-H

 	Description:
		Handles rotating of IEDs
	
	Parameters:
		Number: Scroll amount
 	
 	Returns:
		Boolean: Handled or not.
 	
 	Example:
		1.2 call ITK_fnc_Insurgency_HandleScrollWheel;
*/
private ["_obj"];
if (isNull(ITK_IED_Setup)) exitWith {false};
if !(ITK_IED_ShiftDown) exitWith {false};
//_obj = attachedTo ITK_IED_Setup;
//detach ITK_IED_Setup;
ITK_IED_Setup setDir ((getDir ITK_IED_Setup) + (_this*5));
//ITK_IED_Setup attachTo [_obj];

true