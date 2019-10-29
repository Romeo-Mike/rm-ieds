#include "\ITK\define.hpp"

class Rsc_ITK_ComponentContainer: RscListbox
{
	canDrag = 1;
	colorText[] = {0,0,0,0.5};
	w = 5.5 * GUI_GRID_W;
	h = 4.5 * GUI_GRID_H;
	onLBDrop = "[ctrlIDC (_this select 0), ((_this select 4) select 0) select 2] call ITK_fnc_Insurgency_SetIEDInterfaceComponent;";
};
class Rsc_ITK_IEDComponent_Picture: RscActivePictureKeepAspect
{
	text = "";
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,1};
	colorActive[] = {1,0,0,1};
	colorHover[] = {1,0,0,1};
	w = 4.5 * GUI_GRID_W;
	h = 3.5 * GUI_GRID_H;
	onMouseButtonClick = "_this call ITK_fnc_Insurgency_RemoveIEDInterfaceComponent;";
};

class RscITK_IEDSetupInterface
{
	idd = 8856;
	movingEnable = 0;
	enableSimulation = 0;
	onLoad = "ITK_IED_Creation = [['',''],['',''],['',''],['','']];ITK_null = [] spawn ITK_fnc_Insurgency_LoadIEDComponentList;";
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by L-H, v1.063, #Myqaju)
		////////////////////////////////////////////////////////
		class Background: IGUIBack
		{
			idc = 2200;
			x = 0.5 * GUI_GRID_W + GUI_GRID_X;
			y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 36 * GUI_GRID_W;
			h = 24 * GUI_GRID_H;
			colorbackground[] = {0,0,0,0.8};
		};
		class IEDEditorTitle: RscText
		{
			idc = 999;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_Title;
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) * 1)";
			x = 11.5 * GUI_GRID_W + GUI_GRID_X;
			y = 0.75 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorText[] = {0.92,0.4,0.125,1};
		};
		class IED_Components: Rsc_ITK_ComponentContainer
		{
			idc = 1500;
			x = 1 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 11 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
			onLBSelChanged = "_this call ITK_fnc_Insurgency_SetIED_ComponentDetails;";
			onLBDrop = "";
		};
		class IED_ComponentListText: RscText
		{
			idc = 1000;
			text = $STR_A3_IEDEditor_IED_ComponentListText;
			style = ST_CENTER;
			x = 1 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
		};
		class CreateIEDButton: RscShortcutButton
		{
			idc = 1600;
			text = $STR_A3_IEDEditor_CreateIEDButton;
			x = 31 * GUI_GRID_W + GUI_GRID_X;
			y = 9 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "call ITK_fnc_Insurgency_IED_ProgressBar;";
			colorBackground[] = {0.92,0.4,0.125,1};
			colorBackgroundFocused[] = {0.92,0.4,0.125,1};
		};
		class CancelIEDCreation: RscShortcutButton
		{
			idc = 1601;
			text = $STR_A3_IEDEditor_CancelIEDCreation;
			x = 31 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "closeDialog 0;";
			colorBackground[] = {0.92,0.4,0.125,1};
			colorBackgroundFocused[] = {0.92,0.4,0.125,1};
		};
		class ComponentDetailText: RscStructuredText
		{
			idc = 1100;
			x = 1 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 7 * GUI_GRID_H;
		};
		class ComponentTitle: RscText
		{
			idc = 1001;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_ComponentTitle;
			x = 1 * GUI_GRID_W + GUI_GRID_X;
			y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class TriggerITK_ComponentContainer: Rsc_ITK_ComponentContainer
		{
			idc = IED_TRIGGER_IDC;
			x = 13 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class TriggerComponentPicture: Rsc_ITK_IEDComponent_Picture
		{
			idc = IED_TRIGGER_PIC_IDC;
			x = 13.5 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class TriggerComponentTitle: RscText
		{
			idc = 1002;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_TriggerComponentTitle;
			x = 13 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 5.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class FuseComponentTitle: RscText
		{
			idc = 1003;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_FuseComponentTitle;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 3 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class FuseITK_ComponentContainer: Rsc_ITK_ComponentContainer
		{
			idc = IED_FUSE_IDC;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class FuseComponentPicture: Rsc_ITK_IEDComponent_Picture
		{
			idc = IED_FUSE_PIC_IDC;
			x = 21.5 * GUI_GRID_W + GUI_GRID_X;
			y = 5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class ChargeComponentTitle: RscText
		{
			idc = 1004;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_ChargeComponentTitle;
			x = 13 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class ChargeITK_ComponentContainer: Rsc_ITK_ComponentContainer
		{
			idc = IED_CHARGE_IDC;
			x = 13 * GUI_GRID_W + GUI_GRID_X;
			y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class ChargeComponentPicture: Rsc_ITK_IEDComponent_Picture
		{
			idc = IED_CHARGE_PIC_IDC;
			x = 13.5 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
		};
		class PowerSourceComponentTitle: RscText
		{
			idc = 1005;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_PowerSourceComponentTitle;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 7 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class PowerSourceITK_ComponentContainer: Rsc_ITK_ComponentContainer
		{
			idc = IED_POWERSOURCE_IDC;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
		};
		class PowerSourceComponentPicture: Rsc_ITK_IEDComponent_Picture
		{
			idc = IED_POWERSOURCE_PIC_IDC;
			x = 21.5 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
		};
		class CompletedIEDTitle: RscText
		{
			idc = 1006;
			style = ST_CENTER;
			text = $STR_A3_IEDEditor_CompletedIEDTitle;
			x = 18 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 4 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class CompletedIEDContainer: IGUIBack
		{
			idc = 2205;
			x = 16.5 * GUI_GRID_W + GUI_GRID_X;
			y = 17.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7 * GUI_GRID_W;
			h = 5.5 * GUI_GRID_H;
			colorbackground[] = {0,0,0,0.3};
		};
		class CompletedIEDPicture: Rsc_ITK_IEDComponent_Picture
		{
			idc = IED_COMPLETED_PIC_IDC;
			text = "";
			x = 17 * GUI_GRID_W + GUI_GRID_X;
			y = 18 * GUI_GRID_H + GUI_GRID_Y;
			w = 6 * GUI_GRID_W;
			h = 4.5 * GUI_GRID_H;
			colorActive[] = {1,1,1,1};
			colorHover[] = {1,1,1,1};
			onMouseButtonClick = "";
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};