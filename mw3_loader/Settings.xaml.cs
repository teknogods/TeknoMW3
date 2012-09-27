// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Settings.xaml.cs" company="">
//   
// </copyright>
// <summary>
//   Interaction logic for Settings.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.IO;
    using System.Linq;
    using System.Windows;
    using System.Windows.Input;

    /// <summary>
    /// Interaction logic for Settings.xaml
    /// </summary>
    public partial class Settings : Window
    {
        #region Constants and Fields

        /// <summary>
        /// The canclose.
        /// </summary>
        private bool canclose;

        private string steamid;

        #endregion

        #region Constructors and Destructors

        /// <summary>
        /// Initializes a new instance of the <see cref="Settings"/> class.
        /// </summary>
        public Settings()
        {
            this.InitializeComponent();
            txtName.Focus();
            try
            {
                if (File.Exists("teknogods.ini") == true)
                {
                    var parser = new IniParser("teknogods.ini");
                    txtName.Text = parser.GetSetting("Settings", "Name");
                    this.steamid = parser.GetSetting("Settings", "ID");
                    this.txtFov.Text = parser.GetSetting("Settings", "FOV");
                    try
                    {
                        var fov = Convert.ToInt32(txtFov.Text);

                        if (fov > 90 || fov < 65)
                        {
                            txtFov.Text = "65";
                            return;
                        }

                        txtFov.Text = fov.ToString();
                    }
                    catch (Exception)
                    {
                        txtFov.Text = "65";
                    }
                }
                else
                {
                    var files = Directory.GetFiles(".\\players2\\", "*.stat");
                    for (var i = 0; i < files.Length; i++)
                    {
                        files[i] = files[i].Replace(".\\players2\\", string.Empty);
                    }

                    var ids = new List<string>();
                    for (var i = 0; i < files.Length; i++)
                    {
                        if (files[i].StartsWith("iw5") == true)
                        {
                            var parts = files[i].Split("_".ToCharArray());
                            if (parts.Length == 5)
                            {
                                ids.Add(parts[4].Substring(7, 8));
                            }
                        }
                    }

                    if (ids.Count < 1)
                    {
                        return;
                    }

                    var counts = ids.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
                    foreach (var pair in counts)
                    {
                        this.steamid = pair.Key;
                        break;
                    }
                    
                }
            }
            catch (Exception)
            {
                File.Delete("teknogods.ini");
            }
            // Insert code required on object creation below this point.
        }

        #endregion

        #region Methods

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
            if (string.IsNullOrWhiteSpace(txtName.Text) == true)
            {
                MessageBox.Show("Please first set nickname", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            var settings = "[Settings]" + Environment.NewLine + "Name=" + txtName.Text;
            if (string.IsNullOrWhiteSpace(this.steamid) == false && this.steamid != "00010000")
            {
                settings += Environment.NewLine + "ID=" + this.steamid;
            }

            settings += Environment.NewLine + "FOV=" + this.txtFov.Text;

            File.WriteAllText("teknogods.ini", settings);

            this.canclose = true;
            this.Close();
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
            if (this.canclose == false)
            {
                e.Cancel = true;
            }
        }

        #endregion

        private void txtName_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                this.Button_Click(null, null);
            }
        }

        private void Window_LostFocus(object sender, RoutedEventArgs e)
        {
            try
            {
                var fov = Convert.ToInt32(txtFov.Text);

                if (fov > 90 || fov < 65)
                {
                    txtFov.Text = "65";
                    return;
                }

                txtFov.Text = fov.ToString();
            }
            catch (Exception)
            {
                txtFov.Text = "65";
            }
        }
    }
}