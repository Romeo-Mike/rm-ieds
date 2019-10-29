class CfgVehicles
{
	class Box_IND_AmmoOrd_F;

	class ITK_IED_Crate: Box_IND_AmmoOrd_F
	{
		author = "L-H";
		displayName = $STR_ITK_INSURGENCY_IED_Crate;
		class TransportItems
		{
			class _xx_ITK_component_cellphone
			{
				name = "ITK_IED_Cellphone";
				count = 10;
			};
			class _xx_ITK_component_clacker
			{
				name = "ITK_IED_ClackerTriggerComponent";
				count = 10;
			};
			class _xx_ITK_component_deadman
			{
				name = "ITK_IED_DeadmanTriggerComponent";
				count = 10;
			};
		};
		class TransportMagazines
		{
			class _xx_ITK_csm12v
			{
				count = 5;
				magazine = "ITK_IED_Clacker_Short_Mortar_12VBattery";
			};
			class _xx_ITK_ppsm12v
			{
				count = 5;
				magazine = "ITK_IED_PressurePlate_Short_Mortar_12VBattery";
			};
			class _xx_ITK_cellsm12v
			{
				count = 5;
				magazine = "ITK_IED_Cellphone_Short_Mortar_12VBattery";
			};
			class _xx_ITK_dmssm12v
			{
				count = 5;
				magazine = "ITK_IED_Deadman_Short_Mortar_12VBattery";
			};
			class _xx_ITK_clm12v
			{
				count = 5;
				magazine = "ITK_IED_Clacker_Long_Mortar_12VBattery";
			};
			class _xx_ITK_celllm12v
			{
				count = 5;
				magazine = "ITK_IED_Cellphone_Long_Mortar_12VBattery";
			};
			class _xx_ITK_dmslm12v
			{
				count = 5;
				magazine = "ITK_IED_Deadman_Long_Mortar_12VBattery";
			};
			class _xx_ITK_pplm12v
			{
				count = 5;
				magazine = "ITK_IED_PressurePlate_Long_Mortar_12VBattery";
			};
			class _xx_ITK_wsm12v
			{
				count = 5;
				magazine = "ITK_IED_Wire_Short_Mortar_12VBattery";
			};
			class _xx_ITK_wlm12v
			{
				count = 5;
				magazine = "ITK_IED_Wire_Long_Mortar_12VBattery";
			};
		};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
	class ITK_IED_Component_Crate: Box_IND_AmmoOrd_F
	{
		author = "L-H";
		displayName = $STR_ITK_INSURGENCY_IED_Component_Crate;
		class TransportItems
		{
			class _xx_ITK_component_cellphone
			{
				name = "ITK_IED_Cellphone";
				count = 5;
			};
			class _xx_ITK_component_clacker
			{
				name = "ITK_IED_ClackerTriggerComponent";
				count = 10;
			};
			class _xx_ITK_component_deadman
			{
				name = "ITK_IED_DeadmanTriggerComponent";
				count = 5;
			};
			class _xx_ITK_component_pressureplate
			{
				name = "ITK_IED_PressurePlateTriggerComponent";
				count = 5;
			};
			class _xx_ITK_component_wire
			{
				name = "ITK_IED_WireTriggerComponent";
				count = 5;
			};
			class _xx_ITK_component_shortfuse
			{
				name = "ITK_IED_ShortFuseComponent";
				count = 20;
			};
			class _xx_ITK_component_longfuse
			{
				name = "ITK_IED_LongFuseComponent";
				count = 20;
			};
			class _xx_ITK_component_mortar
			{
				name = "ITK_IED_MortarChargeComponent";
				count = 30;
			};
			class _xx_ITK_component_12Vbattery
			{
				name = "ITK_IED_12VBatteryPowerSourceComponent";
				count = 40;
			};
		};
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
	
	class Bag_Base;
	class ITK_ThorIII: Bag_Base 
	{
		scope = 2;
		displayName = "Thor III";
		descriptionShort = "Thor III IED Jammer";
		author = "ITK";
		maximumLoad = 40;
		mass = 25;
		model = "\ITK_Items\models\ThorIII\ITK_Thor_III.p3d";
		ITK_JammerRange = 150; // In terms of metres
		ITK_JammerMaxCharge = 30; // In terms of minutes
	};
	
	class ThingX;
	class ITK_Test:ThingX
	{
		scope = 2;
		faction = "Default";
		author = "ITK";
		VehicleClass = "Objects";
		model = "\ITK_Items\Models\IEDs\c4\c4.p3d";
		displayName = "ITK Test (C4)";
	};
};