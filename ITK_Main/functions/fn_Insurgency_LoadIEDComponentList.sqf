/*
	Name: ITK_fnc_Insurgency_LoadIEDComponentList
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call ITK_fnc_Insurgency_LoadIEDComponentList;
*/
private ["_items", "_item", "_index"];
lbClear 1500;
_items = items player;
{
	_item = ConfigFile >> "CfgWeapons" >> _x;
	if (getNumber(_item >> "ITK_IEDComponent") == 1) then
	{
		_index = lbAdd [1500, getText(_item >> "displayName")];
		lbSetData [1500, _index, _x];
		lbSetPicture [1500, _index, getText(_item >> "picture")];
	};
} count _items;
private ["_numItems", "_i"];
_numItems = lbSize 1500;
{
	for [{_i = 0}, {_i <_numItems}, {_i = _i+1}] do
	{
		if(lbData [1500, _i] == (_x select 1)) exitWith
		{
			lbDelete [1500, _i];
		};
	};
} count ITK_IED_Creation;