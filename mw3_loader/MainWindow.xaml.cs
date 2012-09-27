// --------------------------------------------------------------------------------------------------------------------
// <copyright file="MainWindow.xaml.cs" company="">
//   
// </copyright>
// <summary>
//   Interaction logic for MainWindow.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Diagnostics;
    using System.IO;
    using System.Net;
    using System.Reflection;
    using System.Runtime.InteropServices;
    using System.Security.Cryptography;
    using System.Text;
    using System.Threading;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Input;

    using Microsoft.Win32;

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Constants and Fields

        /// <summary>
        ///   The acloc.
        /// </summary>
        private const int ACLOC = 0x1F0FFF;

        #endregion

        #region Constructors and Destructors

        /// <summary>
        ///   Initializes a new instance of the <see cref="MainWindow" /> class.
        /// </summary>
        public MainWindow()
        {
            this.InitializeComponent();

            // Insert code required on object creation below this point.
        }

        #endregion

        #region Public Methods and Operators

        /// <summary>
        /// The index of.
        /// </summary>
        /// <param name="arrayToSearchThrough">
        /// The array to search through. 
        /// </param>
        /// <param name="patternToFind">
        /// The pattern to find. 
        /// </param>
        /// <returns>
        /// The index of. 
        /// </returns>
        public static int IndexOf(byte[] arrayToSearchThrough, byte[] patternToFind)
        {
            if (patternToFind.Length > arrayToSearchThrough.Length)
            {
                return -1;
            }

            for (int i = 0; i < arrayToSearchThrough.Length - patternToFind.Length; i++)
            {
                bool found = true;
                for (int j = 0; j < patternToFind.Length; j++)
                {
                    if (arrayToSearchThrough[i + j] != patternToFind[j])
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                {
                    return i;
                }
            }

            return -1;
        }

        /// <summary>
        /// The get ip.
        /// </summary>
        /// <param name="domain">
        /// The domain. 
        /// </param>
        /// <returns>
        /// The get ip. 
        /// </returns>
        public string GetIp(string domain)
        {
            try
            {
                UriHostNameType result = Uri.CheckHostName(domain);

                if (result == UriHostNameType.Unknown || result == UriHostNameType.Basic)
                {
                    MessageBox.Show("Invalid hostname!");
                    return string.Empty;
                }

                if (result == UriHostNameType.IPv4)
                {
                    return domain;
                }

                return Dns.GetHostAddresses(domain)[0].ToString();
            }
            catch (Exception)
            {
                MessageBox.Show("Invalid hostname!");
                return string.Empty;
            }
        }

        /// <summary>
        /// The read.
        /// </summary>
        /// <param name="KeyName">
        /// The key name.
        /// </param>
        /// <returns>
        /// The read.
        /// </returns>
        public string Read(string KeyName)
        {
            // Opening the registry key
            RegistryKey rk = Registry.CurrentUser;

            // Open a subKey as read-only
            RegistryKey sk1 = rk.OpenSubKey("SOFTWARE\\Valve\\Steam\\");

            // If the RegistrySubKey doesn't exist -> (null)
            if (sk1 == null)
            {
                return null;
            }
            else
            {
                try
                {
                    // If the RegistryKey exists I get its value
                    // or null is returned.
                    return (string)sk1.GetValue(KeyName.ToUpper());
                }
                catch (Exception e)
                {
                    // AAAAAAAAAAARGH, an error!
                    return null;
                }
            }
        }

        #endregion

        #region Methods

        /// <summary>
        /// The get m d 5 hash from file.
        /// </summary>
        /// <param name="fileName">
        /// The file name. 
        /// </param>
        /// <returns>
        /// The get m d 5 hash from file. 
        /// </returns>
        protected string GetMD5HashFromFile(string fileName)
        {
            var file = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            MD5 md5 = new MD5CryptoServiceProvider();
            byte[] retVal = md5.ComputeHash(file);
            file.Close();

            var sb = new StringBuilder();
            for (int i = 0; i < retVal.Length; i++)
            {
                sb.Append(retVal[i].ToString("x2"));
            }

            return sb.ToString();
        }

        /// <summary>
        /// The check new version.
        /// </summary>
        private static void CheckNewVersion()
        {
            try
            {
                // used to build entire input
                var sb = new List<string>();

                // used on each read operation
                var buf = new byte[8192];

                // prepare the web page we will be asking for
                var request = (HttpWebRequest)WebRequest.Create("http://teknogods.com:8080/updatecheck/?project=mw3");
                var request2 = (HttpWebRequest)WebRequest.Create("http://teknogods.com/updatecheck/?project=mw3");

                HttpWebResponse response1 = TryToGetData(request);

                HttpWebResponse responsemain;

                // execute the request
                if (response1 == null)
                {
                    HttpWebResponse response2 = TryToGetData(request2);
                    if (response2 == null)
                    {
                        // Cannot connect servers.
                        return;
                    }
                    else
                    {
                        responsemain = response2;
                    }
                }
                else
                {
                    responsemain = response1;
                }

                // we will read data via the response stream
                Stream resStream = responsemain.GetResponseStream();

                string tempString = null;
                int count = 0;

                do
                {
                    // fill the buffer with data
                    count = resStream.Read(buf, 0, buf.Length);

                    // make sure we read some data
                    if (count != 0)
                    {
                        // translate from bytes to ASCII text
                        tempString = Encoding.ASCII.GetString(buf, 0, count);

                        // continue building the string
                        sb.Add(tempString);
                    }
                }
                while (count > 0); // any more data to read?

                string[] str = sb[0].Split(";".ToCharArray());
                if (str.Length != 2)
                {
                    return;
                }

                int version = Convert.ToInt32(str[0].Replace(".", string.Empty));
                string location = str[1].Replace("\r", string.Empty).Replace("\n", string.Empty);
                if (version
                    >
                    Convert.ToInt32(
                        Assembly.GetExecutingAssembly().GetName().Version.ToString().Replace(".", string.Empty)))
                {
                    MessageBoxResult result =
                        MessageBox.Show(
                            "There is a new version available: " + str[0] + Environment.NewLine
                            + "Do you want to open TeknoGods.com so you can fetch it?", 
                            "Information", 
                            MessageBoxButton.YesNo, 
                            MessageBoxImage.Question);
                    if (result == MessageBoxResult.Yes)
                    {
                        Process.Start(str[1]);
                    }
                }
            }
            catch (Exception)
            {
                return;
            }
        }

        /// <summary>
        /// The try to get data.
        /// </summary>
        /// <param name="request">
        /// The request. 
        /// </param>
        /// <returns>
        /// </returns>
        private static HttpWebResponse TryToGetData(HttpWebRequest request)
        {
            try
            {
                return (HttpWebResponse)request.GetResponse();
            }
            catch (Exception)
            {
                return null;
            }
        }

        /// <summary>
        /// The get processes.
        /// </summary>
        /// <param name="name">
        /// The name. 
        /// </param>
        /// <returns>
        /// </returns>
        private static Process[] getProcesses(string name)
        {
            name = name.Replace(".exe", string.Empty);
            Process[] ret = Process.GetProcessesByName(name);

            if (ret.Length == 0)
            {
                return null;
            }

            return ret;
        }

        /// <summary>
        /// The btc sp click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtcSpClick(object sender, RoutedEventArgs e)
        {
            this.btnMPDC.Visibility = Visibility.Hidden;
            this.btnMPLAN.Visibility = Visibility.Hidden;
            this.btcMPDedi.Visibility = Visibility.Hidden;
            this.btcSPC.Visibility = Visibility.Visible;
            this.btnSPH.Visibility = Visibility.Visible;
            this.PortBox.IsEnabled = false;
        }

        /// <summary>
        /// The btn about click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnAboutClick(object sender, RoutedEventArgs e)
        {
            var aboutBox = new AboutBox(this);
            aboutBox.ShowDialog();
        }

        /// <summary>
        /// The btn mp click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnMpClick(object sender, RoutedEventArgs e)
        {
            this.btnMPDC.Visibility = Visibility.Visible;
            this.btnMPLAN.Visibility = Visibility.Visible;
            this.btcMPDedi.Visibility = Visibility.Visible;
            this.btcSPC.Visibility = Visibility.Hidden;
            this.btnSPH.Visibility = Visibility.Hidden;
            this.PortBox.IsEnabled = true;
        }

        /// <summary>
        /// The btn mp dedi click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnMpDediClick(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(this.PortBox.Text))
            {
                MessageBox.Show(
                    "Please enter correct Port before you continue as a client!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                return;
            }

            if (!File.Exists("iw5mp_server.exe"))
            {
                MessageBox.Show("Cannot find iw5mp_server.exe");
                return;
            }

            if (this.checkBox1.IsChecked == true)
            {
                this.StartTheProcess("iw5mp_server.exe", "+usekeys +set dedicated 1 +set net_port " + this.PortBox.Text);
            }
            else
            {
                this.StartTheProcess("iw5mp_server.exe", "+set dedicated 1 +set net_port " + this.PortBox.Text);
            }
        }

        /// <summary>
        /// The btn mp lan click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnMpLanClick(object sender, RoutedEventArgs e)
        {
            if (!File.Exists("iw5mp.exe"))
            {
                MessageBox.Show("Cannot find iw5mp.exe");
                return;
            }

            if (!this.IsAssemblySigned("iw5mp.exe"))
            {
                MessageBox.Show(
                    "Modern Warfare 3 MP Assembly signature is not valid, please reinstall your game!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                this.Close();
                return;
            }

            this.StartTheProcess("iw5mp.exe", this.checkBox1.IsChecked == true ? "+usekeys" : string.Empty);
        }

        /// <summary>
        /// The btn mpdc click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnMpdcClick(object sender, RoutedEventArgs e)
        {
            if (this.IpBox.Text == "Invalid host." || string.IsNullOrWhiteSpace(this.IpBox.Text))
            {
                MessageBox.Show(
                    "Please enter correct IP before you continue as a client!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                return;
            }

            if (!File.Exists("iw5mp.exe"))
            {
                MessageBox.Show("Cannot find iw5mp.exe");
                return;
            }

            if (!this.IsAssemblySigned("iw5mp.exe"))
            {
                MessageBox.Show(
                    "Modern Warfare 3 MP Assembly signature is not valid, please reinstall your game!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                this.Close();
                return;
            }

            var ip = this.GetIp(this.IpBox.Text);

            if (ip == string.Empty)
            {
                return;
            }

            // MessageBox.Show("+server " + ip + ":" + this.PortBox.Text);
            this.StartTheProcess("iw5mp.exe", "+server " + ip + ":" + this.PortBox.Text);
        }

        /// <summary>
        /// The btn pd click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnPdClick(object sender, RoutedEventArgs e)
        {
            byte[] dllName = Encoding.ASCII.GetBytes("teknomw3.dll");
            if (
                MessageBox.Show(
                    "This is only intented if you have the game running in the backround connected to Steam and it is recommented that you are in the barracks.", 
                    "Are you sure you want to continue?", 
                    MessageBoxButton.YesNo, 
                    MessageBoxImage.Question) == MessageBoxResult.No)
            {
                return;
            }

            Process[] proc = getProcesses("iw5mp.exe");

            if (proc == null)
            {
                MessageBox.Show("Target process not found");
                return;
            }

            IntPtr ptrProc = Win32Apis.OpenProcess(ACLOC, false, proc[0].Id);

            if (ptrProc == IntPtr.Zero)
            {
                MessageBox.Show("Target process pointer is invalid");
                return;
            }

            var retLib =
                (IntPtr)((int)Win32Apis.GetProcAddress(Win32Apis.GetModuleHandle("Kernel32.dll"), "LoadLibraryA"));

            if (retLib == (IntPtr)0)
            {
                MessageBox.Show("Loadlibrary unreachable");
                return;
            }

            int objBuffer = dllName.Length + 1;
            IntPtr objPtr = Win32Apis.VirtualAllocEx(
                ptrProc, new IntPtr(0), (uint)objBuffer, (Win32Apis.AllocationType)4096, (Win32Apis.MemoryProtection)4);

            if (objPtr == (IntPtr)0)
            {
                MessageBox.Show("Virtual alloc failure");
                return;
            }

            UIntPtr byteswrite;
            bool ret = Win32Apis.WriteProcessMemory(ptrProc, objPtr, dllName, (uint)objBuffer, out byteswrite);

            if (byteswrite == (UIntPtr)0)
            {
                MessageBox.Show("Write process mem failure");
                return;
            }

            var mutex = new Mutex(false, "TeknoPDump" + (proc[0].Id ^ 0x80).ToString("X8"));
            Win32Apis.CreateRemoteThread(ptrProc, new IntPtr(0), new IntPtr(0), retLib, objPtr, 0, (IntPtr)0);
            Win32Apis.CloseHandle(ptrProc);
            Thread.Sleep(6000);
            mutex.Close();
        }

        /// <summary>
        /// The btn spc click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnSpcClick(object sender, RoutedEventArgs e)
        {
            if (this.IpBox.Text == "Invalid host." || string.IsNullOrWhiteSpace(this.IpBox.Text))
            {
                MessageBox.Show(
                    "Please enter correct IP before you continue as a client!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                return;
            }

            if (!File.Exists("iw5sp.exe"))
            {
                MessageBox.Show("Cannot find iw5sp.exe");
                return;
            }

            if (!this.IsAssemblySigned("iw5sp.exe"))
            {
                MessageBox.Show(
                    "Modern Warfare 3 SP Assembly signature is not valid, please reinstall your game!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                this.Close();
                return;
            }

            var ip = this.GetIp(this.IpBox.Text);

            if (ip == string.Empty)
            {
                return;
            }

            this.StartTheProcess("iw5sp.exe", "+server " + ip + ":0");
        }

        /// <summary>
        /// The btn sph click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void BtnSphClick(object sender, RoutedEventArgs e)
        {
            if (!File.Exists("iw5sp.exe"))
            {
                MessageBox.Show("Cannot find iw5sp.exe");
                return;
            }

            if (!this.IsAssemblySigned("iw5sp.exe"))
            {
                MessageBox.Show(
                    "Modern Warfare 3 SP Assembly signature is not valid, please reinstall your game!", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                this.Close();
                return;
            }

            this.StartTheProcess("iw5sp.exe", string.Empty);
        }

        /// <summary>
        /// The button_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var settings = new Settings();
            settings.ShowDialog();
        }

        /// <summary>
        /// The copy stream.
        /// </summary>
        /// <param name="input">
        /// The input. 
        /// </param>
        /// <param name="output">
        /// The output. 
        /// </param>
        private void CopyStream(Stream input, Stream output)
        {
            var buffer = new byte[32768];
            while (true)
            {
                int read = input.Read(buffer, 0, buffer.Length);
                if (read <= 0)
                {
                    return;
                }

                output.Write(buffer, 0, read);
            }
        }

        /// <summary>
        /// The check new version.
        /// </summary>
        private void FetchNews()
        {
            try
            {
                // used to build entire input
                var sb = new List<string>();

                // used on each read operation
                var buf = new byte[8192];

                // prepare the web page we will be asking for
                var request = (HttpWebRequest)WebRequest.Create("http://teknogods.com:8080/updatecheck/?project=news");
                var request2 = (HttpWebRequest)WebRequest.Create("http://teknogods.com/updatecheck/?project=news");

                HttpWebResponse response1 = TryToGetData(request);

                HttpWebResponse responsemain;

                // execute the request
                if (response1 == null)
                {
                    HttpWebResponse response2 = TryToGetData(request2);
                    if (response2 == null)
                    {
                        // Cannot connect servers.
                        this.NewsUrl.NavigateUri = new Uri("http://www.teknogods.com");
                        this.NewsText.Text =
                            ((AssemblyCompanyAttribute)
                             Assembly.GetCallingAssembly().GetCustomAttributes(typeof(AssemblyCompanyAttribute), false)[
                                 0]).Company + " "
                            +
                            ((AssemblyCopyrightAttribute)
                             Assembly.GetCallingAssembly().GetCustomAttributes(
                                 typeof(AssemblyCopyrightAttribute), false)[0]).Copyright;
                        return;
                    }
                    else
                    {
                        responsemain = response2;
                    }
                }
                else
                {
                    responsemain = response1;
                }

                // we will read data via the response stream
                Stream resStream = responsemain.GetResponseStream();

                string tempString = null;
                int count = 0;

                do
                {
                    // fill the buffer with data
                    count = resStream.Read(buf, 0, buf.Length);

                    // make sure we read some data
                    if (count != 0)
                    {
                        // translate from bytes to ASCII text
                        tempString = Encoding.ASCII.GetString(buf, 0, count);

                        // continue building the string
                        sb.Add(tempString);
                    }
                }
                while (count > 0); // any more data to read?

                string[] str = sb[0].Split(";".ToCharArray());
                if (str.Length == 2)
                {
                    this.NewsUrl.NavigateUri = new Uri(str[1].Replace("\r", string.Empty).Replace("\n", string.Empty));
                    this.NewsText.Text = str[0];
                    return;
                }

                this.NewsUrl.NavigateUri = new Uri("http://www.teknogods.com");
                this.NewsText.Text =
                    ((AssemblyCompanyAttribute)
                     Assembly.GetCallingAssembly().GetCustomAttributes(typeof(AssemblyCompanyAttribute), false)[0]).
                        Company + " "
                    +
                    ((AssemblyCopyrightAttribute)
                     Assembly.GetCallingAssembly().GetCustomAttributes(typeof(AssemblyCopyrightAttribute), false)[0]).
                        Copyright;
            }
            catch (Exception)
            {
                this.NewsUrl.NavigateUri = new Uri("http://www.teknogods.com");
                this.NewsText.Text =
                    ((AssemblyCompanyAttribute)
                     Assembly.GetCallingAssembly().GetCustomAttributes(typeof(AssemblyCompanyAttribute), false)[0]).
                        Company + " "
                    +
                    ((AssemblyCopyrightAttribute)
                     Assembly.GetCallingAssembly().GetCustomAttributes(typeof(AssemblyCopyrightAttribute), false)[0]).
                        Copyright;
            }
        }

        /// <summary>
        /// The image_ mouse down.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void Image_MouseDown(object sender, MouseButtonEventArgs e)
        {
            // TODO: Add event handler implementation here.
            Process.Start("http://teknogods.com/?page_id=19");
        }

        /// <summary>
        /// The ip lost focus.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void IpLostFocus(object sender, RoutedEventArgs e)
        {
            try
            {
                var txt = (TextBox)sender;
                UriHostNameType result = Uri.CheckHostName(txt.Text);

                if (result == UriHostNameType.Unknown || result == UriHostNameType.Basic)
                {
                    txt.Text = "Invalid host.";
                    return;
                }

                if (result == UriHostNameType.IPv4)
                {
                    return;
                }

                IPAddress[] addresslist = Dns.GetHostAddresses(txt.Text);

                return;

                // var txt = (TextBox)sender;
                // string[] thearray = txt.Text.Replace(",", ".").Split(".".ToCharArray());
                // string realip = string.Empty;
                // if (thearray.Length < 4)
                // {
                // txt.Text = "Invalid IP.";
                // }

                // for (int i = 0; i < thearray.Length; i++)
                // {
                // int value = Convert.ToInt32(thearray[i]);
                // if (value > 255 || value < 0)
                // {
                // txt.Text = "Invalid IP.";
                // return;
                // }

                // if (realip == string.Empty)
                // {
                // realip = value.ToString();
                // }
                // else
                // {
                // realip += "." + value;
                // }
                // }

                // var check =
                // new Regex(
                // @"^([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])){3}$");
                // if (check.IsMatch(realip, 0) == false)
                // {
                // txt.Text = "Invalid IP.";
                // return;
                // }

                // txt.Text = realip;
            }
            catch (Exception)
            {
                ((TextBox)sender).Text = "Invalid host.";
            }
        }

        /// <summary>
        /// The is assembly signed.
        /// </summary>
        /// <param name="path">
        /// The path.
        /// </param>
        /// <returns>
        /// The is assembly signed.
        /// </returns>
        private bool IsAssemblySigned(string path)
        {
            int contentType;
            int formatType;
            int ignored;
            IntPtr context = IntPtr.Zero;
            IntPtr pIgnored = IntPtr.Zero;

            IntPtr cryptMsg = IntPtr.Zero;

            if (
                !Win32Apis.CryptQueryObject(
                    Win32Apis.CERT_QUERY_OBJECT_FILE, 
                    Marshal.StringToHGlobalUni(path), 
                    Win32Apis.CERT_QUERY_CONTENT_FLAG_ALL, 
                    Win32Apis.CERT_QUERY_FORMAT_FLAG_ALL, 
                    0, 
                    out ignored, 
                    out contentType, 
                    out formatType, 
                    ref pIgnored, 
                    ref cryptMsg, 
                    ref context))
            {
                int error = Marshal.GetLastWin32Error();

                Console.WriteLine((new Win32Exception(error)).Message);

                return false;
            }

            // expecting '10'; CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
            if (contentType != 10)
            {
                return false;
            }

            // MessageBox.Show("Context Type: " + contentType);

            ////Which implies this is set
            // MessageBox.Show("Crypt Msg: " + cryptMsg.ToString());
            return true;
        }

        /// <summary>
        /// The news url_ click.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void NewsUrl_Click(object sender, RoutedEventArgs e)
        {
            Process.Start(this.NewsUrl.NavigateUri.ToString());
        }

        /// <summary>
        /// The port lost focus.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void PortLostFocus(object sender, RoutedEventArgs e)
        {
            try
            {
                var txt = (TextBox)sender;
                int portnumber = Convert.ToInt32(txt.Text);

                if (portnumber >= 65535)
                {
                    this.PortBox.Text = "27016";
                    return;
                }

                txt.Text = portnumber.ToString();
            }
            catch (Exception)
            {
                this.PortBox.Text = "27016";
            }
        }

        /// <summary>
        /// The start the process.
        /// </summary>
        /// <param name="ExecutableName">
        /// The executable name. 
        /// </param>
        /// <param name="arguements">
        /// The arguements. 
        /// </param>
        private void StartTheProcess(string ExecutableName, string arguements)
        {
            if (File.Exists(@".\devraw\video\startup.bik") == false)
            {
                if (Directory.Exists(@".\devraw\video") == false)
                {
                    Directory.CreateDirectory(@".\devraw\video");
                }

                // Here we extract it
                string strPath = @".\devraw\video\startup.bik";
                if (File.Exists(strPath))
                {
                    File.Delete(strPath);
                }

                Assembly assembly = Assembly.GetExecutingAssembly();
                Stream input = assembly.GetManifestResourceStream("TeknoMW3.tekntup.bik");
                FileStream output = File.Open(strPath, FileMode.CreateNew);
                this.CopyStream(input, output);
                input.Dispose();
                output.Dispose();
            }

            // var parser = new IniParser("teknogods.ini");
            // string name = parser.GetSetting("Settings", "Name");
            // string steamid = parser.GetSetting("Settings", "ID");
            // string fov = parser.GetSetting("Settings", "FOV");

            // string ini = "[Settings]" + Environment.NewLine;

            // if (string.IsNullOrWhiteSpace(name))
            // {
            // MessageBox.Show("teknogods.ini is malformed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            // return;
            // }

            // ini += "Name=" + name + Environment.NewLine;

            // if (string.IsNullOrWhiteSpace(steamid) == false && steamid.Length == 8)
            // {
            // ini += "ID=" + steamid + Environment.NewLine;
            // }

            // try
            // {
            // int fovi = Convert.ToInt32(fov);

            // if (fovi > 80 || fovi < 65)
            // {
            // fovi = 65;
            // }

            // fov = fovi.ToString();
            // }
            // catch (Exception)
            // {
            // fov = "65";
            // }

            // ini += "FOV=" + fov + Environment.NewLine;

            // File.WriteAllText("teknogods.ini", ini);
            var runProc = new RunProc { ExecutableName = ExecutableName, Commandargs = arguements };
            runProc.ShowDialog();
        }

        /// <summary>
        /// The window_ closing.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void Window_Closing(object sender, CancelEventArgs e)
        {
            Properties.Settings.Default.IP = this.IpBox.Text;
            Properties.Settings.Default.Port = this.PortBox.Text;
            Properties.Settings.Default.Save();
        }

        /// <summary>
        /// The window_ loaded.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            this.Window.Title = "TeknoGods Modern Warfare 3 Offline/LAN gameplay MOD "
                                + Assembly.GetExecutingAssembly().GetName().Version;

#if (!DEBUG)

    // if (Directory.GetCurrentDirectory().Contains(@"\steamapps\common\") == false)
    // {
    // MessageBox.Show(
    // "It seems that you are not running legit version of the game, please buy it!",
    // "Error",
    // MessageBoxButton.OK,
    // MessageBoxImage.Error);
    // this.Close();
    // return;
    // }

            var dir = Read("SteamPath");

            if(dir == null)
            {
                MessageBox.Show("Cannot find Steam installation directory!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                this.Close();
                return;
            }

            if (dir.Substring(dir.Length - 1, 1) != "/" || dir.Substring(dir.Length - 1, 1) != "\\")
            {
                dir += "/";
            }

            if(Directory.Exists(dir) == false)
            {
                MessageBox.Show("Cannot find Steam installation directory!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                this.Close();
                return;
            }

            if (File.Exists(dir + "ClientRegistry.blob") == false)
            {
                MessageBox.Show("Cannot open Steam registry!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                this.Close();
                return;                
            }

            var file = File.ReadAllBytes(dir + "ClientRegistry.blob");

            var found = IndexOf(file, Encoding.ASCII.GetBytes("115300"));

            var found2 = IndexOf(file, Encoding.ASCII.GetBytes("42690"));

            if(found == -1 && found2 == -1)
            {
                MessageBox.Show(
                    "It appears you've never used a legitimate Call of Duty - Modern Warfare 3 copy on this computer. Please launch Steam and the game at least once.", 
                    "Error", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Error);
                this.Close();
                return;
            }

            if (File.Exists("teknomw3.dll") == false)
            {
                MessageBox.Show(
                    "Cannot find teknomw3.dll", 
                    "Error", 
                    MessageBoxButton.OK, 
                MessageBoxImage.Error);
                this.Close();
                return;
            }

            if (this.GetMD5HashFromFile("teknomw3.dll") != "fa61fa41dca866f57c4eb7d189a937c6")
            {
                MessageBox.Show(
                "Please extract the TeknoGods teknomw3.dll in the game folder", 
                "Error", 
                MessageBoxButton.OK, 
                MessageBoxImage.Error);
                this.Close();
                return;
            }


#endif
            if (File.Exists(@".\devraw\video\startup.bik") == false)
            {
                if (Directory.Exists(@".\devraw\video") == false)
                {
                    Directory.CreateDirectory(@".\devraw\video");
                }

                // Here we extract it
                string strPath = @".\devraw\video\startup.bik";
                if (File.Exists(strPath))
                {
                    File.Delete(strPath);
                }

                Assembly assembly = Assembly.GetExecutingAssembly();
                Stream input = assembly.GetManifestResourceStream("TeknoMW3.tekntup.bik");
                FileStream output = File.Open(strPath, FileMode.CreateNew);
                this.CopyStream(input, output);
                input.Dispose();
                output.Dispose();
            }

            if (File.Exists("teknogods.ini") == false)
            {
                MessageBox.Show(
                    "It seems that this is your first time running our loader, you must first set your nickname.", 
                    "Information", 
                    MessageBoxButton.OK, 
                    MessageBoxImage.Information);
                var settings = new Settings();
                settings.ShowDialog();
            }
            else
            {
                try
                {
                    if (File.Exists("teknogods.ini"))
                    {
                        var parser = new IniParser("teknogods.ini");
                        string name = parser.GetSetting("Settings", "Name");
                        string id = parser.GetSetting("Settings", "ID");
                        if (id == "/")
                        {
                            File.Delete("teknogods.ini");
                            MessageBox.Show(
                                "It seems that you have malformed SteamID because of bug in 1.2 version, you are required to refill info.", 
                                "Information", 
                                MessageBoxButton.OK, 
                                MessageBoxImage.Information);
                            var settings = new Settings();
                            settings.ShowDialog();
                        }

                        if (string.IsNullOrEmpty(name))
                        {
                            File.Delete("teknogods.ini");
                            MessageBox.Show(
                                "It seems that this is your first time running our loader, you must first set your nickname.", 
                                "Information", 
                                MessageBoxButton.OK, 
                                MessageBoxImage.Information);
                            var settings = new Settings();
                            settings.ShowDialog();
                        }
                    }
                }
                catch (Exception)
                {
                    File.Delete("teknogods.ini");
                    MessageBox.Show(
                        "It seems that this is your first time running our loader, you must first set your nickname.", 
                        "Information", 
                        MessageBoxButton.OK, 
                        MessageBoxImage.Information);
                    var settings = new Settings();
                    settings.ShowDialog();
                }
            }

            this.IpBox.Text = Properties.Settings.Default.IP.Replace(",", ".");
            this.PortBox.Text = Properties.Settings.Default.Port;
            if (string.IsNullOrEmpty(this.PortBox.Text))
            {
                this.PortBox.Text = "27016";
            }

            if (string.IsNullOrEmpty(this.IpBox.Text))
            {
                this.IpBox.Text = "127.0.0.1";
            }

            var thread = new Thread(CheckNewVersion);
            thread.Start();

            this.FetchNews();
        }

        /// <summary>
        /// The check box 1_ checked.
        /// </summary>
        /// <param name="sender">
        /// The sender. 
        /// </param>
        /// <param name="e">
        /// The e. 
        /// </param>
        private void checkBox1_Checked(object sender, RoutedEventArgs e)
        {
            if (this.checkBox1.IsChecked == true)
            {
                this.btnMPDC.IsEnabled = false;
                this.btcSPC.IsEnabled = false;
                this.btnSPH.IsEnabled = false;
            }
            else
            {
                this.btnMPDC.IsEnabled = true;
                this.btcSPC.IsEnabled = true;
                this.btnSPH.IsEnabled = true;
            }
        }

        #endregion
    }
}