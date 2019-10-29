class CfgAmmo
{
	class DemoCharge_Remote_Ammo_Scripted;
	
	class ITK_IED_Remote_Ammo: DemoCharge_Remote_Ammo_Scripted
	{
		CraterEffects = "IEDMineBigLandCrater";
		explosionEffects = "IEDMineBigExplosion";
		hit = 300;
		indirectHit = 300;
		mineInconspicuousness = 60;
		defaultMagazine = "ITK_IED_Remote_Mag";
		mineModelDisabled = "\A3\Structures_F_EPA\Items\Vessels\TinContainer_F.p3d";
		model = "\A3\Structures_F_EPA\Items\Vessels\TinContainer_F.p3d";
		soundActivation[] = {"",0,0,0};
		soundDeactivation[] = {"",0,0,0};
		shadow = 1;
	};
	
	class ITK_IED_Cellphone_Remote_Ammo: ITK_IED_Remote_Ammo
	{
		mineInconspicuousness = 35;
		mineModelDisabled = "\A3\Structures_F\Items\Electronics\SatellitePhone_F.p3d";
		model = "\A3\Structures_F\Items\Electronics\SatellitePhone_F.p3d";
		soundTrigger[] = {"ITK_Items\Data\Audio\cellphone_ring",3.16228,1,50};
	};
	
	class APERSMine_Range_Ammo;
	
	class ITK_IED_Range_Ammo: APERSMine_Range_Ammo
	{
		CraterEffects = "IEDMineBigLandCrater";
		explosionEffects = "IEDMineBigExplosion";
		defaultMagazine = "ITK_IED_Range_Mag";
		mineInconspicuousness = 60;
		explosionTime = 1;
		explosionAngle = 360;
		mineModelDisabled = "\A3\Structures_F_EPA\Items\Tools\GasCanister_F.p3d";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCooker_F.p3d";
		soundActivation[] = {"",0,0,0};
		soundDeactivation[] = {"",0,0,0};
		hit = 300;
		indirectHit = 300;
		soundTrigger[] = {"ITK_Items\Data\Audio\IED_Activated",3.16228,1,20};
		mineTrigger = "ITK_RangeTriggerShort";
		shadow = 1;
	};
	
	class ITK_IED_ExtraTime_Range_Ammo: ITK_IED_Range_Ammo
	{
		mineTrigger = "ITK_RangeTriggerLong";
	};
	
	class APERSTripMine_Wire_Ammo;
	
	class ITK_IED_Tripmine_Ammo: APERSTripMine_Wire_Ammo
	{
		displayName = "IED (Wire)";
		model = "\A3\Weapons_F\explosives\mine_AP_tripwire";
		mineModelDisabled = "\A3\Weapons_F\explosives\mine_AP_tripwire_d";
		mineInconspicuousness = 60;
		soundTrigger[] = {"ITK_Items\Data\Audio\IED_Activated",3.16228,1,20};
		soundActivation[] = {"",0,0,0};
		soundDeactivation[] = {"",0,0,0};
		mineTrigger = "ITK_WireTrigger_Short";
		shadow = 1;
	};
	
	class ITK_IED_Long_Tripmine_Ammo: ITK_IED_Tripmine_Ammo
	{
		mineTrigger = "ITK_WireTrigger_Long";
	};
};