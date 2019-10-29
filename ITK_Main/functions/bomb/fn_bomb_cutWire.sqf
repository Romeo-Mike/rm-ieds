/*
 	Name: ITK_fnc_Bomb_CutWire
 	
 	Author(s):
		L-H

 	Description:
		Cuts a wire for a bomb.
	
	Parameters:
		NUMBER: The wire index to cut. RANGE [0-2]
 	
 	Returns:
		Nothing
 	
 	Example:
		1 call ITK_fnc_Bomb_CutWire;
*/
private ["_object", "_wire", "_bombSetup", "_wires"];
_object = ITK_ActiveBomb;
_wire = _this + 1;

_bombSetup = _object getVariable ["ITK_Bomb", nil];
if (isNil "_bombSetup") exitWith {closeDialog 0;diag_log format ["%1 - not a bomb, cannot cut wire", _object]; };
if !(_bombSetup select 0) exitWith {closeDialog 0;};

_wires = _bombSetup select 2;

if !((_wires select _wire) select 1) exitWith {closeDialog 0;};

if (_wire != 3 and {(_wires select 3) select 1}) exitWith
{
	_object call ITK_fnc_bomb_Activate;
	closeDialog 0;
};
_bombSetup set [0, false];
_wires set [_wire, ["", false]];
_bombSetup set [2, _wires];
_object setVariable ["ITK_Bomb", _bombSetup, true];

disableSerialization;
private ["_dialog"];
_dialog = uiNamespace getVariable ['ITK_BombDefuse', displayNull];
if (isNull _dialog) exitWith {};

(_dialog displayCtrl (1004 + _wire)) ctrlSetText "";
(_dialog displayCtrl (1009 + _wire)) ctrlEnable ((_wires select _wire) select 1);