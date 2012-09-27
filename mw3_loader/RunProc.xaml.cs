// --------------------------------------------------------------------------------------------------------------------
// <copyright file="RunProc.xaml.cs" company="">
//   
// </copyright>
// <summary>
//   Interaction logic for RunProc.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.ComponentModel;
    using System.Globalization;
    using System.IO;
    using System.Text;
    using System.Threading;
    using System.Windows;
    using System.Windows.Threading;

    /// <summary>
    /// Interaction logic for RunProc.xaml
    /// </summary>
    public partial class RunProc : Window
    {
        #region Constants and Fields

        /// <summary>
        /// The canclose.
        /// </summary>
        private bool canclose;

        /// <summary>
        /// The dispatcher timer.
        /// </summary>
        private DispatcherTimer dispatcherTimer;

        /// <summary>
        /// The initialized.
        /// </summary>
        private bool initialized;

        /// <summary>
        /// The mutex.
        /// </summary>
        private Mutex mutex;

        /// <summary>
        /// The thread.
        /// </summary>
        private IntPtr thread;

        #endregion

        #region Constructors and Destructors

        /// <summary>
        /// Initializes a new instance of the <see cref="RunProc"/> class.
        /// </summary>
        public RunProc()
        {
            this.InitializeComponent();

            // Insert code required on object creation below this point.
        }

        #endregion

        // <summary>
        // The protection.
        // </summary>
        #region Public Properties

        /// <summary>
        /// Gets or sets Commandargs.
        /// </summary>
        public string Commandargs { get; set; }

        /// <summary>
        /// Gets or sets ExecutableName.
        /// </summary>
        public string ExecutableName { get; set; }

        #endregion

        #region Public Methods

        /// <summary>
        /// The bytes to int.
        /// </summary>
        /// <param name="input">
        /// The input.
        /// </param>
        /// <returns>
        /// The bytes to int.
        /// </returns>
        public static int BytesToInt(byte[] input)
        {
            string s = input[3].ToString("X2") + input[2].ToString("X2") + input[1].ToString("X2")
                       + input[0].ToString("X2");
            return int.Parse(s, NumberStyles.HexNumber);
        }

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

        #endregion

        #region Methods

        /// <summary>
        /// The round 1000.
        /// </summary>
        /// <param name="a">
        /// The a.
        /// </param>
        /// <returns>
        /// The round 1000.
        /// </returns>
        private static int Round1000(int a)
        {
            return (a / 0x1000 + ((a % 0x1000) > 0 ? 1 : 0)) * 0x1000;
        }

        /// <summary>
        /// The dispatcher timer_ tick.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The e.
        /// </param>
        private void DispatcherTimer_Tick(object sender, EventArgs e)
        {
            if (this.initialized == false)
            {
                this.initialized = true;
                var t = new Thread(this.threadi);
                t.Start();

                this.dispatcherTimer.Interval = new TimeSpan(0, 0, 5);
                return;
            }

            var context = new CONTEXT();
            try
            {
                if (this.ExecutableName == "iw5mp_server.exe")
                {
                    this.mutex.Close();
                    this.canclose = true;
                    this.Close();
                }

                if (!Win32Apis.GetThreadContext(this.thread, ref context))
                {
                    this.mutex.Close();
                    this.canclose = true;
                    this.Close();
                }
            }
            catch (Exception)
            {
                try
                {
                    this.mutex.Close();
                    this.canclose = true;
                    this.Close();
                }
                catch (Exception)
                {
                    this.canclose = true;
                    this.Close();
                }
            }
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
            // TODO: Add event handler implementation here.
            if (this.canclose == false)
            {
                e.Cancel = true;
            }
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
            this.initialized = false;
            this.dispatcherTimer = new DispatcherTimer();
            this.dispatcherTimer.Tick += this.DispatcherTimer_Tick;
            this.dispatcherTimer.Interval = new TimeSpan(0, 0, 1);
            this.dispatcherTimer.Start();
            if (this.ExecutableName == "iw5mp_server.exe")
            {
                this.RunningLabel.Content = "Running dedicated server, a moment please.";
            }
        }

        /// <summary>
        /// The threadi.
        /// </summary>
        private void threadi()
        {
            var si = new STARTUPINFO();
            var pi = new PROCESS_INFORMATION();

            byte[] array = File.ReadAllBytes(this.ExecutableName);

            var peptr = new byte[4];

            Array.Copy(array, 0x3C, peptr, 0, 2);

            var temparray = new byte[4];

            int peLocation = BytesToInt(peptr);

            int virtualSize = peLocation + 0x128;

            int virtualAddress = peLocation + 0x12C;
            int rawSize = peLocation + 0x130;
            int rawLocation = peLocation + 0x134;

            Array.Copy(array, rawSize, temparray, 0, 4);
            rawSize = BytesToInt(temparray);
            Array.Copy(array, rawLocation, temparray, 0, 4);
            rawLocation = BytesToInt(temparray);
            Array.Copy(array, virtualAddress, temparray, 0, 4);
            virtualAddress = BytesToInt(temparray) + 0x400000;
            Array.Copy(array, virtualSize, temparray, 0, 4);
            virtualSize = Round1000(BytesToInt(temparray));

            int steamapi = IndexOf(array, Encoding.ASCII.GetBytes("steam_api.dll"));

            if (steamapi < rawLocation && steamapi > rawLocation + rawSize)
            {
                MessageBox.Show(
                    "Cannot find steam_api.dll string in executable, make sure you have the proper original files!");
                return;
            }

            int location = steamapi - rawLocation;

            if (
                !Win32Apis.CreateProcess(
                    this.ExecutableName, 
                    this.Commandargs, 
                    IntPtr.Zero, 
                    IntPtr.Zero, 
                    false, 
                    0x4 | 0x200, 
                    IntPtr.Zero, 
                    null, 
                    ref si, 
                    out pi))
            {
                MessageBox.Show("Cannot create process!");
                return;
            }

            this.thread = pi.hThread;
            uint oldprot;
            Win32Apis.VirtualProtectEx(
                pi.hProcess, new IntPtr(virtualAddress), new UIntPtr((uint)virtualSize), 0x40, out oldprot);

            UIntPtr ptr;
            Win32Apis.WriteProcessMemory(
                pi.hProcess, new IntPtr(virtualAddress + location), Encoding.ASCII.GetBytes("teknomw3.dll"), 13, out ptr);

            uint newprot;
            Win32Apis.VirtualProtectEx(
                pi.hProcess, new IntPtr(virtualAddress), new UIntPtr((uint)virtualSize), oldprot, out newprot);

            if (ptr == (UIntPtr)0)
            {
                MessageBox.Show("Cannot write to process memory!");
                Win32Apis.TerminateProcess(pi.hProcess, 0);
                Win32Apis.TerminateThread(pi.hThread, 0);
                return;
            }

            this.mutex = new Mutex(false, "TeknoMW3" + (pi.dwProcessId ^ 0x57).ToString("X8"));
            Win32Apis.ResumeThread(pi.hThread);
        }

        #endregion
    }
}