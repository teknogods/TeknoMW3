#include "ISteamBilling001.h"

	virtual bool  SetBillingAddress ( const char *pchName,  const char *pchAddress1,  const char *pchAddress2,  const char *pchCity,  const char *pchPostcode,  const char *pchState,  const char *pchCountry,  const char *pchPhone )	{
		char log[1024];
		sprintf(log,"SetBillingAddress() pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetBillingAddress(pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetBillingAddress ( char *pchName,  char *pchAddress1,  char *pchAddress2,  char *pchCity,  char *pchPostcode,  char *pchState,  char *pchCountry,  char *pchPhone )	{
		char log[1024];
		sprintf(log,"GetBillingAddress() pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetBillingAddress(pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetShippingAddress ( const char *pchName,  const char *pchAddress1,  const char *pchAddress2,  const char *pchCity,  const char *pchPostcode,  const char *pchState,  const char *pchCountry,  const char *pchPhone )	{
		char log[1024];
		sprintf(log,"SetShippingAddress() pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetShippingAddress(pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetShippingAddress ( char *pchName,  char *pchAddress1,  char *pchAddress2,  char *pchCity,  char *pchPostcode,  char *pchState,  char *pchCountry,  char *pchPhone )	{
		char log[1024];
		sprintf(log,"GetShippingAddress() pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetShippingAddress(pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFinalPrice ( int32 nPackageID )	{
		char log[1024];
		sprintf(log,"GetFinalPrice() nPackageID=0x%X ",
			nPackageID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFinalPrice(nPackageID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetCardInfo ( ECreditCardType eCreditCardType,  const char *pchCardNumber,  const char *pchCardHolderName,  const char *pchCardExpYear,  const char *pchCardExpMonth,  const char *pchCardCVV2 )	{
		char log[1024];
		sprintf(log,"SetCardInfo() eCreditCardType=0x%X pchCardNumber=%s pchCardHolderName=%s pchCardExpYear=%s pchCardExpMonth=%s pchCardCVV2=%s ",
			eCreditCardType,
			pchCardNumber,
			pchCardHolderName,
			pchCardExpYear,
			pchCardExpMonth,
			pchCardCVV2		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetCardInfo(eCreditCardType, pchCardNumber, pchCardHolderName, pchCardExpYear, pchCardExpMonth, pchCardCVV2);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetCardInfo ( ECreditCardType *eCreditCardType,  char *pchCardNumber,  char *pchCardHolderName,  char *pchCardExpYear,  char *pchCardExpMonth,  char *pchCardCVV2 )	{
		char log[1024];
		sprintf(log,"GetCardInfo() eCreditCardType=0x%X pchCardNumber=%s pchCardHolderName=%s pchCardExpYear=%s pchCardExpMonth=%s pchCardCVV2=%s ",
			eCreditCardType,
			pchCardNumber,
			pchCardHolderName,
			pchCardExpYear,
			pchCardExpMonth,
			pchCardCVV2		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetCardInfo(eCreditCardType, pchCardNumber, pchCardHolderName, pchCardExpYear, pchCardExpMonth, pchCardCVV2);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  Purchase ( int32 nPackageID,  int32 nExpectedCostCents,  uint64 gidCardID,  bool bStoreCardInfo )	{
		char log[1024];
		sprintf(log,"Purchase() nPackageID=0x%X nExpectedCostCents=0x%X gidCardID=0x%X bStoreCardInfo=0x%X ",
			nPackageID,
			nExpectedCostCents,
			gidCardID,
			bStoreCardInfo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->Purchase(nPackageID, nExpectedCostCents, gidCardID, bStoreCardInfo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
