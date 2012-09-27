#include "ISteam2Bridge001.h"

class ISteam2Bridge001_wrapper
{
public:
	virtual void  SetSteam2Ticket ( uint8 *pubTicket,  int cubTicket )	{
		char log[1024];
		sprintf(log,"SetSteam2Ticket() pubTicket=0x%X cubTicket=0x%X ",
			pubTicket,
			cubTicket		);
		OutputDebugStringA(log);
		pubTicket, cubTicket);
		OutputDebugStringA("\n");
	}
	virtual bool  SetAccountName ( const char *szName )	{
		char log[1024];
		sprintf(log,"SetAccountName() szName=%s ",
			szName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAccountName(szName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetPassword ( const char *szPassword )	{
		char log[1024];
		sprintf(log,"SetPassword() szPassword=%s ",
			szPassword		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetPassword(szPassword);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetAccountCreationTime ( RTime32 creationTime )	{
		char log[1024];
		sprintf(log,"SetAccountCreationTime() creationTime=0x%X ",
			creationTime		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAccountCreationTime(creationTime);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  CreateProcess ( void *lpVACBlob,  uint32 cbBlobSize,  char const *,  char *,  uint32  void *,  char *,  uint32 )	{
		char log[1024];
		sprintf(log,"CreateProcess() lpVACBlob=0x%X cbBlobSize=0x%X =%s =%s uint32=0x%X =0x%X =%s uint32=0x%X ",
			lpVACBlob,
			cbBlobSize,
			,
			,
			uint32			,
			,
			uint32		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->CreateProcess(lpVACBlob, cbBlobSize, , , uint32, , uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EUniverse  GetConnectedUniverse ()	{
		char log[1024];
		sprintf(log,"GetConnectedUniverse() "		);
		OutputDebugStringA(log);
		EUniverse  ret = m_pWrapper->GetConnectedUniverse();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetIPCountry ()	{
		char log[1024];
		sprintf(log,"GetIPCountry() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetIPCountry();
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
	virtual RTime32  GetLicenseTimeNextProcess ( uint32 licenseId )	{
		char log[1024];
		sprintf(log,"GetLicenseTimeNextProcess() licenseId=0x%X ",
			licenseId		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetLicenseTimeNextProcess(licenseId);
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
	virtual bool  SetOfflineMode ( bool offlineMode )	{
		char log[1024];
		sprintf(log,"SetOfflineMode() offlineMode=0x%X ",
			offlineMode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetOfflineMode(offlineMode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
