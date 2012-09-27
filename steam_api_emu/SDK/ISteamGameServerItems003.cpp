#include "ISteamGameServerItems003.h"

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
	virtual bool  GetItemIterative ( CSteamID steamid,  uint32 i,  ItemID *UniqueID,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity,  uint32 *NbOfAttribute )	{
		char log[1024];
		sprintf(log,"GetItemIterative() steamid=0x%X i=0x%X UniqueID=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X NbOfAttribute=0x%X ",
			steamid,
			i,
			UniqueID,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity,
			NbOfAttribute		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemIterative(steamid, i, UniqueID, ItemType, ItemLevel, Quality, Flags, Quantity, NbOfAttribute);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemByID ( ItemID itemid,  CSteamID* steamid,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity,  uint32 *NbOfAttribute )	{
		char log[1024];
		sprintf(log,"GetItemByID() itemid=0x%X steamid=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X NbOfAttribute=0x%X ",
			itemid,
			steamid,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity,
			NbOfAttribute		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemByID(itemid, steamid, ItemType, ItemLevel, Quality, Flags, Quantity, NbOfAttribute);
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
	virtual HNewItemRequest  CreateNewItemRequest ( CSteamID steamid )	{
		char log[1024];
		sprintf(log,"CreateNewItemRequest() steamid=0x%X ",
			steamid		);
		OutputDebugStringA(log);
		HNewItemRequest  ret = m_pWrapper->CreateNewItemRequest(steamid);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemLevel ( HNewItemRequest ireq,  uint32 level )	{
		char log[1024];
		sprintf(log,"AddNewItemLevel() ireq=0x%X level=0x%X ",
			ireq,
			level		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemLevel(ireq, level);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemQuality ( HNewItemRequest ireq,  EItemQuality quality )	{
		char log[1024];
		sprintf(log,"AddNewItemQuality() ireq=0x%X quality=0x%X ",
			ireq,
			quality		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemQuality(ireq, quality);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetNewItemInitialInventoryPos ( HNewItemRequest ireq,  uint32 pos )	{
		char log[1024];
		sprintf(log,"SetNewItemInitialInventoryPos() ireq=0x%X pos=0x%X ",
			ireq,
			pos		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetNewItemInitialInventoryPos(ireq, pos);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetNewItemInitialQuantity ( HNewItemRequest ireq,  uint32 quantity )	{
		char log[1024];
		sprintf(log,"SetNewItemInitialQuantity() ireq=0x%X quantity=0x%X ",
			ireq,
			quantity		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetNewItemInitialQuantity(ireq, quantity);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemCriteria ( HNewItemRequest ireq,  const char* key,  EItemCriteriaOperator criteria,  const char* value,  bool unkn )	{
		char log[1024];
		sprintf(log,"AddNewItemCriteria() ireq=0x%X key=%s criteria=0x%X value=%s unkn=0x%X ",
			ireq,
			key,
			criteria,
			value,
			unkn		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemCriteria(ireq, key, criteria, value, unkn);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddNewItemCriteria ( HNewItemRequest ireq,  const char* key,  EItemCriteriaOperator criteria,  float value,  bool unkn )	{
		char log[1024];
		sprintf(log,"AddNewItemCriteria() ireq=0x%X key=%s criteria=0x%X value=0x%X unkn=0x%X ",
			ireq,
			key,
			criteria,
			value,
			unkn		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddNewItemCriteria(ireq, key, criteria, value, unkn);
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
	virtual SteamAPICall_t  UpdateQuantity ( ItemID item,  uint32 quantity )	{
		char log[1024];
		sprintf(log,"UpdateQuantity() item=0x%X quantity=0x%X ",
			item,
			quantity		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UpdateQuantity(item, quantity);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetItemBlob ( ItemID item )	{
		char log[1024];
		sprintf(log,"GetItemBlob() item=0x%X ",
			item		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetItemBlob(item);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SetItemBlob ( ItemID item,  void const* blob,  uint32 size )	{
		char log[1024];
		sprintf(log,"SetItemBlob() item=0x%X blob=0x%X size=0x%X ",
			item,
			blob,
			size		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SetItemBlob(item, blob, size);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
