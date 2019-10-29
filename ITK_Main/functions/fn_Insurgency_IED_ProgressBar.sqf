private ["_class"];
_class = ITK_IED_Creation call ITK_fnc_Insurgency_IsValidIEDMagazine;
if (_class != "") then
{
	closeDialog 0;
	createDialog "Rsc_ITK_IED_CreationProgress";
	((findDisplay 8857) displayCtrl 1100) progressSetPosition 0.1;
	ITK_IED_CreateHandle = [getNumber(ConfigFile >> "CfgMagazines" >> _class >> "ITK_IED_CreateTime"),_class] spawn {
		private ["_timer"];
		_timer = 0;
		while {_timer < (_this select 0)} do
		{
			((findDisplay 8857) displayCtrl 1100) progressSetPosition (_timer/(_this select 0));
			_timer = _timer + 0.2;
			sleep 0.2;
		};
		closeDialog 0;
		[player, _this select 1] call ITK_fnc_Insurgency_SetupIED;
	};
};