// -----------------------------------------------------------------------
// <copyright file="IniParser.cs" company="">
// TODO: Update copyright text.
// </copyright>
// -----------------------------------------------------------------------

namespace TeknoMW3
{
    using System;
    using System.IO;
    using System.Collections;
 
public class IniParser
{
    private readonly Hashtable _keyPairs = new Hashtable();
    private readonly String _iniFilePath;
 
    private struct SectionPair
    {
        public String Section;
        public String Key;
    }
 
    /// <summary>
    /// Opens the INI file at the given path ;and enumerates the values in the IniParser.
    /// </summary>
    /// <param name="iniPath">Full path to INI file.&lt;/param>
    public IniParser(String iniPath)
    {
        TextReader iniFile = null;
        String strLine = null;
        String currentRoot = null;
        String[] keyPair = null;
 
        this._iniFilePath = iniPath;
 
        if(File.Exists(iniPath))
        {
            try
            {
                iniFile = new StreamReader(iniPath);
 
                strLine = iniFile.ReadLine();
 
                while (strLine != null)
                {
                    strLine = strLine.Trim();
 
                   if (strLine != "")
                   {
                       if (strLine.StartsWith("[") && strLine.EndsWith("]"))
                       {
                          currentRoot = strLine.Substring(1, strLine.Length - 2);
                       }
                       else
                       {
                          keyPair = strLine.Split(new char[]{ '=' }, 2);
 
                          SectionPair sectionPair;
                          String value = null;
 
                          if (currentRoot == null)
                              currentRoot = "ROOT";
 
                          sectionPair.Section = currentRoot;
                          sectionPair.Key = keyPair[0];
 
                          if (keyPair.Length > 1)
                              value = keyPair[1];
 
                          this._keyPairs.Add(sectionPair, value);
                       }
                   }
 
                   strLine = iniFile.ReadLine();
                }
 
            }
            catch (Exception ex)
            {
                throw ex;
            }
            finally
            {
                if (iniFile != null)
                   iniFile.Close();
            }
        }
        else
            throw new FileNotFoundException("Unable to locate " + iniPath);
 
    }
 
    /// <summary>
    /// Returns the ;value for the given section, key pair.
    /// </summary>
    /// <param name="sectionName">Section name.</param>
    /// <param name="settingName">Key name.</param>
    public string GetSetting(string sectionName, string settingName)
    {
        try
        {
        SectionPair sectionPair;
        sectionPair.Section = sectionName;
        sectionPair.Key = settingName;
 
        return (String)this._keyPairs[sectionPair];
        }
        catch (Exception)
        {
            return string.Empty;
        }
    }
 
    /// <summary>
    /// Enumerates alllines for given section.
    /// </summary>
    /// <param name="sectionName">Section to enum.</param>;
    public string[] EnumSection(string sectionName)
    {
        ArrayList tmpArray = new ArrayList();
 
        foreach (SectionPair pair in this._keyPairs.Keys)
        {
            if (pair.Section == sectionName)
                tmpArray.Add(pair.Key);
        }
 
        return (String[])tmpArray.ToArray(typeof(String));
    }
 
    /// <summary>
    /// Adds or replaces a setting to the tableto be saved.
    /// </summary>
    /// <param name="sectionName">Section to add under.<;/param>
    /// <param name="settingName">Key name to add.</param>
    /// <param name="settingValue">Value of key.</param>
    public void AddSetting(string sectionName, string settingName, string settingValue)
    {
        SectionPair sectionPair;
        sectionPair.Section = sectionName;
        sectionPair.Key = settingName;
 
        if(this._keyPairs.ContainsKey(sectionPair))
            this._keyPairs.Remove(sectionPair);
 
        this._keyPairs.Add(sectionPair, settingValue);
    }
 
    /// <summary>
    /// Adds or replaces a setting to the tableto be saved with a nullvalue.
    /// </summary>
    /// <param name="sectionName">Section to add under.<;/param>
    /// <param name="settingName">Key name to add.</param>
    public void AddSetting(string sectionName, string settingName)
    {
        AddSetting(sectionName, settingName, null);
    }
 
    /// <summary>
    /// Remove a setting.
    /// </summary>
    /// <param name="sectionName">Section to add under.<;/param>
    /// <param name="settingName">Key name to add.</param>
    public void DeleteSetting(string sectionName, string settingName)
    {
        SectionPair sectionPair;
        sectionPair.Section = sectionName;
        sectionPair.Key = settingName;
 
        if(this._keyPairs.ContainsKey(sectionPair))
            this._keyPairs.Remove(sectionPair);
    }
 
    /// <summary>
    /// Save settingsto new file.
    /// </summary>
    /// <param name="newFilePath">New file path.</param>
    public void SaveSettings(string newFilePath)
    {
        ArrayList sections = new ArrayList();
        string tmpValue = "";
        string strToSave = "";
 
        foreach (SectionPair sectionPair in this._keyPairs.Keys)
        {
            if (!sections.Contains(sectionPair.Section))
                sections.Add(sectionPair.Section);
        }
 
        foreach (string section in sections)
        {
            strToSave += ("[" +section + "]\r\n");
 
            foreach (SectionPair sectionPair in this._keyPairs.Keys)
            {
                if (sectionPair.Section == section)
                {
                   tmpValue = (String)this._keyPairs[sectionPair];
 
                   if (tmpValue != null)
                       tmpValue = "=" + tmpValue;
 
                   strToSave += (sectionPair.Key + tmpValue + "\r\n");
                }
            }
 
            strToSave += "\r\n";
        }
 
        try
        {
            TextWriter tw = new StreamWriter(newFilePath);
            tw.Write(strToSave);
            tw.Close();
        }
        catch(Exception ex)
        {
            throw ex;
        }
    }
 
    /// <summary>
    /// Save settingsback to ini file.
    /// </summary>
    public void SaveSettings()
    {
        SaveSettings(this._iniFilePath);
    }
}
}
