class RscPicture;
class RscText;
class RscButton;
class RscEdit;

class RscITK_CallScreen_Edit:RscEdit
{
	canModify = 1;
	colorBackground[] = {0,0,0,1};
	colorText[] = {0,0,0,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelection[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	text = "";
	style = "0x00 + 0x40 + 0x200";
	shadow = 1;
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) * 1)";
	x = 0.288594 * safezoneW + safezoneX;
	w = 0.0825 * safezoneW;
	h = 0.044 * safezoneH;
};
class RscITK_HiddenButton:RscButton
{
	colorText[] = {0, 0, 0, 0};
	colorDisabled[] = {0, 0, 0, 0};
	colorBackground[] = {0, 0, 0, 0};
	colorBackgroundDisabled[] = {0, 0, 0, 0};
	colorBackgroundActive[] = {0, 0, 0, 0};
	colorFocused[] = {0, 0, 0, 0};
	colorShadow[] = {0, 0, 0, 0};
	colorBorder[] = {0, 0, 0, 0};
	w = 0.095589;
	h = 0.039216;
	shadow = 0;
};

class IGUIBack;
class RscListbox;
class RscStructuredText;
class RscActivePictureKeepAspect;
class RscShortcutButton;

#include "Interfaces\BombInterface.hpp"
#include "Interfaces\PhoneInterface.hpp"
#include "Interfaces\IEDSetupInterface.hpp"
#include "Interfaces\IEDCreationProgressInterface.hpp"