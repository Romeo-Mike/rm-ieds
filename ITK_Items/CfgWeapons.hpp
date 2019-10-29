#define LOAD(weight,capacity) maximumLoad = ##capacity##; \
							  mass = ##weight##;
class CfgWeapons
{
	class VestItem;
	class ItemCore;
	
	class ITK_Suicide_Vest_Base: ItemCore
	{
		scope = 0;
		allowedSlots[] = {};
		hiddenSelectons[] = {"camo"}; // Maybe
		
		class ItemInfo: VestItem
		{
			hiddenSelecitons[] = {"camo"};
			LOAD(0,0)
		};
	};
	
	class ITK_Suicide_Vest_Empty: ITK_Suicide_Vest_Base
	{
		scope = 2;
		displayName = "Suicide Vest - Empty";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_CA.paa";
		//picture = "\ITK_Items\Data\UI\icon_V_Suicide_empty_CA.paa";
		model = "\ITK_Items\Models\Vests\Suicide_Vest_empty.p3d";
		hiddenSelectionTextures[] = {"\ITK_Items\Data\Suicide_Vest_empty_co.paa"};
		
		class ItemInfo: ItemInfo
		{
			uniformModel = "\ITK_Items\Models\Vests\Suicide_Vest_empty.p3d";
			LOAD(35,40)
			armor = 5*0.6;
			passThrough = 0.4;
		};
	};
	
	class ITK_Suicide_Vest: ITK_Suicide_Vest_Base
	{
		scope = 2;
		displayName = "Suicide Vest";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVest_blk_CA.paa";
		//picture = "\ITK_Items\Data\UI\icon_V_Suicide_CA.paa";
		model = "\ITK_Items\Models\Vests\Suicide_Vest.p3d";
		hiddenSelectionTextures[] = {"\ITK_Items\Data\Suicide_Vest_co.paa"};
		class ItemInfo: ItemInfo
		{
			uniformModel = "\ITK_Items\Models\Vests\Suicide_Vest.p3d";
			LOAD(80,15)
			armor = 5*0.6;
			passThrough = 0.4;
		};
		
		ITK_SuicideVest = 1;
	};
	
	#include "IEDComponents.hpp"
	
	class ITK_BombDefusalKit: ItemCore
	{
		scope = 2;
		displayName = $STR_ITK_INSURGENCY_CT_BombDefusalKit_DisplayName;
		descriptionShort = $STR_ITK_INSURGENCY_CT_BombDefusalKit_Description;
		picture = "\ITK_Items\Data\UI\Cellphone_UI.paa";
		model = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		
		class ItemInfo: ITK_IEDItem
		{
			mass = 5;
			uniformModel = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		};
	};
};