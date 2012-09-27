#include "ISteamGameServerItems002.h"

	virtual SteamAPICall_t  LoadItems ( CSteamID steamid )	{
		char log[1024];
		sprintf(log,"LoadItems() steamid=0x%X ",
			steamid		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->LoadItems(steamid);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetItemCount ( CSteamID steamid )	{
		char log[1024];
		sprintf(log,"GetItemCount() steamid=0x%X ",
			steamid		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetItemCount(steamid);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemIterative ( CSteamID steamid,  uint32 i,  ItemID *UniqueID,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity )	{
		char log[1024];
		sprintf(log,"GetItemIterative() steamid=0x%X i=0x%X UniqueID=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X ",
			steamid,
			i,
			UniqueID,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemIterative(steamid, i, UniqueID, ItemType, ItemLevel, Quality, Flags, Quantity);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemByID ( ItemID itemid,  CSteamID* steamid,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity )	{
		char log[1024];
		sprintf(log,"GetItemByID() itemid=0x%X steamid=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X ",
			itemid,
			steamid,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemByID(itemid, steamid, ItemType, ItemLevel, Quality, Flags, Quantity);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemAttribute ( ItemID itemid,  uint32,  uint32*,  float* )	{
		char log[1024];
		sprintf(log,"GetItemAttribute() itemid=0x%X uint32=0x%X =0x%X =0x%X ",
			itemid,
			uint32,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemAttribute(itemid, uint32, , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HNewItemRequest  CreateNewItemRequest ( CSteamID steamid,  uint32,  EItemQuality quality )	{
		char log[1024];
		sprintf(log,"CreateNewItemRequest() steamid=0x%X uint32=0x%X quality=0x%X ",
			steamid,
			uint32,
			quality		);
		OutputDebugStringA(log);
		HNewItemRequest  ret = m_pWrapper->CreateNewItemRequest(steamid, uint32, quality);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemCriteria ( HNewItemRequest ireq,  const char*,  EItemCriteriaOperator,  const char*,  bool )	{
		char log[1024];
		sprintf(log,"AddNewItemCriteria() ireq=0x%X =%s EItemCriteriaOperator=0x%X =%s bool=0x%X ",
			ireq,
			,
			EItemCriteriaOperator,
			,
			bool		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemCriteria(ireq, , EItemCriteriaOperator, , bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemCriteria ( HNewItemRequest ireq,  const char*,  EItemCriteriaOperator,  float,  bool )	{
		char log[1024];
		sprintf(log,"AddNewItemCriteria() ireq=0x%X =%s EItemCriteriaOperator=0x%X float=0x%X bool=0x%X ",
			ireq,
			,
			EItemCriteriaOperator,
			float,
			bool		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemCriteria(ireq, , EItemCriteriaOperator, float, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SendNewItemRequest ( HNewItemRequest ireq )	{
		char log[1024];
		sprintf(log,"SendNewItemRequest() ireq=0x%X ",
			ireq		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SendNewItemRequest(ireq);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GrantItemToUser ( ItemID item,  CSteamID steamid )	{
		char log[1024];
		sprintf(log,"GrantItemToUser() item=0x%X steamid=0x%X ",
			item,
			steamid		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GrantItemToUser(item, steamid);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DeleteTemporaryItem ( ItemID item )	{
		char log[1024];
		sprintf(log,"DeleteTemporaryItem() item=0x%X ",
			item		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DeleteTemporaryItem(item);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DeleteAllTemporaryItems ()	{
		char log[1024];
		sprintf(log,"DeleteAllTemporaryItems() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DeleteAllTemporaryItems();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
