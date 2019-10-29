class InventoryItem_Base_f;

class ITK_IEDItem: InventoryItem_Base_f
{
	allowedSlots[] = {801,701,901};
	type = 620;
};

class ITK_IED_Component: ItemCore
{
	ITK_IEDComponent = 1;
	ITK_IED_Description = "";
	ITK_IED_Class = "";
};

class ITK_IED_TriggerComponent: ITK_IED_Component{};
class ITK_IED_FuseComponent: ITK_IED_Component{};
class ITK_IED_ChargeComponent: ITK_IED_Component{};
class ITK_IED_PowerSourceComponent: ITK_IED_Component{};

class ITK_IED_Cellphone:ITK_IED_TriggerComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_Cellphone_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_Cellphone_description;
	picture = "\ITK_Items\Data\UI\Cellphone_UI.paa";
	model = "\A3\Structures_F\Items\Electronics\MobilePhone_old_F.p3d";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsMaterials[] = {"\A3\Structures_F\Items\Electronics\Data\electronics_screens.rvmat"};
	hiddenSelectionsTextures[] = {"\A3\Structures_F\Items\Electronics\Data\Electronics_screens_mobilePhone_old_CO.paa"};
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 5;
		uniformModel = "\A3\Structures_F\Items\Electronics\MobilePhone_old_F.p3d";
	};
	ITK_IED_Class = "Cellphone";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_Cellphone_details;
};

class ITK_IED_ClackerTriggerComponent:ITK_IED_TriggerComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_Clacker_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_Clacker_description;
	picture = "\ITK_Items\Data\UI\Clacker.paa";
	model = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 3;
		uniformModel = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
	};
	ITK_IED_Class = "Clacker";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_Clacker_details;
};
class ITK_IED_DeadmanTriggerComponent:ITK_IED_TriggerComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_Deadman_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_Deadman_description;
	picture = "\ITK_Items\Data\UI\DeadmanSwitch.paa";
	model = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 3;
		uniformModel = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
	};
	ITK_IED_Class = "Deadman";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_Deadman_details;
};
class ITK_IED_PressurePlateTriggerComponent:ITK_IED_TriggerComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_PressurePlate_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_PressurePlate_description;
	picture = "\ITK_Items\Data\UI\Pressure_plate.paa";
	model = "\A3\Structures_F_EPA\Items\Tools\GasCooker_F.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 20;
		uniformModel = "\A3\Structures_F_EPA\Items\Tools\GasCooker_F.p3d";
	};
	ITK_IED_Class = "PressurePlate";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_PressurePlate_details;
};
class ITK_IED_WireTriggerComponent:ITK_IED_TriggerComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_Wire_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_Wire_description;
	picture = "\ITK_Items\Data\UI\wire.paa";
	model = "\A3\Structures_F_EPA\Items\Tools\MetalWire_F.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 5;
		uniformModel = "\A3\Structures_F_EPA\Items\Tools\MetalWire_F.p3d";
	};
	ITK_IED_Class = "Wire";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_Wire_details;
};
class ITK_IED_ShortFuseComponent:ITK_IED_FuseComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_ShortFuse_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_ShortFuse_description;
	picture = "\ITK_Items\Data\UI\Fuse.paa";
	model = "\A3\Weapons_F\DummyItem.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 7;
		uniformModel = "\A3\Weapons_F\DummyItem.p3d";
	};
	ITK_IED_Class = "Short";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_ShortFuse_details;
};
class ITK_IED_LongFuseComponent:ITK_IED_FuseComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_LongFuse_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_LongFuse_description;
	picture = "\ITK_Items\Data\UI\Fuse.paa";
	model = "\A3\Weapons_F\DummyItem.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 10;
		uniformModel = "\A3\Weapons_F\DummyItem.p3d";
	};
	ITK_IED_Class = "Long";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_LongFuse_details;
};
class ITK_IED_MortarChargeComponent:ITK_IED_ChargeComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_MortarCharge_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_MortarCharge_description;
	picture = "\ITK_Items\Data\UI\MortarShell.paa";
	model = "\A3\weapons_f\ammo\shell";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 50;
		uniformModel = "\A3\weapons_f\ammo\shell";
	};
	ITK_IED_Class = "Mortar";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_MortarCharge_details;
};
class ITK_IED_12VBatteryPowerSourceComponent:ITK_IED_PowerSourceComponent
{
	scope = 2;
	displayName = $STR_ITK_INSURGENCY_IED_Component_12VBattery_name;
	descriptionShort = $STR_ITK_INSURGENCY_IED_Component_12VBattery_description;
	picture = "\ITK_Items\Data\UI\12VBattery.paa";
	model = "\A3\Structures_F_EPA\Items\Electronics\Battery_F.p3d";
	
	class ItemInfo: ITK_IEDItem
	{
		mass = 1;
		model = "\A3\Structures_F_EPA\Items\Electronics\Battery_F.p3d";
	};
	ITK_IED_Class = "12VBattery";
	ITK_IED_Description = $STR_ITK_INSURGENCY_IED_Component_12VBattery_details;
};