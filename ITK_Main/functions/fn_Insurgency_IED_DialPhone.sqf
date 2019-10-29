/*
	Name: ITK_fnc_Insurgency_IED_DialPhone
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		
	
	Returns:
		Nothing
	
	Example:
		[player, "20113"] spawn ITK_fnc_Insurgency_IED_DialPhone;
*/
private ["_num", "_arr", "_ran", "_i", "_unit"];
_unit = _this select 0;
if (_unit getVariable ["ITK_IED_Dial", false]) exitWith {};
if !(alive _unit) exitWith {};
_unit setVariable ["ITK_IED_Dial", true, true];
_num = _this select 1;

if (_unit == player) then
{
	ctrlSetText [1400,"Calling"];
};
_ran = (ceil(random 8)) + 1;
_arr = [];
for [{_i=0}, {_i<_ran}, {_i=_i+1}] do
{
	_arr = _arr + ['.','..','...',''];
};
_i = 4;
if (_unit == player) then
{
	{
		if ((_i mod 4) == 0) then
		{
			playSound3D ["ITK_Items\Data\Audio\dialtone.wss", _unit, false, (_unit ModelToWorld [0,0.2,2]), 15,1,2.5];
		};
		sleep 0.25;
		ctrlSetText [1400,format["Calling%1",_x]];
		_i=_i+1;
		if (_i  == (count _arr + 2)) then
		{
			[_unit,_num, false, false] call ITK_fnc_Insurgency_DetonateIED;
		};
	} count _arr;
}
else
{
	sleep (0.25 * (count _arr - 1));
	[_unit,_num, false, false] call ITK_fnc_Insurgency_DetonateIED;
	sleep 0.5;
};
sleep 0.25;
if (_unit == player) then
{
	ctrlSetText [1400,"Call Ended!"];
};
if (_unit == player) then
{
	sleep 1;
	ctrlSetText [1400,_num];
};
_unit setVariable ["ITK_IED_Dial", false, true];