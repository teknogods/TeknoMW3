#include "IClientBilling.h"

	virtual bool  PurchaseWithActivationCode ( const char *pchActivationCode )	{
		char log[1024];
		sprintf(log,"PurchaseWithActivationCode() pchActivationCode=%s ",
			pchActivationCode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->PurchaseWithActivationCode(pchActivationCode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CancelLicense ( PackageId_t packageID,  int32 nCancelReason )	{
		char log[1024];
		sprintf(log,"CancelLicense() packageID=0x%X nCancelReason=0x%X ",
			packageID,
			nCancelReason		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CancelLicense(packageID, nCancelReason);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AcknowledgePurchaseReceipt ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"AcknowledgePurchaseReceipt() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AcknowledgePurchaseReceipt(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual PackageId_t  GetLicensePackageID ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicensePackageID() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		PackageId_t  ret = m_pWrapper->GetLicensePackageID(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetLicenseTimeCreated ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseTimeCreated() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetLicenseTimeCreated(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetLicenseTimeNextProcess ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseTimeNextProcess() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetLicenseTimeNextProcess(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetLicenseMinuteLimit ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseMinuteLimit() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetLicenseMinuteLimit(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetLicenseMinutesUsed ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseMinutesUsed() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetLicenseMinutesUsed(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPaymentMethod  GetLicensePaymentMethod ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicensePaymentMethod() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		EPaymentMethod  ret = m_pWrapper->GetLicensePaymentMethod(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetLicenseFlags ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseFlags() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetLicenseFlags(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetLicensePurchaseCountryCode ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicensePurchaseCountryCode() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLicensePurchaseCountryCode(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetLicenseTerritoryCode ( uint32 nLicenseIndex )	{
		char log[1024];
		sprintf(log,"GetLicenseTerritoryCode() nLicenseIndex=0x%X ",
			nLicenseIndex		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetLicenseTerritoryCode(nLicenseIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLicenseInfo ( uint32 nLicenseIndex,  uint32 * puTimeCreated,  uint32 * puTimeNextProcess,  int32 * piMinuteLimit,  int32 * piMinutesUsed,  EPaymentMethod * pePaymentMethod,  uint32 * puFlags,  int32 * piTerritoryCode,  char * pchPurchaseCountryCode /* Use a 3 bytes buffer */)	{
		char log[1024];
		sprintf(log,"GetLicenseInfo() nLicenseIndex=0x%X puTimeCreated=0x%X puTimeNextProcess=0x%X piMinuteLimit=0x%X piMinutesUsed=0x%X pePaymentMethod=0x%X puFlags=0x%X piTerritoryCode=0x%X /=%s ",
			nLicenseIndex,
			puTimeCreated,
			puTimeNextProcess,
			piMinuteLimit,
			piMinutesUsed,
			pePaymentMethod,
			puFlags,
			piTerritoryCode,
			/		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLicenseInfo(nLicenseIndex, puTimeCreated, puTimeNextProcess, piMinuteLimit, piMinutesUsed, pePaymentMethod, puFlags, piTerritoryCode, /);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual PackageId_t  GetReceiptPackageID ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptPackageID() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		PackageId_t  ret = m_pWrapper->GetReceiptPackageID(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPurchaseStatus  GetReceiptStatus ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptStatus() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		EPurchaseStatus  ret = m_pWrapper->GetReceiptStatus(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPurchaseResultDetail  GetReceiptResultDetail ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptResultDetail() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		EPurchaseResultDetail  ret = m_pWrapper->GetReceiptResultDetail(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetReceiptTransTime ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptTransTime() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetReceiptTransTime(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetReceiptTransID ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptTransID() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetReceiptTransID(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetReceiptAcknowledged ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptAcknowledged() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetReceiptAcknowledged(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPaymentMethod  GetReceiptPaymentMethod ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptPaymentMethod() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		EPaymentMethod  ret = m_pWrapper->GetReceiptPaymentMethod(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptBaseCost ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptBaseCost() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptBaseCost(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptTotalDiscount ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptTotalDiscount() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptTotalDiscount(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptTax ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptTax() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptTax(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptShipping ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptShipping() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptShipping(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ECurrencyCode  GetReceiptCurrencyCode ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptCurrencyCode() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		ECurrencyCode  ret = m_pWrapper->GetReceiptCurrencyCode(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptCountryCode ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptCountryCode() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptCountryCode(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptErrorHeadline ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptErrorHeadline() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptErrorHeadline(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptErrorString ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptErrorString() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptErrorString(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptErrorLinkText ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptErrorLinkText() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptErrorLinkText(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptErrorLinkURL ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptErrorLinkURL() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptErrorLinkURL(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetReceiptErrorAppID ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptErrorAppID() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetReceiptErrorAppID(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumLicenses ()	{
		char log[1024];
		sprintf(log,"GetNumLicenses() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumLicenses();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumReceipts ()	{
		char log[1024];
		sprintf(log,"GetNumReceipts() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumReceipts();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  PurchaseWithMachineID ( PackageId_t packageId,  const char *pchCustomData )	{
		char log[1024];
		sprintf(log,"PurchaseWithMachineID() packageId=0x%X pchCustomData=%s ",
			packageId,
			pchCustomData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->PurchaseWithMachineID(packageId, pchCustomData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetReceiptCardInfo ( uint32 nReceiptIndex,  ECreditCardType* eCreditCardType,  char* pchCardLast4Digits,  char* pchCardHolderFirstName,  char* pchCardHolderLastName,  char* pchCardExpYear,  char* pchCardExpMonth )	{
		char log[1024];
		sprintf(log,"GetReceiptCardInfo() nReceiptIndex=0x%X eCreditCardType=0x%X pchCardLast4Digits=%s pchCardHolderFirstName=%s pchCardHolderLastName=%s pchCardExpYear=%s pchCardExpMonth=%s ",
			nReceiptIndex,
			eCreditCardType,
			pchCardLast4Digits,
			pchCardHolderFirstName,
			pchCardHolderLastName,
			pchCardExpYear,
			pchCardExpMonth		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetReceiptCardInfo(nReceiptIndex, eCreditCardType, pchCardLast4Digits, pchCardHolderFirstName, pchCardHolderLastName, pchCardExpYear, pchCardExpMonth);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetReceiptBillingAddress ( uint32 nReceiptIndex,  char* pchFirstName,  char* pchLastName,  char* pchAddress1,  char* pchAddress2,  char* pchCity,  char* pchPostcode,  char* pchState,  char* pchCountry,  char* pchPhone )	{
		char log[1024];
		sprintf(log,"GetReceiptBillingAddress() nReceiptIndex=0x%X pchFirstName=%s pchLastName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			nReceiptIndex,
			pchFirstName,
			pchLastName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetReceiptBillingAddress(nReceiptIndex, pchFirstName, pchLastName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptLineItemCount ( uint32 nReceiptIndex )	{
		char log[1024];
		sprintf(log,"GetReceiptLineItemCount() nReceiptIndex=0x%X ",
			nReceiptIndex		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptLineItemCount(nReceiptIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetReceiptLineItemInfo ( uint32 nReceiptIndex,  uint32 nLineItemIndex,  PackageId_t *nPackageID,  uint32 *nBaseCost,  uint32 *nDiscount,  uint32 *nTax,  uint32 *nShipping,  ECurrencyCode *eCurrencyCode,  AppId_t *punAppId,  char *pchDescription )	{
		char log[1024];
		sprintf(log,"GetReceiptLineItemInfo() nReceiptIndex=0x%X nLineItemIndex=0x%X nPackageID=0x%X nBaseCost=0x%X nDiscount=0x%X nTax=0x%X nShipping=0x%X eCurrencyCode=0x%X punAppId=0x%X pchDescription=%s ",
			nReceiptIndex,
			nLineItemIndex,
			nPackageID,
			nBaseCost,
			nDiscount,
			nTax,
			nShipping,
			eCurrencyCode,
			punAppId,
			pchDescription		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetReceiptLineItemInfo(nReceiptIndex, nLineItemIndex, nPackageID, nBaseCost, nDiscount, nTax, nShipping, eCurrencyCode, punAppId, pchDescription);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  EnableTestLicense ( PackageId_t unPackageID )	{
		char log[1024];
		sprintf(log,"EnableTestLicense() unPackageID=0x%X ",
			unPackageID		);
		OutputDebugStringA(log);
		unPackageID);
		OutputDebugStringA("\n");
	}
	virtual void  DisableTestLicense ( PackageId_t unPackageID )	{
		char log[1024];
		sprintf(log,"DisableTestLicense() unPackageID=0x%X ",
			unPackageID		);
		OutputDebugStringA(log);
		unPackageID);
		OutputDebugStringA("\n");
	}
	virtual bool  ActivateOEMTicket ( const char *pchOEMLicenseFile )	{
		char log[1024];
		sprintf(log,"ActivateOEMTicket() pchOEMLicenseFile=%s ",
			pchOEMLicenseFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ActivateOEMTicket(pchOEMLicenseFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLicenseForAppID ( AppId_t unAppId,  PackageId_t * punPackageID )	{
		char log[1024];
		sprintf(log,"GetLicenseForAppID() unAppId=0x%X punPackageID=0x%X ",
			unAppId,
			punPackageID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLicenseForAppID(unAppId, punPackageID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetPackageName ( PackageId_t unPackageID,  char *pchName,  int32 cubName )	{
		char log[1024];
		sprintf(log,"GetPackageName() unPackageID=0x%X pchName=%s cubName=0x%X ",
			unPackageID,
			pchName,
			cubName		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetPackageName(unPackageID, pchName, cubName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetPackageInfo ( PackageId_t unPackageID,  uint32 * puNumAppIds,  uint32 * puNumDepotIDs,  EBillingType * peBillingType,  ELicenseType * peLicenseType,  EPackageStatus * pePackageStatus,  int32 * piCodeClass,  int32 * piGameCode,  int32 * piTerritoryCode,  bool *pbRequiresShipping,  bool *pbIsPreorder )	{
		char log[1024];
		sprintf(log,"GetPackageInfo() unPackageID=0x%X puNumAppIds=0x%X puNumDepotIDs=0x%X peBillingType=0x%X peLicenseType=0x%X pePackageStatus=0x%X piCodeClass=0x%X piGameCode=0x%X piTerritoryCode=0x%X pbRequiresShipping=0x%X pbIsPreorder=0x%X ",
			unPackageID,
			puNumAppIds,
			puNumDepotIDs,
			peBillingType,
			peLicenseType,
			pePackageStatus,
			piCodeClass,
			piGameCode,
			piTerritoryCode,
			pbRequiresShipping,
			pbIsPreorder		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetPackageInfo(unPackageID, puNumAppIds, puNumDepotIDs, peBillingType, peLicenseType, pePackageStatus, piCodeClass, piGameCode, piTerritoryCode, pbRequiresShipping, pbIsPreorder);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAppsInPackage ( PackageId_t unPackageID,  AppId_t* puIds,  uint32 uMaxIds,  bool bExcludeDepots,  bool bExcludeApps )	{
		char log[1024];
		sprintf(log,"GetAppsInPackage() unPackageID=0x%X puIds=0x%X uMaxIds=0x%X bExcludeDepots=0x%X bExcludeApps=0x%X ",
			unPackageID,
			puIds,
			uMaxIds,
			bExcludeDepots,
			bExcludeApps		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppsInPackage(unPackageID, puIds, uMaxIds, bExcludeDepots, bExcludeApps);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetPackageExtendedInfo ( PackageId_t unPackageID,  uint8 *pubData,  int32 cubData,  bool bUseSymbolsAsKeys )	{
		char log[1024];
		sprintf(log,"GetPackageExtendedInfo() unPackageID=0x%X pubData=0x%X cubData=0x%X bUseSymbolsAsKeys=0x%X ",
			unPackageID,
			pubData,
			cubData,
			bUseSymbolsAsKeys		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetPackageExtendedInfo(unPackageID, pubData, cubData, bUseSymbolsAsKeys);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestFreeLicenseForApp ( AppId_t unAppId )	{
		char log[1024];
		sprintf(log,"RequestFreeLicenseForApp() unAppId=0x%X ",
			unAppId		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestFreeLicenseForApp(unAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
