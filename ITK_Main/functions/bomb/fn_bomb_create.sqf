/*
 	Name: ITK_fnc_Bomb_Create
 	
 	Author(s):
		L-H

 	Description:
		Initialises the object for bomb usage
	
	Parameters:
		0: OBJECT : Bomb Object
		1: STRING : Ammo class to use as bomb ("Bo_Mk82")
		2: ARRAY  : Bomb interface look
			0 - STRING : Interface ("01")
			1 - STRING : Positive Wire ("Blue", "Yellow")
			2 - STRING : Negative Wire ("Black", "Yellow")
			3 - STRING : Antenna Wire ("Green", "Red")
 	
 	Returns:
		Nothing
 	
 	Example:
		[Bomb1, "Bo_Mk82", ["01", "Blue", "Black", "Green"]] call ITK_fnc_Bomb_create;
*/
private ["_object", "_bombType","_bombSetup", "_wires"];
_object = _this select 0;

if (isServer) then
{
	_bombType = _this select 1;
	_wires = _this select 2;
	_wires set [1, [_wires select 1, true]];
	_wires set [2, [_wires select 2, true]];
	_wires set [3, [_wires select 3, true]];
	/*
		ITK_bomb
		0 - BOOL : Active/alive
		1 - STRING : bomb type
		2 - ARRAY : Wires
	*/
	_bombSetup = [true, _bombType, _wires];
	_object setVariable ["ITK_Bomb", _bombSetup, true];
};
if (hasInterface) then
{
	_object addAction [localize "STR_ITK_INSURGENCY_Inspect", {(_this select 0) call ITK_fnc_Bomb_InitialiseDefuse;}, nil, 7, true, false, "",
		"((_target getVariable 'ITK_Bomb') select 0) AND {(_target distance _this) < 3}"];
};