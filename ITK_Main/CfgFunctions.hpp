class CfgFunctions
{	
	class ITK
	{
		class Insurgency
		{
			file="ITK\functions";
			class Insurgency_HandleClick{};
			class Insurgency_Initialise{postInit=1;};
			class Insurgency_SetupIED{};
			class Insurgency_PlaceIED{};
			class Insurgency_IsValidIEDMagazine{};
			
			class Insurgency_LoadIEDComponentList{};
			class Insurgency_SetIEDInterfaceComponent{};
			class Insurgency_SetIED_ComponentDetails{};
			class Insurgency_RemoveIEDInterfaceComponent{};
			class Insurgency_IED_ProgressBar{};
			
			class Insurgency_AddCodeToSpeedDial{};
			class Insurgency_RemoveCodeFromSpeedDial{};
			class Insurgency_SetSpeedDial{};
			class Insurgency_IED_DialPhone{};
			class Insurgency_DetonateIED{};
			class Insurgency_DetonateVest{};
			class Insurgency_HandleScrollWheel{};
			
			class Insurgency_RemoveIED_Components{};
			class Insurgency_IEDPlace_Cancel{};
			class Insurgency_IEDPlace_AttachTo{};
			class Insurgency_IEDPlace_Approve{};
			class Insurgency_IED_DeadManCheck{};
			
			class Insurgency_JammerInit{};
		};
		class Bomb
		{
			file="ITK\functions\bomb";
			class Bomb_Create{};
			class Bomb_Activate{};
			class Bomb_CutWire{};
			class Bomb_InitialiseDefuse{};
		};
	};
};