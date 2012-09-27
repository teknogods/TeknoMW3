// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Win32Apis.cs" company="">
//   
// </copyright>
// <summary>
//   TODO: Update summary.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.Runtime.InteropServices;

    /// <summary>
    /// TODO: Update summary.
    /// </summary>
    public static class Win32Apis
    {
        #region Delegates

        /// <summary>
        /// The thread proc.
        /// </summary>
        /// <param name="param">
        /// The param.
        /// </param>
        public delegate int ThreadProc(IntPtr param);

        #endregion

        #region Enums

        /// <summary>
        /// The allocation type.
        /// </summary>
        [Flags]
        public enum AllocationType : uint
        {
            /// <summary>
            /// The commit.
            /// </summary>
            COMMIT = 0x1000, 

            /// <summary>
            /// The reserve.
            /// </summary>
            RESERVE = 0x2000, 

            /// <summary>
            /// The reset.
            /// </summary>
            RESET = 0x80000, 

            /// <summary>
            /// The larg e_ pages.
            /// </summary>
            LARGE_PAGES = 0x20000000, 

            /// <summary>
            /// The physical.
            /// </summary>
            PHYSICAL = 0x400000, 

            /// <summary>
            /// The to p_ down.
            /// </summary>
            TOP_DOWN = 0x100000, 

            /// <summary>
            /// The writ e_ watch.
            /// </summary>
            WRITE_WATCH = 0x200000
        }

        /// <summary>
        /// The memory protection.
        /// </summary>
        [Flags]
        public enum MemoryProtection : uint
        {
            /// <summary>
            /// The execute.
            /// </summary>
            EXECUTE = 0x10, 

            /// <summary>
            /// The execut e_ read.
            /// </summary>
            EXECUTE_READ = 0x20, 

            /// <summary>
            /// The execut e_ readwrite.
            /// </summary>
            EXECUTE_READWRITE = 0x40, 

            /// <summary>
            /// The execut e_ writecopy.
            /// </summary>
            EXECUTE_WRITECOPY = 0x80, 

            /// <summary>
            /// The noaccess.
            /// </summary>
            NOACCESS = 0x01, 

            /// <summary>
            /// The readonly.
            /// </summary>
            READONLY = 0x02, 

            /// <summary>
            /// The readwrite.
            /// </summary>
            READWRITE = 0x04, 

            /// <summary>
            /// The writecopy.
            /// </summary>
            WRITECOPY = 0x08, 

            /// <summary>
            /// The guar d_ modifierflag.
            /// </summary>
            GUARD_Modifierflag = 0x100, 

            /// <summary>
            /// The nocach e_ modifierflag.
            /// </summary>
            NOCACHE_Modifierflag = 0x200, 

            /// <summary>
            /// The writecombin e_ modifierflag.
            /// </summary>
            WRITECOMBINE_Modifierflag = 0x400
        }

        /// <summary>
        /// The protection.
        /// </summary>
        public enum Protection
        {
            /// <summary>
            /// The pag e_ noaccess.
            /// </summary>
            PAGE_NOACCESS = 0x01, 

            /// <summary>
            /// The pag e_ readonly.
            /// </summary>
            PAGE_READONLY = 0x02, 

            /// <summary>
            /// The pag e_ readwrite.
            /// </summary>
            PAGE_READWRITE = 0x04, 

            /// <summary>
            /// The pag e_ writecopy.
            /// </summary>
            PAGE_WRITECOPY = 0x08, 

            /// <summary>
            /// The pag e_ execute.
            /// </summary>
            PAGE_EXECUTE = 0x10, 

            /// <summary>
            /// The pag e_ execut e_ read.
            /// </summary>
            PAGE_EXECUTE_READ = 0x20, 

            /// <summary>
            /// The pag e_ execut e_ readwrite.
            /// </summary>
            PAGE_EXECUTE_READWRITE = 0x40, 

            /// <summary>
            /// The pag e_ execut e_ writecopy.
            /// </summary>
            PAGE_EXECUTE_WRITECOPY = 0x80, 

            /// <summary>
            /// The pag e_ guard.
            /// </summary>
            PAGE_GUARD = 0x100, 

            /// <summary>
            /// The pag e_ nocache.
            /// </summary>
            PAGE_NOCACHE = 0x200, 

            /// <summary>
            /// The pag e_ writecombine.
            /// </summary>
            PAGE_WRITECOMBINE = 0x400
        }

        #endregion

        #region Public Methods

        /// <summary>
        /// The close handle.
        /// </summary>
        /// <param name="hObject">
        /// The h object.
        /// </param>
        /// <returns>
        /// The close handle.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool CloseHandle(IntPtr hObject);

        /// <summary>
        /// The create process.
        /// </summary>
        /// <param name="lpApplicationName">
        /// The lp application name.
        /// </param>
        /// <param name="lpCommandLine">
        /// The lp command line.
        /// </param>
        /// <param name="lpProcessAttributes">
        /// The lp process attributes.
        /// </param>
        /// <param name="lpThreadAttributes">
        /// The lp thread attributes.
        /// </param>
        /// <param name="bInheritHandles">
        /// The b inherit handles.
        /// </param>
        /// <param name="dwCreationFlags">
        /// The dw creation flags.
        /// </param>
        /// <param name="lpEnvironment">
        /// The lp environment.
        /// </param>
        /// <param name="lpCurrentDirectory">
        /// The lp current directory.
        /// </param>
        /// <param name="lpStartupInfo">
        /// The lp startup info.
        /// </param>
        /// <param name="lpProcessInformation">
        /// The lp process information.
        /// </param>
        /// <returns>
        /// The create process.
        /// </returns>
        [DllImport("kernel32.dll")]
        public static extern bool CreateProcess(
            string lpApplicationName, 
            string lpCommandLine, 
            IntPtr lpProcessAttributes, 
            IntPtr lpThreadAttributes, 
            bool bInheritHandles, 
            uint dwCreationFlags, 
            IntPtr lpEnvironment, 
            string lpCurrentDirectory, 
            ref STARTUPINFO lpStartupInfo, 
            out PROCESS_INFORMATION lpProcessInformation);

        /// <summary>
        /// The create remote thread.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpThreadAttribute">
        /// The lp thread attribute.
        /// </param>
        /// <param name="dwStackSize">
        /// The dw stack size.
        /// </param>
        /// <param name="lpStartAddress">
        /// The lp start address.
        /// </param>
        /// <param name="lpParameter">
        /// The lp parameter.
        /// </param>
        /// <param name="dwCreationFlags">
        /// The dw creation flags.
        /// </param>
        /// <param name="lpThreadId">
        /// The lp thread id.
        /// </param>
        /// <returns>
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern IntPtr CreateRemoteThread(
            IntPtr hProcess, 
            IntPtr lpThreadAttribute, 
            IntPtr dwStackSize, 
            IntPtr lpStartAddress, 
            IntPtr lpParameter, 
            uint dwCreationFlags, 
            IntPtr lpThreadId);

        /// <summary>
        /// The get module handle.
        /// </summary>
        /// <param name="lpModuleName">
        /// The lp module name.
        /// </param>
        /// <returns>
        /// </returns>
        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string lpModuleName);

        /// <summary>
        /// The get proc address.
        /// </summary>
        /// <param name="hModule">
        /// The h module.
        /// </param>
        /// <param name="procName">
        /// The proc name.
        /// </param>
        /// <returns>
        /// </returns>
        [DllImport("kernel32", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        public static extern UIntPtr GetProcAddress(IntPtr hModule, string procName);

        /// <summary>
        /// The get thread context.
        /// </summary>
        /// <param name="hThread">
        /// The h thread.
        /// </param>
        /// <param name="lpContext">
        /// The lp context.
        /// </param>
        /// <returns>
        /// The get thread context.
        /// </returns>
        [DllImport("kernel32.dll")]
        public static extern bool GetThreadContext(IntPtr hThread, ref CONTEXT lpContext);

        /// <summary>
        /// The open process.
        /// </summary>
        /// <param name="dwDesiredAccess">
        /// The dw desired access.
        /// </param>
        /// <param name="bInheritHandle">
        /// The b inherit handle.
        /// </param>
        /// <param name="dwProcessId">
        /// The dw process id.
        /// </param>
        /// <returns>
        /// </returns>
        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(int dwDesiredAccess, bool bInheritHandle, int dwProcessId);

        /// <summary>
        /// The read process memory.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpBaseAddress">
        /// The lp base address.
        /// </param>
        /// <param name="lpBuffer">
        /// The lp buffer.
        /// </param>
        /// <param name="dwSize">
        /// The dw size.
        /// </param>
        /// <param name="lpNumberOfBytesRead">
        /// The lp number of bytes read.
        /// </param>
        /// <returns>
        /// The read process memory.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool ReadProcessMemory(
            IntPtr hProcess, IntPtr lpBaseAddress, [Out] byte[] lpBuffer, int dwSize, out int lpNumberOfBytesRead);

        /// <summary>
        /// The read process memory.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpBaseAddress">
        /// The lp base address.
        /// </param>
        /// <param name="lpBuffer">
        /// The lp buffer.
        /// </param>
        /// <param name="dwSize">
        /// The dw size.
        /// </param>
        /// <param name="lpNumberOfBytesRead">
        /// The lp number of bytes read.
        /// </param>
        /// <returns>
        /// The read process memory.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool ReadProcessMemory(
            IntPtr hProcess, 
            IntPtr lpBaseAddress, 
            [Out] [MarshalAs(UnmanagedType.AsAny)] object lpBuffer, 
            int dwSize, 
            out int lpNumberOfBytesRead);

        /// <summary>
        /// The read process memory.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpBaseAddress">
        /// The lp base address.
        /// </param>
        /// <param name="lpBuffer">
        /// The lp buffer.
        /// </param>
        /// <param name="dwSize">
        /// The dw size.
        /// </param>
        /// <param name="lpNumberOfBytesRead">
        /// The lp number of bytes read.
        /// </param>
        /// <returns>
        /// The read process memory.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool ReadProcessMemory(
            IntPtr hProcess, IntPtr lpBaseAddress, IntPtr lpBuffer, int dwSize, out int lpNumberOfBytesRead);

        /// <summary>
        /// The resume thread.
        /// </summary>
        /// <param name="hThread">
        /// The h thread.
        /// </param>
        /// <returns>
        /// The resume thread.
        /// </returns>
        [DllImport("kernel32.dll")]
        public static extern uint ResumeThread(IntPtr hThread);

        /// <summary>
        /// The terminate process.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="uExitCode">
        /// The u exit code.
        /// </param>
        /// <returns>
        /// The terminate process.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool TerminateProcess(IntPtr hProcess, uint uExitCode);

        /// <summary>
        /// The virtual alloc ex.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpAddress">
        /// The lp address.
        /// </param>
        /// <param name="dwSize">
        /// The dw size.
        /// </param>
        /// <param name="flAllocationType">
        /// The fl allocation type.
        /// </param>
        /// <param name="flProtect">
        /// The fl protect.
        /// </param>
        /// <returns>
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        public static extern IntPtr VirtualAllocEx(
            IntPtr hProcess, IntPtr lpAddress, uint dwSize, AllocationType flAllocationType, MemoryProtection flProtect);

        /// <summary>
        /// The virtual protect ex.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpAddress">
        /// The lp address.
        /// </param>
        /// <param name="dwSize">
        /// The dw size.
        /// </param>
        /// <param name="flNewProtect">
        /// The fl new protect.
        /// </param>
        /// <param name="lpflOldProtect">
        /// The lpfl old protect.
        /// </param>
        /// <returns>
        /// The virtual protect ex.
        /// </returns>
        [DllImport("kernel32.dll")]
        public static extern bool VirtualProtectEx(
            IntPtr hProcess, IntPtr lpAddress, UIntPtr dwSize, uint flNewProtect, out uint lpflOldProtect);


        [StructLayout(LayoutKind.Sequential)]
        public struct BLOB
        {
            public int cbData;
            public IntPtr pbData;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CRYPT_ALGORITHM_IDENTIFIER
        {
            public String pszObjId;
            BLOB Parameters;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CERT_ID
        {
            public int dwIdChoice;
            public BLOB IssuerSerialNumberOrKeyIdOrHashId;
        }

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct SIGNER_SUBJECT_INFO
        {
            /// DWORD->unsigned int
            public uint cbSize;

            /// DWORD*
            public System.IntPtr pdwIndex;

            /// DWORD->unsigned int
            public uint dwSubjectChoice;

            /// SubjectChoiceUnion
            public SubjectChoiceUnion Union1;
        }

        [StructLayoutAttribute(LayoutKind.Explicit)]
        public struct SubjectChoiceUnion
        {

            /// SIGNER_FILE_INFO*
            [FieldOffsetAttribute(0)]
            public System.IntPtr pSignerFileInfo;

            /// SIGNER_BLOB_INFO*
            [FieldOffsetAttribute(0)]
            public System.IntPtr pSignerBlobInfo;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CERT_NAME_BLOB
        {
            public uint cbData;
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)]
            public byte[] pbData;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CRYPT_INTEGER_BLOB
        {
            public UInt32 cbData;
            public IntPtr pbData;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CRYPT_ATTR_BLOB
        {
            public uint cbData;
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0)]
            public byte[] pbData;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CRYPT_ATTRIBUTE
        {
            [MarshalAs(UnmanagedType.LPStr)]
            public string pszObjId;
            public uint cValue;
            [MarshalAs(UnmanagedType.LPStruct)]
            public CRYPT_ATTR_BLOB rgValue;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CMSG_SIGNER_INFO
        {
            public int dwVersion;
            private CERT_NAME_BLOB Issuer;
            CRYPT_INTEGER_BLOB SerialNumber;
            CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
            CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
            BLOB EncryptedHash;
            CRYPT_ATTRIBUTE[] AuthAttrs;
            CRYPT_ATTRIBUTE[] UnauthAttrs;
        }

        [DllImport("crypt32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern Boolean CryptQueryObject(
            int dwObjectType,
            IntPtr pvObject,
            int dwExpectedContentTypeFlags,
            int dwExpectedFormatTypeFlags,
            int dwFlags,
            out int pdwMsgAndCertEncodingType,
            out int pdwContentType,
            out int pdwFormatType,
            ref IntPtr phCertStore,
            ref IntPtr phMsg,
            ref IntPtr ppvContext);


        [DllImport("crypt32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern Boolean CryptMsgGetParam(
            IntPtr hCryptMsg,
            int dwParamType,
            int dwIndex,
            IntPtr pvData,
            ref int pcbData
        );

        [DllImport("crypt32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern Boolean CryptMsgGetParam(
            IntPtr hCryptMsg,
            int dwParamType,
            int dwIndex,
            [In, Out] byte[] vData,
            ref int pcbData
        );

        [DllImport("crypt32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool CryptDecodeObject(
          uint CertEncodingType,
          UIntPtr lpszStructType,
          byte[] pbEncoded,
          uint cbEncoded,
          uint flags,
          [In, Out] byte[] pvStructInfo,
          ref uint cbStructInfo);


        public const int CRYPT_ASN_ENCODING = 0x00000001;
        public const int CRYPT_NDR_ENCODING = 0x00000002;
        public const int X509_ASN_ENCODING = 0x00000001;
        public const int X509_NDR_ENCODING = 0x00000002;
        public const int PKCS_7_ASN_ENCODING = 0x00010000;
        public const int PKCS_7_NDR_ENCODING = 0x00020000;

        public static UIntPtr PKCS7_SIGNER_INFO = new UIntPtr(500);
        public static UIntPtr CMS_SIGNER_INFO = new UIntPtr(501);

        public static string szOID_RSA_signingTime = "1.2.840.113549.1.9.5";
        public static string szOID_RSA_counterSign = "1.2.840.113549.1.9.6";

        //+-------------------------------------------------------------------------
        //  Get parameter types and their corresponding data structure definitions.
        //--------------------------------------------------------------------------
        public const int CMSG_TYPE_PARAM = 1;
        public const int CMSG_CONTENT_PARAM = 2;
        public const int CMSG_BARE_CONTENT_PARAM = 3;
        public const int CMSG_INNER_CONTENT_TYPE_PARAM = 4;
        public const int CMSG_SIGNER_COUNT_PARAM = 5;
        public const int CMSG_SIGNER_INFO_PARAM = 6;
        public const int CMSG_SIGNER_CERT_INFO_PARAM = 7;
        public const int CMSG_SIGNER_HASH_ALGORITHM_PARAM = 8;
        public const int CMSG_SIGNER_AUTH_ATTR_PARAM = 9;
        public const int CMSG_SIGNER_UNAUTH_ATTR_PARAM = 10;
        public const int CMSG_CERT_COUNT_PARAM = 11;
        public const int CMSG_CERT_PARAM = 12;
        public const int CMSG_CRL_COUNT_PARAM = 13;
        public const int CMSG_CRL_PARAM = 14;
        public const int CMSG_ENVELOPE_ALGORITHM_PARAM = 15;
        public const int CMSG_RECIPIENT_COUNT_PARAM = 17;
        public const int CMSG_RECIPIENT_INDEX_PARAM = 18;
        public const int CMSG_RECIPIENT_INFO_PARAM = 19;
        public const int CMSG_HASH_ALGORITHM_PARAM = 20;
        public const int CMSG_HASH_DATA_PARAM = 21;
        public const int CMSG_COMPUTED_HASH_PARAM = 22;
        public const int CMSG_ENCRYPT_PARAM = 26;
        public const int CMSG_ENCRYPTED_DIGEST = 27;
        public const int CMSG_ENCODED_SIGNER = 28;
        public const int CMSG_ENCODED_MESSAGE = 29;
        public const int CMSG_VERSION_PARAM = 30;
        public const int CMSG_ATTR_CERT_COUNT_PARAM = 31;
        public const int CMSG_ATTR_CERT_PARAM = 32;
        public const int CMSG_CMS_RECIPIENT_COUNT_PARAM = 33;
        public const int CMSG_CMS_RECIPIENT_INDEX_PARAM = 34;
        public const int CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM = 35;
        public const int CMSG_CMS_RECIPIENT_INFO_PARAM = 36;
        public const int CMSG_UNPROTECTED_ATTR_PARAM = 37;
        public const int CMSG_SIGNER_CERT_ID_PARAM = 38;
        public const int CMSG_CMS_SIGNER_INFO_PARAM = 39;


        //-------------------------------------------------------------------------
        //dwObjectType for CryptQueryObject
        //-------------------------------------------------------------------------
        public const int CERT_QUERY_OBJECT_FILE = 0x00000001;
        public const int CERT_QUERY_OBJECT_BLOB = 0x00000002;

        //-------------------------------------------------------------------------
        //dwContentType for CryptQueryObject
        //-------------------------------------------------------------------------
        //encoded single certificate
        public const int CERT_QUERY_CONTENT_CERT = 1;
        //encoded single CTL
        public const int CERT_QUERY_CONTENT_CTL = 2;
        //encoded single CRL
        public const int CERT_QUERY_CONTENT_CRL = 3;
        //serialized store
        public const int CERT_QUERY_CONTENT_SERIALIZED_STORE = 4;
        //serialized single certificate
        public const int CERT_QUERY_CONTENT_SERIALIZED_CERT = 5;
        //serialized single CTL
        public const int CERT_QUERY_CONTENT_SERIALIZED_CTL = 6;
        //serialized single CRL
        public const int CERT_QUERY_CONTENT_SERIALIZED_CRL = 7;
        //a PKCS#7 signed message
        public const int CERT_QUERY_CONTENT_PKCS7_SIGNED = 8;
        //a PKCS#7 message, such as enveloped message.  But it is not a signed message,
        public const int CERT_QUERY_CONTENT_PKCS7_UNSIGNED = 9;
        //a PKCS7 signed message embedded in a file
        public const int CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED = 10;
        //an encoded PKCS#10
        public const int CERT_QUERY_CONTENT_PKCS10 = 11;
        //an encoded PKX BLOB
        public const int CERT_QUERY_CONTENT_PFX = 12;
        //an encoded CertificatePair (contains forward and/or reverse cross certs)
        public const int CERT_QUERY_CONTENT_CERT_PAIR = 13;

        //-------------------------------------------------------------------------
        //dwExpectedConentTypeFlags for CryptQueryObject
        //-------------------------------------------------------------------------
        //encoded single certificate
        public const int CERT_QUERY_CONTENT_FLAG_CERT = (1 << CERT_QUERY_CONTENT_CERT);

        //encoded single CTL
        public const int CERT_QUERY_CONTENT_FLAG_CTL = (1 << CERT_QUERY_CONTENT_CTL);

        //encoded single CRL
        public const int CERT_QUERY_CONTENT_FLAG_CRL = (1 << CERT_QUERY_CONTENT_CRL);

        //serialized store
        public const int CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE = (1 << CERT_QUERY_CONTENT_SERIALIZED_STORE);

        //serialized single certificate
        public const int CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT = (1 << CERT_QUERY_CONTENT_SERIALIZED_CERT);

        //serialized single CTL
        public const int CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL = (1 << CERT_QUERY_CONTENT_SERIALIZED_CTL);

        //serialized single CRL
        public const int CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL = (1 << CERT_QUERY_CONTENT_SERIALIZED_CRL);

        //an encoded PKCS#7 signed message
        public const int CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED = (1 << CERT_QUERY_CONTENT_PKCS7_SIGNED);

        //an encoded PKCS#7 message.  But it is not a signed message
        public const int CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED = (1 << CERT_QUERY_CONTENT_PKCS7_UNSIGNED);

        //the content includes an embedded PKCS7 signed message
        public const int CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED = (1 << CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED);

        //an encoded PKCS#10
        public const int CERT_QUERY_CONTENT_FLAG_PKCS10 = (1 << CERT_QUERY_CONTENT_PKCS10);

        //an encoded PFX BLOB
        public const int CERT_QUERY_CONTENT_FLAG_PFX = (1 << CERT_QUERY_CONTENT_PFX);

        //an encoded CertificatePair (contains forward and/or reverse cross certs)
        public const int CERT_QUERY_CONTENT_FLAG_CERT_PAIR = (1 << CERT_QUERY_CONTENT_CERT_PAIR);

        //content can be any type
        public const int CERT_QUERY_CONTENT_FLAG_ALL =
            CERT_QUERY_CONTENT_FLAG_CERT |
            CERT_QUERY_CONTENT_FLAG_CTL |
            CERT_QUERY_CONTENT_FLAG_CRL |
            CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE |
            CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT |
            CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL |
            CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL |
            CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED |
            CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED |
            CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED |
            CERT_QUERY_CONTENT_FLAG_PKCS10 |
            CERT_QUERY_CONTENT_FLAG_PFX |
            CERT_QUERY_CONTENT_FLAG_CERT_PAIR;

        //-------------------------------------------------------------------------
        //dwFormatType for CryptQueryObject
        //-------------------------------------------------------------------------
        //the content is in binary format
        public const int CERT_QUERY_FORMAT_BINARY = 1;

        //the content is base64 encoded
        public const int CERT_QUERY_FORMAT_BASE64_ENCODED = 2;

        //the content is ascii hex encoded with "{ASN}" prefix
        public const int CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED = 3;

        //-------------------------------------------------------------------------
        //dwExpectedFormatTypeFlags for CryptQueryObject
        //-------------------------------------------------------------------------
        //the content is in binary format
        public const int CERT_QUERY_FORMAT_FLAG_BINARY = (1 << CERT_QUERY_FORMAT_BINARY);

        //the content is base64 encoded
        public const int CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED = (1 << CERT_QUERY_FORMAT_BASE64_ENCODED);

        //the content is ascii hex encoded with "{ASN}" prefix
        public const int CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED = (1 << CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED);

        //the content can be of any format
        public const int CERT_QUERY_FORMAT_FLAG_ALL =
            CERT_QUERY_FORMAT_FLAG_BINARY |
            CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED |
            CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED;

        /// <summary>
        /// The write process memory.
        /// </summary>
        /// <param name="hProcess">
        /// The h process.
        /// </param>
        /// <param name="lpBaseAddress">
        /// The lp base address.
        /// </param>
        /// <param name="lpBuffer">
        /// The lp buffer.
        /// </param>
        /// <param name="nSize">
        /// The n size.
        /// </param>
        /// <param name="lpNumberOfBytesWritten">
        /// The lp number of bytes written.
        /// </param>
        /// <returns>
        /// The write process memory.
        /// </returns>
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool WriteProcessMemory(
            IntPtr hProcess, IntPtr lpBaseAddress, byte[] lpBuffer, uint nSize, out UIntPtr lpNumberOfBytesWritten);

        [DllImport("kernel32.dll")]
        public static extern bool TerminateThread(IntPtr hThread, uint dwExitCode);

        #endregion
    }
}