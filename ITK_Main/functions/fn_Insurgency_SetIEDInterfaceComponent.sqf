/*
	Name: ITK_fnc_Insurgency_SetIEDInterfaceComponent
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		ARRAY
	
	Returns:
		Nothing
	
	Example:
		[ctrlIDC (_this select 0), ((_this select 4) select 0) select 2] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;
*/
private ["_control", "_item", "_class", "_parents", "_set"];
_control = _this select 0;
_item = _this select 1;
_class = configFile >> "CfgWeapons" >> _item;
_parents = [_class, true] call BIS_fnc_returnParents;
_set = false;

if (isNil "ITK_IED_Creation") then
{
	ITK_IED_Creation = [["",""],["",""],["",""],["",""]];
};

#include "\ITK\define.hpp"

switch (_control) do
{
	case IED_TRIGGER_IDC:
	{
		if ("ITK_IED_TriggerComponent" in _parents) then
		{
			ctrlSetText [IED_TRIGGER_PIC_IDC, getText(_class >> "picture")];
			ctrlShow [IED_TRIGGER_IDC, false];
			ITK_IED_Creation set [0, [getText(_class >> "ITK_IED_Class"),_item]];
			_set = true;
		};
	};
	case IED_FUSE_IDC:
	{
		if ("ITK_IED_FuseComponent" in _parents) then
		{
			ctrlSetText [IED_FUSE_PIC_IDC, getText(_class >> "picture")];
			ctrlShow [IED_FUSE_IDC, false];
			ITK_IED_Creation set [1, [getText(_class >> "ITK_IED_Class"),_item]];
			_set = true;
		};
	};
	case IED_CHARGE_IDC:
	{
		if ("ITK_IED_ChargeComponent" in _parents) then
		{
			ctrlSetText [IED_CHARGE_PIC_IDC, getText(_class >> "picture")];
			ctrlShow [IED_CHARGE_IDC, false];
			ITK_IED_Creation set [2, [getText(_class >> "ITK_IED_Class"),_item]];
			_set = true;
		};
	};
	case IED_POWERSOURCE_IDC:
	{
		if ("ITK_IED_PowerSourceComponent" in _parents) then
		{
			ctrlSetText [IED_POWERSOURCE_PIC_IDC, getText(_class >> "picture")];
			ctrlShow [IED_POWERSOURCE_IDC, false];
			ITK_IED_Creation set [3, [getText(_class >> "ITK_IED_Class"),_item]];
			_set = true;
		};
	};
};
if (_set) then
{
	private ["_numItems", "_i"];
	_numItems = lbSize 1500;
	for [{_i = 0}, {_i <_numItems}, {_i = _i+1}] do
	{
		if (lbData [1500,_i] == _item) exitWith
		{
			lbDelete [1500, _i];
		};
	};
	_class = ITK_IED_Creation call ITK_fnc_Insurgency_IsValidIEDMagazine;
	if (_class != "") then
	{
		ctrlSetText [IED_COMPLETED_PIC_IDC, getText(ConfigFile >> "CfgMagazines" >> _class >> "picture")];
	};
};