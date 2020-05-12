class DiscordHook
{
	ref map<string, string> m_alias;

	void DiscordHook()
	{
		m_alias = new map<string, string>;
	}

	// Alias section
	bool AddAlias(string alias, string url)
	{
		if (!m_alias.Contains(alias))
		{
			m_alias.Set(alias, url);
			return true;
		}
		return false;
	}
	
	bool RemoveAlias(string alias)
	{
		if (m_alias.Contains(alias))
		{
			m_alias.Remove(alias);
			return true;
		}
		return false;
	}
	
	bool ModifyAlias(string alias, string url)
	{
		if (m_alias.Contains(alias))
		{
			m_alias.Set(alias, url);
			return true;
		}
		return false;
	}
};

static ref DiscordHook g_discordHook;
static ref DiscordHook DiscordHook()
{
	if (!g_discordHook)
	{
		g_discordHook = new DiscordHook;
	}
	return g_discordHook;
}