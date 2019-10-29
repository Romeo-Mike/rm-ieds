/*
 	Name: ITK_fnc_Bomb_initaliseDefuse
 	
 	Author(s):
		L-H

 	Description:
		Initialises the bomb defuse interface.
	
	Parameters:
		OBJECT: Bomb
 	
 	Returns:
		Nothing
 	
 	Example:
		Bomb_1 call ITK_fnc_Bomb_InitaliseDefuse;
*/
/*
ITK_bomb
0 - BOOL : Active/alive
1 - STRING : bomb type
2 - ARRAY : Wires
*/
private ["_object", "_bombSetup"];
_object = _this;

_bombSetup = _object getVariable ["ITK_Bomb", nil];
if (isNil "_bombSetup") exitWith { diag_log format ["%1 - not a bomb, cannot cut wire", _object]; };
if !(_bombSetup select 0) exitWith {};

_bombSetup = _bombSetup select 2;

createDialog "Rsc_ITK_BombInterface";
disableSerialization;
private ["_dialog"];
_dialog = uiNamespace getVariable ["ITK_BombDefuse", displayNull];
if (isNull _dialog) exitWith {};

(_dialog displayCtrl 1000) ctrlSetText format["ITK\bomb\images\Interface-%1.paa", _bombSetup select 0];

if ((_bombSetup select 1) select 1) then {
	(_dialog displayCtrl 1005) ctrlSetText format["ITK\bomb\images\P-%1.paa", (_bombSetup select 1) select 0];
};
if ((_bombSetup select 2) select 1) then {
	(_dialog displayCtrl 1006) ctrlSetText format["ITK\bomb\images\N-%1.paa", (_bombSetup select 2) select 0];
};
if ((_bombSetup select 3) select 1) then {
	(_dialog displayCtrl 1007) ctrlSetText format["ITK\bomb\images\A-%1.paa", (_bombSetup select 3) select 0];
};

(_dialog displayCtrl 1010) ctrlEnable ((_bombSetup select 1) select 1);
(_dialog displayCtrl 1011) ctrlEnable ((_bombSetup select 2) select 1);
(_dialog displayCtrl 1012) ctrlEnable ((_bombSetup select 3) select 1);

ITK_ActiveBomb = _object;