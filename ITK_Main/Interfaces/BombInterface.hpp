class Rsc_ITK_BombPicture:RscPicture
{
	y = 0.05;
	w = 0.8;
	h = 0.5;
};

class Rsc_ITK_BombText: RscText
{
	style = 32 + 0x02;
	colorBackground[] = {0.1, 0.1, 0.1, 1};
	sizeEx = 0.05;
	w = 1;
	h = 0.05;
};
class Rsc_ITK_BombButton:RscButton
{
	colorDisabled[] = {0.4,0.4,0.4,1};
	x = 0.8;
	y = 0.05;
	w = 0.2;
	h = 0.05;
	action = "";
};
class Rsc_ITK_BombInterface
{
	idd = 58888;
	onLoad = "uiNamespace setVariable ['ITK_BombDefuse', _this select 0]";
	onUnload = "uiNamespace setVariable ['ITK_BombDefuse', displayNull]";
	fadeIn=0.5;
	fadeOut=0.5;
	movingEnable = false;
	duration = 10e10;
	name = "Rsc_ITK_BombInterface"; 
	class controls
	{
		class HeaderText: Rsc_ITK_BombText
		{
			idc = 1001;
			text = "$STR_ITK_INSURGENCY_DefuseInterface";
		};
		class background: Rsc_ITK_BombPicture
		{
			idc = 1000;
			text = "ITK\bomb\images\Interface-01.paa";
		};
		class PositiveWire: Rsc_ITK_BombPicture
		{
			idc = 1005;
			text = "";
		};
		class NegativeWire: Rsc_ITK_BombPicture
		{
			idc = 1006;
			text = "";
		};
		class AntennaWire: Rsc_ITK_BombPicture
		{
			idc = 1007;
			text = "";
		};
		class CutPositive: Rsc_ITK_BombButton
		{
			idc = 1010;
			x = 0.15;
			y = 0.4;
			text = "$STR_ITK_INSURGENCY_CutWire";
			action = "0 call ITK_fnc_Bomb_cutWire;";
		};
		class CutNegative: Rsc_ITK_BombButton
		{
			idc = 1011;
			text = "$STR_ITK_INSURGENCY_CutWire";
			x = 0.1;
			y = 0.12;
			action = "1 call ITK_fnc_Bomb_cutWire;";
		};
		class CutAntenna: Rsc_ITK_BombButton
		{
			idc = 1012;
			text = "$STR_ITK_INSURGENCY_CutWire";
			x = 0.52;
			y = 0.12;
			action = "2 call ITK_fnc_Bomb_CutWire;";
		};
		class CloseDialog: Rsc_ITK_BombButton
		{
			idc = 1013;
			text = "$STR_ITK_INSURGENCY_Close";
			y = 0.5;
			action = "closeDialog 0;";
		};
	};
};