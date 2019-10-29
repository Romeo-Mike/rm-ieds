/*
	Name: ITK_fnc_Insurgency_SetIED_ComponentDetails
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		ARRAY
	
	Returns:
		Nothing
	
	Example:
		_this call ITK_fnc_Insurgency_SetIED_ComponentDetails;
*/
private ["_idc", "_index", "_item"];
_idc = ctrlIDC (_this select 0);
_index = _this select 1;

_item = lbData [_idc, _index];

((findDisplay 8856) displayCtrl 1100) ctrlSetStructuredText parseText (getText (configFile >> "CfgWeapons" >> _item >> "ITK_IED_Description"));