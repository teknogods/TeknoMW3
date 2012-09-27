//
// Developed by kirants @ codeguru.com
// http://www.codeguru.com/cpp/misc/misc/tools/article.php/c12347#SMBIOS
//
#pragma once
#define _WIN32_DCOM
#include "stdafx.h"
#include <windows.h>
//
//struct EnumTableStruct
//{
//	DWORD	dwOffsetOfTableFromBeginning;
//	DWORD	dwTableSize;
//	DWORD	dwIndex;
//	DWORD	dwTableType;
//};

//typedef void	(*ENUMPROC)(DWORD dwParam, EnumTableStruct* pstEnumTableStruct);

struct SMBiosHeader
{
	BYTE	bySection;
	BYTE	byLength;	
	WORD	wHandle;
};

struct SMBios_TypeBase
{
	SMBiosHeader	stHeader;
};
//
//struct SMBios_TYPE0 : public SMBios_TypeBase
//{
//	BYTE			byVendor;
//	BYTE			byBiosVersion;
//	WORD			wBIOSStartingSegment;
//	BYTE			byBIOSReleaseDate;
//	BYTE			byBIOSROMSize;
//	BYTE			qwBIOSCharacteristics[8];
//	BYTE			byExtensionByte1;
//	BYTE			byExtensionByte2;
//	BYTE			bySystemBIOSMajorRelease;
//	BYTE			bySystemBIOSMinorRelease;
//	BYTE			byEmbeddedFirmwareMajorRelease;
//	BYTE			byEmbeddedFirmwareMinorRelease;
//	char*			szVendor;
//	char*			szBIOSVersion;
//	char*			szBIOSReleaseDate;
//};
//
//struct SMBios_TYPE1 : public SMBios_TypeBase
//{
//	BYTE			byManufacturer;
//	BYTE			byProductName;
//	BYTE			byVersion;
//	BYTE			bySerialNumber;
//	BYTE			byUUID[16];
//	BYTE			byWakeupType;
//	BYTE			bySKUNumber;
//	BYTE			byFamily;
//	char*			szManufacturer;
//	char*			szProductName;
//	char*			szVersion;
//	char*			szSerialNumber;
//	char*			szSKUNumber;
//	char*			szFamily;
//};
//
//struct SMBios_TYPE2 : public SMBios_TypeBase
//{
//	BYTE			byManufacturer;
//	BYTE			byProductName;
//	BYTE			byVersion;
//	BYTE			bySerialNumber;
//	BYTE			byAssetTag;
//	BYTE			byFeatureFlags;
//	BYTE			byLocationInChassis;
//	WORD			wChassisHandle;
//	BYTE			byBoardType;
//	BYTE			byNoOfContainedObjectHandles;
//	WORD*			ContainedObjectHandles[255];
//	char*			szManufacturer;
//	char*			szProductName;
//	char*			szVersion;
//	char*			szSerialNumber;
//	char*			szAssetTag;
//	char*			szLocationInChassis;
//};
//
//struct SMBios_TYPE3 : public SMBios_TypeBase
//{
//	BYTE			byManufacturer;
//	BYTE			byType;
//	BYTE			byVersion;
//	BYTE			bySerialNumber;
//	BYTE			byAssetTag;
//	BYTE			byBootupState;
//	BYTE			byPowerSupplyState;
//	BYTE			byThermalState;
//	BYTE			bySecurityStatus;
//	DWORD			dwOEMdefined;
//	BYTE			byHeight;
//	BYTE			byNumberOfPowerCords;
//	BYTE			byContainedElementCount;
//	BYTE			byContainedElementRecordLength;
//	char*			szManufacturer;
//	char*			szVersion;
//	char*			szSerialNumber;
//	char*			szAssetTag;
//};
//
//struct SMBios_TYPE4 : public SMBios_TypeBase
//{
//	BYTE			bySocketDesignation;
//	BYTE			byProcessorType;
//	BYTE			byProcessorFamily;
//	BYTE			byProcessorManufacturer;
//	BYTE			qwProcessorID[8];
//	BYTE			byProcessorVersion;
//	BYTE			byVoltage;
//	WORD			wExternalClock;
//	WORD			wMaxSpeed;
//	WORD			wCurrentSpeed;
//	BYTE			byStatus;
//	BYTE			byProcessorUpgrade;
//	WORD			wL1CacheHandle;
//	WORD			wL2CacheHandle;
//	WORD			wL3CacheHandle;
//	BYTE			bySerialNumber;
//	BYTE			byAssetTagNumber;
//	BYTE			byPartNumber;
//	char*			szSocketDesignation;
//	char*			szProcessorManufacturer;
//	char*			szProcessorVersion;
//	char*			szSerialNumber;
//	char*			szAssetTagNumber;
//	char*			szPartNumber;
//};
//
//struct SMBios_TYPE11 : public SMBios_TypeBase
//{
//	BYTE			byCountStrings;
//	char*			szStrings[255];
//};

class SMBiosData
{
public:
	SMBiosData();
	~SMBiosData();

	BOOL FetchSMBiosData();
	//void EnumTables(DWORD dwParam, ENUMPROC pfnEnumProc);
	//BOOL GetData(SMBios_TYPE0& stSMBiosType0);
	//BOOL GetData(SMBios_TYPE1& stSMBiosType1);
	//BOOL GetData(SMBios_TYPE2& stSMBiosType2);
	//BOOL GetData(SMBios_TYPE3& stSMBiosType3);
	//BOOL GetData(SMBios_TYPE4& stSMBiosType4);
	//BOOL GetData(SMBios_TYPE11& stSMBiosType11);
	
	//BYTE*	GetTableByIndex(BYTE byIndex,DWORD& dwTotalTableSize);

	//BYTE*	GetRawData(){ return m_pbBIOSData;};
	//DWORD	GetRawDataLength(){ return m_dwLen;};


	BYTE*	GetTable(BYTE byTableType,DWORD& dwTotalTableSize);
private:
	BYTE	m_byMajorVersion;
	BYTE	m_byMinorVersion;
	BYTE*	m_pbBIOSData;
	DWORD	m_dwLen;

	BYTE*	GetNextTable(BYTE* const pbData, BOOL bIgnoreTableType, BYTE byTableType,DWORD& dwTotalTableSize);
	//char*	GetString(BYTE* const pbData,BYTE byIndex);
};

