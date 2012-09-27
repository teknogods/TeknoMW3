// --------------------------------------------------------------------------------------------------------------------
// <copyright file="AboutBox.xaml.cs" company="">
//   
// </copyright>
// <summary>
//   Interaction logic for AboutBox.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.Diagnostics;
    using System.IO;
    using System.Reflection;
    using System.Windows;
    using System.Windows.Data;
    using System.Windows.Navigation;
    using System.Xml;

    /// <summary>
    /// Interaction logic for AboutBox.xaml
    /// </summary>
    public partial class AboutBox : Window
    {
        #region Constants and Fields

        /// <summary>
        /// The property name company.
        /// </summary>
        private const string propertyNameCompany = "TeknoGods";

        /// <summary>
        /// The property name copyright.
        /// </summary>
        private const string propertyNameCopyright = "Copyright";

        /// <summary>
        /// The property name description.
        /// </summary>
        private const string propertyNameDescription = "Description";

        /// <summary>
        /// The property name product.
        /// </summary>
        private const string propertyNameProduct = "TeknoMW3";

        /// <summary>
        /// The property name title.
        /// </summary>
        private const string propertyNameTitle = "Title";

        /// <summary>
        /// The x path company.
        /// </summary>
        private const string xPathCompany = xPathRoot + propertyNameCompany;

        /// <summary>
        /// The x path copyright.
        /// </summary>
        private const string xPathCopyright = xPathRoot + propertyNameCopyright;

        /// <summary>
        /// The x path description.
        /// </summary>
        private const string xPathDescription = xPathRoot + propertyNameDescription;

        /// <summary>
        /// The x path link.
        /// </summary>
        private const string xPathLink = xPathRoot + "Link";

        /// <summary>
        /// The x path link uri.
        /// </summary>
        private const string xPathLinkUri = xPathRoot + "Link/@Uri";

        /// <summary>
        /// The x path product.
        /// </summary>
        private const string xPathProduct = xPathRoot + "TeknoMW3";

        /// <summary>
        /// The x path root.
        /// </summary>
        private const string xPathRoot = "ApplicationInfo/";

        /// <summary>
        /// The x path title.
        /// </summary>
        private const string xPathTitle = xPathRoot + propertyNameTitle;

        /// <summary>
        /// The x path version.
        /// </summary>
        private const string xPathVersion = xPathRoot + "2.0";

        /// <summary>
        /// The xml doc.
        /// </summary>
        private XmlDocument xmlDoc;

        #endregion

        #region Constructors and Destructors

        /// <summary>
        /// Initializes a new instance of the <see cref="AboutBox"/> class. 
        /// Constructor that takes a parent for this AboutBox dialog.
        /// </summary>
        /// <param name="parent">
        /// Parent window for this dialog.
        /// </param>
        public AboutBox(Window parent)
            : this()
        {
            this.Owner = parent;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AboutBox"/> class. 
        /// Default constructor is protected so callers must use one with a parent.
        /// </summary>
        protected AboutBox()
        {
            this.InitializeComponent();
        }

        #endregion

        #region Public Properties

        /// <summary>
        /// Gets the product's company name.
        /// </summary>
        public string Company
        {
            get
            {
                return this.CalculatePropertyValue<AssemblyCompanyAttribute>(propertyNameCompany, xPathCompany);
            }
        }

        /// <summary>
        /// Gets the copyright information for the product.
        /// </summary>
        public string Copyright
        {
            get
            {
                return this.CalculatePropertyValue<AssemblyCopyrightAttribute>(propertyNameCopyright, xPathCopyright);
            }
        }

        /// <summary>
        /// Gets the description about the application.
        /// </summary>
        public string Description
        {
            get
            {
                return this.CalculatePropertyValue<AssemblyDescriptionAttribute>(
                    propertyNameDescription, xPathDescription);
            }
        }

        /// <summary>
        /// Gets the link text to display in the About dialog.
        /// </summary>
        public string LinkText
        {
            get
            {
                return this.GetLogicalResourceString(xPathLink);
            }
        }

        /// <summary>
        /// Gets the link uri that is the navigation target of the link.
        /// </summary>
        public string LinkUri
        {
            get
            {
                return this.GetLogicalResourceString(xPathLinkUri);
            }
        }

        /// <summary>
        ///  Gets the product's full name.
        /// </summary>
        public string Product
        {
            get
            {
                return this.CalculatePropertyValue<AssemblyProductAttribute>(propertyNameProduct, xPathProduct);
            }
        }

        /// <summary>
        /// Gets the title property, which is display in the About dialogs window title.
        /// </summary>
        public string ProductTitle
        {
            get
            {
                string result = this.CalculatePropertyValue<AssemblyTitleAttribute>(propertyNameTitle, xPathTitle);
                if (string.IsNullOrEmpty(result))
                {
                    // otherwise, just get the name of the assembly itself.
                    result = Path.GetFileNameWithoutExtension(Assembly.GetExecutingAssembly().CodeBase);
                }

                return result;
            }
        }

        /// <summary>
        /// Gets the application's version information to show.
        /// </summary>
        public string Version
        {
            get
            {
                string result = string.Empty;

                // first, try to get the version string from the assembly.
                Version version = Assembly.GetExecutingAssembly().GetName().Version;
                if (version != null)
                {
                    result = version.ToString();
                }
                else
                {
                    // if that fails, try to get the version from a resource in the Application.
                    result = this.GetLogicalResourceString(xPathVersion);
                }

                return result;
            }
        }

        #endregion

        #region Properties

        /// <summary>
        /// Gets the XmlDataProvider's document from the resource dictionary.
        /// </summary>
        protected virtual XmlDocument ResourceXmlDocument
        {
            get
            {
                if (this.xmlDoc == null)
                {
                    // if we haven't already found the resource XmlDocument, then try to find it.
                    var provider = this.TryFindResource("aboutProvider") as XmlDataProvider;
                    if (provider != null)
                    {
                        // save away the XmlDocument, so we don't have to get it multiple times.
                        this.xmlDoc = provider.Document;
                    }
                }

                return this.xmlDoc;
            }
        }

        #endregion

        #region Methods

        /// <summary>
        /// Gets the specified data element from the XmlDataProvider in the resource dictionary.
        /// </summary>
        /// <param name="xpathQuery">
        /// An XPath query to the XML element to retrieve.
        /// </param>
        /// <returns>
        /// The resulting string value for the specified XML element. 
        /// Returns empty string if resource element couldn't be found.
        /// </returns>
        protected virtual string GetLogicalResourceString(string xpathQuery)
        {
            string result = string.Empty;

            // get the About xml information from the resources.
            XmlDocument doc = this.ResourceXmlDocument;
            if (doc != null)
            {
                // if we found the XmlDocument, then look for the specified data. 
                XmlNode node = doc.SelectSingleNode(xpathQuery);
                if (node != null)
                {
                    if (node is XmlAttribute)
                    {
                        // only an XmlAttribute has a Value set.
                        result = node.Value;
                    }
                    else
                    {
                        // otherwise, need to just return the inner text.
                        result = node.InnerText;
                    }
                }
            }

            return result;
        }

        /// <summary>
        /// Gets the specified property value either from a specific attribute, or from a resource dictionary.
        /// </summary>
        /// <typeparam name="T">
        /// Attribute type that we're trying to retrieve.
        /// </typeparam>
        /// <param name="propertyName">
        /// Property name to use on the attribute.
        /// </param>
        /// <param name="xpathQuery">
        /// XPath to the element in the XML data resource.
        /// </param>
        /// <returns>
        /// The resulting string to use for a property.
        /// Returns null if no data could be retrieved.
        /// </returns>
        private string CalculatePropertyValue<T>(string propertyName, string xpathQuery)
        {
            string result = string.Empty;

            // first, try to get the property value from an attribute.
            object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(T), false);
            if (attributes.Length > 0)
            {
                var attrib = (T)attributes[0];
                PropertyInfo property = attrib.GetType().GetProperty(
                    propertyName, BindingFlags.Public | BindingFlags.Instance);
                if (property != null)
                {
                    result = property.GetValue(attributes[0], null) as string;
                }
            }

            // if the attribute wasn't found or it did not have a value, then look in an xml resource.
            if (result == string.Empty)
            {
                // if that fails, try to get it from a resource.
                result = this.GetLogicalResourceString(xpathQuery);
            }

            return result;
        }

        /// <summary>
        /// Handles click navigation on the hyperlink in the About dialog.
        /// </summary>
        /// <param name="sender">
        /// Object the sent the event.
        /// </param>
        /// <param name="e">
        /// Navigation events arguments.
        /// </param>
        private void hyperlink_RequestNavigate(object sender, RequestNavigateEventArgs e)
        {
            if (e.Uri != null && string.IsNullOrEmpty(e.Uri.OriginalString) == false)
            {
                string uri = e.Uri.AbsoluteUri;
                Process.Start(new ProcessStartInfo(uri));
                e.Handled = true;
            }
        }

        #endregion
    }
}