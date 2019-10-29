/*
	Name: ITK_fnc_Insurgency_HandleClick
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Used to handle double clicks within the inventory screen.
	
	Parameters:
		0: NUMBER - IDC of the control
		1: NUMBER - Selected index within the control
	
	Returns:
		BOOLEAN - If the event was handled.
	
	Example:
		((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
		((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
		((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["LBDblClick", "_this call ITK_fnc_Insurgency_HandleClick"];
*/
private ["_class", "_idc", "_selectedIndex", "_result"];
_idc = ctrlIDC (_this select 0);
_selectedIndex = _this select 1;
_class = configFile >> "CfgMagazines" >> (lbData [_idc, _selectedIndex]);
_result = false;

if ((lbData [_idc, _selectedIndex]) == "") exitWith
{
	private ["_item", "_fncSort"];
	
	_fncSort = {
		private ["_newArray"];
		_newArray = [];
		{
			if !(_x in _newArray) then
			{
				_newArray set [count _newArray, _x];
			};
		} count _this;
		_newArray
	};
	_item = "";
	switch (_idc) do
	{
		// Uniform
		case 633:
		{
			_item = ((uniformItems player) call _fncSort) select _selectedIndex;
		};
		// Backpack
		case 619:
		{
			_item = ((backpackItems player) call _fncSort) select _selectedIndex;
		};
		// Vest
		case 638:
		{
			_item = ((vestItems player) call _fncSort) select _selectedIndex;
		};
	};
	switch (_item) do
	{
		case "ITK_IED_Cellphone":
		{
			closeDialog 0;
			createDialog "RscITK_PhoneInterface";
			_result = true;
		};
		case "ITK_IED_ClackerTriggerComponent":
		{
			private "_clacker";
			_clacker = player getVariable ["ITK_Clacker", []];
			if (count _clacker > 0) then
			{
				if ([player,(_clacker select 0), false, false] call ITK_fnc_Insurgency_DetonateIED) then
				{
					_clacker set [0, "X"];
					_clacker = _clacker - ["X"];
					player setVariable ["ITK_Clacker", _clacker, true];
					player sideChat format[localize "STR_ITK_INSURGENCY_IED_Clacker_Remaining", count _clacker];
				};
				_result = true;
			};
		};
		default
		{
			private ["_parents"];
			_class = configFile >> "CfgWeapons" >> _item;
			if (isClass(_class)) then
			{
				_parents = [_class, true] call BIS_fnc_returnParents;
				#define InParents(x) (x in _parents)
				#include "\ITK\define.hpp"
				switch (true) do
				{
					case InParents("ITK_IED_TriggerComponent"):
					{
						closeDialog 0;
						createDialog "RscITK_IEDSetupInterface";
						[IED_TRIGGER_IDC, _item] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;
					};
					case InParents("ITK_IED_FuseComponent"):
					{
						closeDialog 0;
						createDialog "RscITK_IEDSetupInterface";
						[IED_FUSE_IDC, _item] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;
					};
					case InParents("ITK_IED_ChargeComponent"):
					{
						closeDialog 0;
						createDialog "RscITK_IEDSetupInterface";
						[IED_CHARGE_IDC, _item] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;
					};
					case InParents("ITK_IED_PowerSourceComponent"):
					{
						closeDialog 0;
						createDialog "RscITK_IEDSetupInterface";
						[IED_POWERSOURCE_IDC, _item] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;
					};
				};
			};
		};
	};
	_result
};
if (isClass(_class)) then
{
	if (getNumber(_class >> "ITK_Placeable") == 1) then
	{
		closeDialog 0;
		[player, (lbData [_idc, _selectedIndex])] spawn ITK_fnc_Insurgency_SetupIED;
		_result = true;
	};
};

_result