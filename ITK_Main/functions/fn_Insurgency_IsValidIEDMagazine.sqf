/*
	Name: ITK_fnc_Insurgency_IsValidIEDMagazine
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		ARRAY
	
	Returns:
		STRING
	
	Example:
		ITK_IED_Creation call ITK_fnc_Insurgency_IsValidIEDMagazine;
*/
private "_class";
_class = format ["ITK_IED_%1_%2_%3_%4", (_this select 0) select 0, (_this select 1) select 0, (_this select 2) select 0, (_this select 3) select 0];
if !(isClass (ConfigFile >> "CfgMagazines" >> _class)) exitWith{""};

_class