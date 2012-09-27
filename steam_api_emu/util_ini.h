#ifndef UTIL_INI_H
#define UTIL_INI_H
class CIniWriter
{
public:
 CIniWriter(char* szFileName); 
 void WriteInteger(char* szSection, char* szKey, int iValue);
 void WriteFloat(char* szSection, char* szKey, float fltValue);
 void WriteBoolean(char* szSection, char* szKey, bool bolValue);
 void WriteString(char* szSection, char* szKey, char* szValue);
private:
 char m_szFileName[255];
};


class CIniReader
{
public:
 CIniReader(char* szFileName); 
 int ReadInteger(char* szSection, char* szKey, int iDefaultValue);
 float ReadFloat(char* szSection, char* szKey, float fltDefaultValue);
 bool ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue);
 char* ReadString(char* szSection, char* szKey, const char* szDefaultValue);
private:
  char m_szFileName[255];
};
#endif 