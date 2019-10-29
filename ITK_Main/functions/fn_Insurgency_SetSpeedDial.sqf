/*
	Name: ITK_fnc_Insurgency_SetSpeedDial
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		NUMBER - Whether to increase or decrease speed dial
	
	Returns:
		Nothing
	
	Example:
		// Decrease
		-1 call ITK_fnc_Insurgency_SetSpeedDial;
		// Increase
		1 call ITK_fnc_Insurgency_SetSpeedDial;
*/
if (count ITK_IED_SpeedDial == 0) exitWith{};
ITK_IED_CurrentSpeedDial = ITK_IED_CurrentSpeedDial + _this;
ITK_IED_CurrentSpeedDial = if(ITK_IED_CurrentSpeedDial < 0)then{(count ITK_IED_SpeedDial)-1}else{ITK_IED_CurrentSpeedDial};
ITK_IED_CurrentSpeedDial = if(ITK_IED_CurrentSpeedDial >= (count ITK_IED_SpeedDial))then{0}else{ITK_IED_CurrentSpeedDial};
ctrlSetText [1400,(ITK_IED_SpeedDial select ITK_IED_CurrentSpeedDial) select 1];
ctrlSetText [1401,(ITK_IED_SpeedDial select ITK_IED_CurrentSpeedDial) select 0];