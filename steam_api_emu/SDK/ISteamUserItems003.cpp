#include "ISteamUserItems003.h"

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
	virtual bool  GetItemIterative ( uint32 i,  ItemID *UniqueID,  uint32 *ItemType,  uint32 *ItemLevel,  EItemQuality *Quality,  uint32 *Flags,  uint32 *Quantity,  uint32 *NbOfAttribute )	{
		char log[1024];
		sprintf(log,"GetItemIterative() i=0x%X UniqueID=0x%X ItemType=0x%X ItemLevel=0x%X Quality=0x%X Flags=0x%X Quantity=0x%X NbOfAttribute=0x%X ",
			i,
			UniqueID,
			ItemType,
			ItemLevel,
			Quality,
			Flags,
			Quantity,
			NbOfAttribute		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetItemIterative(i, UniqueID, ItemType, ItemLevel, Quality, Flags, Quantity, NbOfAttribute);
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
	virtual void  GetItemAttribute ( ItemID uniqueID,  uint32 b,  uint32 *c,  float *d )	{
		char log[1024];
		sprintf(log,"GetItemAttribute() uniqueID=0x%X b=0x%X c=0x%X d=0x%X ",
			uniqueID,
			b,
			c,
			d		);
		OutputDebugStringA(log);
		uniqueID, b, c, d);
		OutputDebugStringA("\n");
	}
	virtual void  UpdateInventoryPos ( ItemID uniqueID,  uint32 b )	{
		char log[1024];
		sprintf(log,"UpdateInventoryPos() uniqueID=0x%X b=0x%X ",
			uniqueID,
			b		);
		OutputDebugStringA(log);
		uniqueID, b);
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
	virtual SteamAPICall_t  GetItemBlob ( ItemID itemId )	{
		char log[1024];
		sprintf(log,"GetItemBlob() itemId=0x%X ",
			itemId		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetItemBlob(itemId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SetItemBlob ( ItemID itemID,  const void *blob,  uint32 )	{
		char log[1024];
		sprintf(log,"SetItemBlob() itemID=0x%X blob=0x%X uint32=0x%X ",
			itemID,
			blob,
			uint32		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SetItemBlob(itemID, blob, uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
