/*
	Name: ITK_fnc_Insurgency_RemoveCodeFromSpeedDial
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Removes an IED code from the speed dial of the player.
	
	Parameters:
		STRING - Name of speed dial
	
	Returns:
		Nothing
	
	Example:
		"IED 1" call ITK_fnc_Insurgency_RemoveCodeFromSpeedDial;
*/
if (isNil "ITK_IED_SpeedDial") exitWith{};
{
	if ((_x select 0) == _this) exitWith
	{
		ITK_IED_SpeedDial set [_foreachIndex, "x"];
		ITK_IED_SpeedDial = ITK_IED_SpeedDial - ["x"];
	};
} foreach ITK_IED_SpeedDial;