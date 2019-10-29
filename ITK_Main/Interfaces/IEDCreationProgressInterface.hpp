#include "\ITK\define.hpp"
class RscProgress;

class Rsc_ITK_IED_CreationProgress
{
	idd = 8857;
	movingEnable = 0;
	enableSimulation = 1;
	onUnload = "if (!scriptDone ITK_IED_CreateHandle)then{terminate ITK_IED_CreateHandle;};";
	class controls 
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by L-H, v1.063, #Qofocu)
		////////////////////////////////////////////////////////

		class background: IGUIBack
		{
			idc = 2200;
			x = 13 * GUI_GRID_W + GUI_GRID_X;
			y = 6 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 7 * GUI_GRID_H;
		};
		class CancelButton: RscShortcutButton
		{
			idc = 1700;
			text = $STR_A3_IEDEditor_CancelIEDCreation;
			x = 18.5 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0.92,0.4,0.125,1};
			colorBackgroundFocused[] = {0.92,0.4,0.125,1};
			action = "closeDialog 0;";
		};
		class TitleText: RscText
		{
			idc = 1000;
			style = ST_CENTER;
			SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) * 1)";
			text = $STR_A3_IEDEditor_IEDCreating;
			x = 17 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 8 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {0.92,0.4,0.125,1};
		};
		class progressBar: RscProgress
		{
			idc = 1100;
			x = 14 * GUI_GRID_W + GUI_GRID_X;
			y = 8 * GUI_GRID_H + GUI_GRID_Y;
			w = 14 * GUI_GRID_W;
			h = 2 * GUI_GRID_H;
			colorFrame[] = {0,0,0,0};
			colorBar[] ={0.92,0.4,0.125,1};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};