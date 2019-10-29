/*
	Name: ITK_fnc_Insurgency_IED_DeadManCheck
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		OBJECT: Unit
	
	Returns:
		BOOLEAN
	
	Example:
		player call ITK_fnc_Insurgency_IED_DeadManCheck;
*/
private ["_deadman", "_result"];
_deadman = _this getVariable ["ITK_Deadman",[]];
_result = false;
if (count _deadman >= 3) then
{
	if ("ITK_IED_DeadmanTriggerComponent" in (items _this)) then
	{
		if ((_this distance (_deadman select 0)) > (_deadman select 2)) exitWith
		{
			[_this,_deadman,true,true] call ITK_fnc_Insurgency_DetonateIED;
			_this setVariable ["ITK_Deadman", [], true];
			_result = false;
		};
		_result = true;
	}
	else
	{
		[_this,_deadman,true,true] call ITK_fnc_Insurgency_DetonateIED;
		_this setVariable ["ITK_Deadman", [], true];
		_result = false;
	};
};
_result