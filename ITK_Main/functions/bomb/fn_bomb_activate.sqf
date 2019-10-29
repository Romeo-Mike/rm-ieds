/*
 	Name: ITK_fnc_Bomb_Activate
 	
 	Author(s):
		L-H

 	Description:
		Sets off the bomb.
	
	Parameters:
		OBJECT : Bomb Object
 	
 	Returns:
		Nothing
 	
 	Example:
		Bomb_1 call ITK_fnc_Bomb_Activate;
*/
private ["_object", "_bombSetup", "_position", "_boom"];
_object = _this;

_bombSetup = _object getVariable ["ITK_Bomb", nil];
if (isNil "_bombSetup") exitWith { diag_log format ["%1 - not a bomb, cannot activate", _object]; };
if !(_bombSetup select 0) exitWith {};

_position = getPosATL _object;
_position set [2, (_position select 2) + 0.2];

_boom = createVehicle [_bombSetup select 1, _position, [], 0, "NONE"];