/*
	Name: ITK_fnc_Insurgency_RemoveIEDInterfaceComponent
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		ARRAY
	
	Returns:
		Nothing
	
	Example:
		_this call ITK_fnc_Insurgency_RemoveIEDInterfaceComponent;
*/
private ["_control", "_class"];
_control = _this select 0;

if (isNil "ITK_IED_Creation") then
{
	ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
};

#include "\ITK\define.hpp"

switch (ctrlIDC _control) do
{
	case IED_TRIGGER_PIC_IDC:
	{
		ctrlSetText [IED_TRIGGER_PIC_IDC, ""];
		ctrlShow [IED_TRIGGER_IDC, true];
		ITK_IED_Creation set [0, ["",""]];
	};
	case IED_FUSE_PIC_IDC:
	{
		ctrlSetText [IED_FUSE_PIC_IDC, ""];
		ctrlShow [IED_FUSE_IDC, true];
		ITK_IED_Creation set [1, ["",""]];
	};
	case IED_CHARGE_PIC_IDC:
	{
		ctrlSetText [IED_CHARGE_PIC_IDC, ""];
		ctrlShow [IED_CHARGE_IDC, true];
		ITK_IED_Creation set [2, ["",""]];
	};
	case IED_POWERSOURCE_PIC_IDC:
	{
		ctrlSetText [IED_POWERSOURCE_PIC_IDC, ""];
		ctrlShow [IED_POWERSOURCE_IDC, true];
		ITK_IED_Creation set [3, ["",""]];
	};
};
_class = ConfigFile >> "CfgMagazines" >> (format ['ITK_IED_%1_%2_%3_%4', (ITK_IED_Creation select 0) select 0, (ITK_IED_Creation select 1) select 0, (ITK_IED_Creation select 2) select 0, (ITK_IED_Creation select 3) select 0]);
if !(isClass (_class)) then
{
	ctrlSetText [IED_COMPLETED_PIC_IDC, ""];
};
call ITK_fnc_Insurgency_LoadIEDComponentList;