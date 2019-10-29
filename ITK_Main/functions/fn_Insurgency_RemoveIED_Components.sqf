/*
	Name: ITK_fnc_Insurgency_RemoveIED_Components
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call ITK_fnc_Insurgency_RemoveIED_Components;
*/
if (((ITK_IED_Creation select 0) select 0) == "") exitWith
{
	player removeMagazine (ITK_IED_Setup getVariable "ITK_IED");
};
{
	if (_foreachIndex != 0) then
	{
		player removeItem (_x select 1);
	}
	else
	{
		if ((_x select 0) == "PressurePlate" or {(_x select 0) == "Wire"}) then
		{
			player removeItem (_x select 1);
		};
	};
} foreach ITK_IED_Creation;