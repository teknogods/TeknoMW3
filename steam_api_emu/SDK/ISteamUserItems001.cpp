#include "ISteamUserItems001.h"

	virtual SteamAPICall_t  LoadItems ()	{
		char log[1024];
		sprintf(log,"LoadItems() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->LoadItems();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetItemCount ()	{
		char log[1024];
		sprintf(log,"GetItemCount() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetItemCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemIterative ( uint32 index,  ItemID *UniqueID,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity,  uint32 *NbOfAttribute )	{
		char log[1024];
		sprintf(log,"GetItemIterative() index=0x%X UniqueID=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X NbOfAttribute=0x%X ",
			index,
			UniqueID,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity,
			NbOfAttribute		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemIterative(index, UniqueID, ItemType, ItemLevel, Quality, Flags, Quantity, NbOfAttribute);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetItemByID ( ItemID uniqueID,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity,  uint32 *NbOfAttribute )	{
		char log[1024];
		sprintf(log,"GetItemByID() uniqueID=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X NbOfAttribute=0x%X ",
			uniqueID,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity,
			NbOfAttribute		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemByID(uniqueID, ItemType, ItemLevel, Quality, Flags, Quantity, NbOfAttribute);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  GetItemAttribute ( ItemID uniqueID,  uint32 index,  uint32 *attribId,  float *value )	{
		char log[1024];
		sprintf(log,"GetItemAttribute() uniqueID=0x%X index=0x%X attribId=0x%X value=0x%X ",
			uniqueID,
			index,
			attribId,
			value		);
		OutputDebugStringA(log);
		uniqueID, index, attribId, value);
		OutputDebugStringA("\n");
	}
	virtual void  UpdateInventoryPos ( ItemID uniqueID,  uint32 pos )	{
		char log[1024];
		sprintf(log,"UpdateInventoryPos() uniqueID=0x%X pos=0x%X ",
			uniqueID,
			pos		);
		OutputDebugStringA(log);
		uniqueID, pos);
		OutputDebugStringA("\n");
	}
	virtual void  DropItem ( ItemID itemId )	{
		char log[1024];
		sprintf(log,"DropItem() itemId=0x%X ",
			itemId		);
		OutputDebugStringA(log);
		itemId);
		OutputDebugStringA("\n");
	}
};
