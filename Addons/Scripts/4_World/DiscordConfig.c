static string DiscordConfigDataFileLocation = "$profile:DH_DiscordConfigDataFile.json";

class DiscordConfig
{
    ref map<string, string> dh_data = new map<string, string>();

    map<string, string> Load()
    {
        ref map<string, string> data = new map<string, string>();

        if ( FileExist(DiscordConfigDataFileLocation) ) {
            JsonFileLoader<map<string, string>>.JsonLoadFile(DiscordConfigDataFileLocation, data);
        } else {
            JsonFileLoader<map<string, string>>.JsonSaveFile(DiscordConfigDataFileLocation, data);
        }

        return data;
    }

    void LoadConfigHandler()
    {
        dh_data = Load();

        string m_discordHookText = "";
        
        ref map<string, string> m_discordHook = new map<string, string>();

        if (FileExist(DiscordConfigDataFileLocation) && dh_data.Contains("m_discordHook")) {
            Print("DATA");
            Print(dh_data);
        } else {
            m_discordHook.Insert("m_discordHook", "HERE_LINK_DISCORD_HOOK");
            m_discordHook.Insert("m_discordHookServerName", "HERE_SERVER_NAME");
            Save(m_discordHook);
        }        
        Print("LoadConfigHandler ");
        Print(m_discordHook.Get("m_discordHook"));
        Print(m_discordHook.Get("m_discordHookServerName"));
    }

    void Save(map<string, string>> dh_data)
    {
        JsonFileLoader<map<string, string>>.JsonSaveFile(DiscordConfigDataFileLocation, dh_data);
    }
}