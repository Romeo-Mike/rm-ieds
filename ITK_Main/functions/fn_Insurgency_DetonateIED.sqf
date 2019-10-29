/*
	Name: ITK_fnc_Insurgency_DetonateIED
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Detonates a remote IED that belongs to the passed code.
	
	Parameters:
		0: OBJECT - Unit detonating explosive
		1: STRING - IED code
		/
		1: ARRAY - IED
			0: OBJECT - IED
			1: NUMBER - Fuse Time
			2: NUMBER - Max range
		2: BOOLEAN - Ignore Range
		3: BOOLEAN - Ignore Jammer
	
	Returns:
		Nothing
	
	Example:
		// Cellphone
		[player, "2123", false, false] call ITK_fnc_Insurgency_DetonateIED;
		// Clacker
		[player, [IED, 1, 75], false, false] call ITK_fnc_Insurgency_DetonateIED;
		// Deadman switch
		[player, [IED, 1, 75], true, true] call ITK_fnc_Insurgency_DetonateIED;
*/
private ["_item","_result", "_ignoreRange", "_ignoreJammer", "_unit"];
_unit = (_this select 0);
_item = (_this select 1);
_ignoreRange = (_this select 2);
_ignoreJammer = (_this select 3);
_result = true;
if ((typeName _item) == "ARRAY") then
{
	if (!_ignoreRange) then
	{
		if ((_unit distance (_item select 0)) > (_item select 2)) exitWith {_result = false;};
	};
	if (!_result) exitWith{};
	if (!_ignoreJammer) then
	{
		{
			if (((_x select 2) getVariable ["ITK_JammerEnabled",false]) and {(_x select 0) distance (_item select 0) <= (_x select 1)}) exitWith
			{
				_result = false;
			};
		} count ITK_Jammers;
	};
	if (!_result) exitWith{};
	_item spawn {
		sleep (_this select 1);
		(_this select 0) setDamage 1;
	};
	_result = true;
}
else
{
	{
		if ((_x select 1) == _item) exitWith
		{
			if (isNull(_x select 0)) exitWith
			{
				ITK_IEDs set [_foreachIndex, "x"];
				ITK_IEDs = ITK_IEDs - ["x"];
				publicVariable "ITK_IEDs";
				_result = false;
			};
			private "_ied";
			_ied = _x select 0;
			if (!_ignoreRange) then
			{
				if ((_unit distance _ied) > (_x select 3)) exitWith {_result=false;};
			};
			if (!_result) exitWith{};
			if (!_ignoreJammer) then
			{
				{
					if (((_x select 2) getVariable ["ITK_JammerEnabled",false]) and {(_x select 0) distance _ied <= (_x select 1)}) exitWith
					{
						_result = false;
					};
				} count ITK_Jammers;
			};
			if (!_result) exitWith{};
			[_x,_foreachIndex] spawn {
				playSound3D ["ITK_Items\Data\Audio\cellphone_ring.wss",((_this select 0) select 0), false,getPosATL ((_this select 0) select 0),3.16228,1,75];
				sleep ((_this select 0) select 2);
				((_this select 0) select 0) setDamage 1;
				ITK_IEDs set [_this select 1, "x"];
				ITK_IEDs = ITK_IEDs - ["x"];
				publicVariable "ITK_IEDs";
			};
			_result = true;
		};
	} foreach ITK_IEDs;
};
_result