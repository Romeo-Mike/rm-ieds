/*
	Name: ITK_fnc_Insurgency_DetonateVest
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Detonates a suicide vest of the passed object.
	
	Parameters:
		OBJECT - Unit that has vest
	
	Returns:
		Nothing
	
	Example:
		player call ITK_fnc_Insurgency_DetonateVest;
*/
private "_position";
_position = getPosATL _this;
_position set [2, (_position select 2) + 0.2];

createVehicle ["Bo_Mk82", _position, [], 0, "NONE"];