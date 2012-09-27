#include "ISteamBilling002.h"

	virtual unknown_ret  InitCreditCardPurchase ( int,  uint32,  bool )	{
		char log[1024];
		sprintf(log,"InitCreditCardPurchase() int=0x%X uint32=0x%X bool=0x%X ",
			int,
			uint32,
			bool		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->InitCreditCardPurchase(int, uint32, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  InitPayPalPurchase ( int )	{
		char log[1024];
		sprintf(log,"InitPayPalPurchase() int=0x%X ",
			int		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->InitPayPalPurchase(int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetActivationCodeInfo ( const char* )	{
		char log[1024];
		sprintf(log,"GetActivationCodeInfo() =%s ",
					);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetActivationCodeInfo();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  PurchaseWithActivationCode ( const char* )	{
		char log[1024];
		sprintf(log,"PurchaseWithActivationCode() =%s ",
					);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->PurchaseWithActivationCode();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetFinalPrice ( void )	{
		char log[1024];
		sprintf(log,"GetFinalPrice() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetFinalPrice(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  CancelPurchase ( void )	{
		char log[1024];
		sprintf(log,"CancelPurchase() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->CancelPurchase(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  CompletePurchase ( void )	{
		char log[1024];
		sprintf(log,"CompletePurchase() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->CompletePurchase(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  UpdateCardInfo ( uint32 )	{
		char log[1024];
		sprintf(log,"UpdateCardInfo() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->UpdateCardInfo(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  DeleteCard ( uint32 )	{
		char log[1024];
		sprintf(log,"DeleteCard() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->DeleteCard(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetCardList ( void )	{
		char log[1024];
		sprintf(log,"GetCardList() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetCardList(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetLicenses ( void )	{
		char log[1024];
		sprintf(log,"GetLicenses() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetLicenses(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  CancelLicense ( int,  int )	{
		char log[1024];
		sprintf(log,"CancelLicense() int=0x%X int=0x%X ",
			int,
			int		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->CancelLicense(int, int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetPurchaseReceipts ( bool )	{
		char log[1024];
		sprintf(log,"GetPurchaseReceipts() bool=0x%X ",
			bool		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetPurchaseReceipts(bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  AcknowledgePurchaseReceipt ( uint32 )	{
		char log[1024];
		sprintf(log,"AcknowledgePurchaseReceipt() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->AcknowledgePurchaseReceipt(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetBillingAddress ( uint32,  const char *pchName,  const char *pchAddress1,  const char *pchAddress2,  const char *pchCity,  const char *pchPostcode,  const char *pchState,  const char *pchCountry,  const char *pchPhone)	{
		char log[1024];
		sprintf(log,"SetBillingAddress() uint32=0x%X pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			uint32,
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetBillingAddress(uint32, pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetBillingAddress ( uint32,  char *pchName,  char *pchAddress1,  char *pchAddress2,  char *pchCity,  char *pchPostcode,  char *pchState,  char *pchCountry,  char *pchPhone)	{
		char log[1024];
		sprintf(log,"GetBillingAddress() uint32=0x%X pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s ",
			uint32,
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetBillingAddress(uint32, pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetShippingAddress ( const char *pchName,  const char *pchAddress1,  const char *pchAddress2,  const char *pchCity,  const char *pchPostcode,  const char *pchState,  const char *pchCountry,  const char *pchPhone,  const char *)	{
		char log[1024];
		sprintf(log,"SetShippingAddress() pchName=%s pchAddress1=%s pchAddress2=%s pchCity=%s pchPostcode=%s pchState=%s pchCountry=%s pchPhone=%s =%s ",
			pchName,
			pchAddress1,
			pchAddress2,
			pchCity,
			pchPostcode,
			pchState,
			pchCountry,
			pchPhone,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetShippingAddress(pchName, pchAddress1, pchAddress2, pchCity, pchPostcode, pchState, pchCountry, pchPhone, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetShippingAddress ( char *pchName,  char *pchAddress1,  char *pchAddress2,  char *pchCity,  char *pchPostcode,  char *pchState,  char *pchCountry,  char *pchPhone)	{
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
	virtual bool  SetCardInfo ( uint32,  ECreditCardType eCreditCardType,  const char *pchCardNumber,  const char *pchCardHolderName,  const char *pchCardExpYear,  const char *pchCardExpMonth,  const char *pchCardCVV2,  const char *)	{
		char log[1024];
		sprintf(log,"SetCardInfo() uint32=0x%X eCreditCardType=0x%X pchCardNumber=%s pchCardHolderName=%s pchCardExpYear=%s pchCardExpMonth=%s pchCardCVV2=%s =%s ",
			uint32,
			eCreditCardType,
			pchCardNumber,
			pchCardHolderName,
			pchCardExpYear,
			pchCardExpMonth,
			pchCardCVV2,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetCardInfo(uint32, eCreditCardType, pchCardNumber, pchCardHolderName, pchCardExpYear, pchCardExpMonth, pchCardCVV2, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetCardInfo ( uint32,  ECreditCardType *eCreditCardType,  char *pchCardNumber,  char *pchCardHolderName,  char *pchCardExpYear,  char *pchCardExpMonth,  char *pchCardCVV2,  char *)	{
		char log[1024];
		sprintf(log,"GetCardInfo() uint32=0x%X eCreditCardType=0x%X pchCardNumber=%s pchCardHolderName=%s pchCardExpYear=%s pchCardExpMonth=%s pchCardCVV2=%s =%s ",
			uint32,
			eCreditCardType,
			pchCardNumber,
			pchCardHolderName,
			pchCardExpYear,
			pchCardExpMonth,
			pchCardCVV2,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetCardInfo(uint32, eCreditCardType, pchCardNumber, pchCardHolderName, pchCardExpYear, pchCardExpMonth, pchCardCVV2, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetLicensePackageID ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicensePackageID() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetLicensePackageID(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetLicenseTimeCreated ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseTimeCreated() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetLicenseTimeCreated(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetLicenseTimeNextProcess ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseTimeNextProcess() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetLicenseTimeNextProcess(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetLicenseMinuteLimit ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseMinuteLimit() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetLicenseMinuteLimit(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetLicenseMinutesUsed ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseMinutesUsed() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetLicenseMinutesUsed(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPaymentMethod  GetLicensePaymentMethod ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicensePaymentMethod() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		EPaymentMethod  ret = m_pWrapper->GetLicensePaymentMethod(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ELicenseFlags  GetLicenseFlags ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseFlags() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		ELicenseFlags  ret = m_pWrapper->GetLicenseFlags(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetLicensePurchaseCountryCode ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicensePurchaseCountryCode() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLicensePurchaseCountryCode(licenseId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetReceiptPackageID ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptPackageID() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetReceiptPackageID(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetReceiptStatus ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptStatus() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetReceiptStatus(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetReceiptResultDetail ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptResultDetail() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetReceiptResultDetail(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetReceiptTransTime ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptTransTime() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetReceiptTransTime(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetReceiptTransID ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptTransID() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetReceiptTransID(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetReceiptAcknowledged ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptAcknowledged() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetReceiptAcknowledged(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPaymentMethod  GetReceiptPaymentMethod ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptPaymentMethod() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		EPaymentMethod  ret = m_pWrapper->GetReceiptPaymentMethod(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptBaseCost ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptBaseCost() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptBaseCost(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptTotalDiscount ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptTotalDiscount() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptTotalDiscount(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptTax ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptTax() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptTax(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetReceiptShipping ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptShipping() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetReceiptShipping(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetReceiptCountryCode ( uint32 )	{
		char log[1024];
		sprintf(log,"GetReceiptCountryCode() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetReceiptCountryCode(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumLicenses ( void )	{
		char log[1024];
		sprintf(log,"GetNumLicenses() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumLicenses(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumReceipts ( void )	{
		char log[1024];
		sprintf(log,"GetNumReceipts() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumReceipts(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  PurchaseWithMachineID ( int,  const char* )	{
		char log[1024];
		sprintf(log,"PurchaseWithMachineID() int=0x%X =%s ",
			int,
					);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->PurchaseWithMachineID(int, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  InitClickAndBuyPurchase ( int,  int64,  const char*,  const char* )	{
		char log[1024];
		sprintf(log,"InitClickAndBuyPurchase() int=0x%X int64=0x%X =%s =%s ",
			int,
			int64,
			,
					);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->InitClickAndBuyPurchase(int, int64, , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetPreviousClickAndBuyAccount ( int64 *,  char *,  char * )	{
		char log[1024];
		sprintf(log,"GetPreviousClickAndBuyAccount() =0x%X =%s =%s ",
			,
			,
					);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetPreviousClickAndBuyAccount(, , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
