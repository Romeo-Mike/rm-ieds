class RscITK_NumKeyButton: RscITK_HiddenButton{};
class RscITK_PhoneInterface
{
	idd = 8855;
	movingEnable = 1;
	onLoad = "ITK_IED_CurrentSpeedDial = -1;";
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by L-H, v1.063, #Zygoha)
		////////////////////////////////////////////////////////
		class RscPicture_1200: RscPicture
		{
			idc = 1200;
			text = "\ITK\Data\UI\cellphone.paa";
			x = 0.231875 * safezoneW + safezoneX;
			y = 0.104 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.704 * safezoneH;
		};
		class numkey_1: RscITK_NumKeyButton
		{
			idc = 1600;
			x = 0.278281 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "1";
			action = "ctrlSetText [1400,((ctrlText 1400) + '1')];";
		};
		class numkey_2: RscITK_NumKeyButton
		{
			idc = 1601;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "2";
			action = "ctrlSetText [1400,((ctrlText 1400) + '2')];";
		};
		class numkey_3: RscITK_NumKeyButton
		{
			idc = 1602;
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "3";
			action = "ctrlSetText [1400,((ctrlText 1400) + '3')];";
		};
		class numkey_4: RscITK_NumKeyButton
		{
			idc = 1603;
			x = 0.278281 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "4";
			action = "ctrlSetText [1400,((ctrlText 1400) + '4')];";
		};
		class numkey_5: RscITK_NumKeyButton
		{
			idc = 1604;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "5";
			action = "ctrlSetText [1400,((ctrlText 1400) + '5')];";
		};
		class numkey_6: RscITK_NumKeyButton
		{
			idc = 1605;
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "6";
			action = "ctrlSetText [1400,((ctrlText 1400) + '6')];";
		};
		class numkey_7: RscITK_NumKeyButton
		{
			idc = 1606;
			x = 0.278281 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "7";
			action = "ctrlSetText [1400,((ctrlText 1400) + '7')];";
		};
		class numkey_8: RscITK_NumKeyButton
		{
			idc = 1607;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "8";
			action = "ctrlSetText [1400,((ctrlText 1400) + '8')];";
		};
		class numkey_9: RscITK_NumKeyButton
		{
			idc = 1608;
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "9";
			action = "ctrlSetText [1400,((ctrlText 1400) + '9')];";
		};
		class numkey_0: RscITK_NumKeyButton
		{
			idc = 1609;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "0";
			action = "ctrlSetText [1400,((ctrlText 1400) + '0')];";
		};
		class speedDialAdd: RscITK_NumKeyButton
		{
			idc = 1610;
			x = 0.278281 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Add to Speed Dial";
			action = "[(ctrlText 1401),(ctrlText 1400)] call ITK_fnc_Insurgency_AddCodeToSpeedDial;";
		};
		class clear: RscITK_HiddenButton
		{
			idc = 1610;
			x = 0.278281 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Clear";
			action = "ctrlSetText [1400,''];(ctrlText 1401) call ITK_fnc_Insurgency_RemoveCodeFromSpeedDial;ctrlSetText [1401,''];";
		};
		class dial: RscITK_HiddenButton
		{
			idc = 1611;
			x = 0.309219 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Dial";
			action = "[player, (ctrlText 1400)] spawn ITK_fnc_Insurgency_IED_DialPhone;";
		};
		class up: RscITK_HiddenButton
		{
			idc = 1612;
			x = 0.360781 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Up";
			action = "1 call ITK_fnc_Insurgency_SetSpeedDial;";
		};
		class down: RscITK_HiddenButton
		{
			idc = 1613;
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.485 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Down";
			action = "-1 call ITK_fnc_Insurgency_SetSpeedDial;";
		};
		class speedDial_Text: RscText
		{
			idc = 1405;
			y = 0.302 * safezoneH + safezoneY;
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
			x = 0.288594 * safezoneW + safezoneX;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			text = "Name";
		};
		class speedDial_edit: RscITK_CallScreen_Edit
		{
			idc = 1401;
			y = 0.302 * safezoneH + safezoneY;
			x = 0.318 * safezoneW + safezoneX;
			w = 0.1;
		};
		class numberEdit_Text: RscText
		{
			idc = 1406;
			y = 0.348 * safezoneH + safezoneY;
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
			x = 0.288594 * safezoneW + safezoneX;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			text = "#";
		};
		class number_edit: RscITK_CallScreen_Edit
		{
			canModify = 0;
			idc = 1400;
			y = 0.348 * safezoneH + safezoneY;
			x = 0.3 * safezoneW + safezoneX;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};