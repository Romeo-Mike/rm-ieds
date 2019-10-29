#include "\ITK_Items\IEDTypes.hpp"
class CfgMagazines
{
	class DemoCharge_Remote_Mag;
	class ATMine_Range_Mag;
	
	class ITK_IED_Clacker_Short_Mortar_12VBattery:DemoCharge_Remote_Mag
	{
		scope = 2;
		ammo = "ITK_IED_Remote_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_CSM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_CSM12V_Remote_Mag_DisplayName;
		mass = 60;
		model = "\A3\Structures_F_EPA\Items\Vessels\TinContainer_F.p3d";
		picture = "\A3\Weapons_F\Data\UI\gear_c4_charge_small_CA.paa";
		useAction = 0;
		ITK_Placeable = 1;
		ITK_Type = TYPE_Clacker;
		ITK_FuseTime = 1;
		ITK_IED_SetupObject = "Land_TinContainer_F";
		ITK_IED_MaxDistance = 75;
		ITK_IED_CreateTime = 15;
	};
	
	class ITK_IED_PressurePlate_Short_Mortar_12VBattery: ATMine_Range_Mag
	{
		scope = 2;
		ammo = "ITK_IED_Range_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_PSM12V_Range_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_PSM12V_Range_Mag_DisplayName;
		mass = 80;
		model = "\A3\Structures_F_EPA\Items\Tools\GasCooker_F.p3d";
		picture = "\A3\Weapons_F\Data\UI\gear_mine_AP_CA.paa";
		useAction = 0;
		ITK_Placeable = 1;
		ITK_Type = TYPE_PressurePlate;
		ITK_IED_SetupObject = "Land_GasCooker_F";
		ITK_IED_OnCreate = "sleep 0.1;private '_pos';_pos = (getPosATL _this);if((_pos select 2)>0)then{_pos set[2, (_pos select 2) - 0.12];_this setPosATL _pos;};";
		ITK_IED_CreateTime = 17;
	};
	
	class ITK_IED_Cellphone_Short_Mortar_12VBattery:DemoCharge_Remote_Mag
	{
		scope = 2;
		ammo = "ITK_IED_Cellphone_Remote_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_CellSM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_CellSM12V_Remote_Mag_DisplayName;
		mass = 62;
		model = "\A3\Structures_F\Items\Electronics\SatellitePhone_F.p3d";
		picture = "\A3\Weapons_F\Data\UI\gear_c4_charge_small_CA.paa";
		useAction = 0;
		ITK_Placeable = 1;
		ITK_Type = TYPE_Cellphone;
		ITK_FuseTime = 1;
		ITK_IED_SetupObject = "Land_SatellitePhone_F";
		ITK_IED_MaxDistance = 8000;
		ITK_IED_CreateTime = 18;
	};
	
	class ITK_IED_Deadman_Short_Mortar_12VBattery:ITK_IED_Clacker_Short_Mortar_12VBattery
	{
		ITK_Type = TYPE_DeadmanTrigger;
		ITK_IED_MaxDistance = 25;
		descriptionShort = $STR_ITK_INSURGENCY_IED_DSM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_DSM12V_Remote_Mag_DisplayName;
		ITK_IED_CreateTime = 16;
	};
	
	class ITK_IED_Clacker_Long_Mortar_12VBattery:ITK_IED_Clacker_Short_Mortar_12VBattery
	{
		mass = 65;
		ITK_FuseTime = 5;
		descriptionShort = $STR_ITK_INSURGENCY_IED_CLM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_CLM12V_Remote_Mag_DisplayName;		
	};

	class ITK_IED_Cellphone_Long_Mortar_12VBattery:ITK_IED_Cellphone_Short_Mortar_12VBattery
	{
		mass = 67;
		ITK_FuseTime = 5;
		descriptionShort = $STR_ITK_INSURGENCY_IED_CellLM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_CellLM12V_Remote_Mag_DisplayName;
	};
	
	class ITK_IED_Deadman_Long_Mortar_12VBattery:ITK_IED_Deadman_Short_Mortar_12VBattery
	{
		mass = 65;
		ITK_FuseTime = 5;
		descriptionShort = $STR_ITK_INSURGENCY_IED_DLM12V_Remote_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_DLM12V_Remote_Mag_DisplayName;
	};
	
	class ITK_IED_PressurePlate_Long_Mortar_12VBattery: ITK_IED_PressurePlate_Short_Mortar_12VBattery
	{
		mass = 85;
		ammo = "ITK_IED_ExtraTime_Range_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_PLM12V_Range_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_PLM12V_Range_Mag_DisplayName;
	};
	
	class APERSTripMine_Wire_Mag;
	
	class ITK_IED_Wire_Short_Mortar_12VBattery:APERSTripMine_Wire_Mag
	{
		scope = 2;
		ammo = "ITK_IED_Tripmine_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_WSM12V_Wire_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_WSM12V_Wire_Mag_DisplayName;
		mass = 65;
		model = "\A3\Structures_F_EPA\Items\Vessels\TinContainer_F.p3d";
		picture = "\A3\Weapons_F\Data\UI\gear_mine_AP_tripwire_CA.paa";
		useAction = 0;
		ITK_Placeable = 1;
		ITK_Type = TYPE_Wire;
		ITK_FuseTime = 1;
		ITK_IED_SetupObject = "Land_HandyCam_F";
		ITK_IED_CreateTime = 18;
	};
	
	class ITK_IED_Wire_Long_Mortar_12VBattery:ITK_IED_Wire_Short_Mortar_12VBattery
	{
		mass = 70;
		ammo = "ITK_IED_Long_Tripmine_Ammo";
		descriptionShort = $STR_ITK_INSURGENCY_IED_WLM12V_Wire_Mag_Description;
		displayName = $STR_ITK_INSURGENCY_IED_WLM12V_Wire_Mag_DisplayName;
	};
};