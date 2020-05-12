class DiscordJSON
{
	bool m_useDate;
	ref map<string, string> m_object;
	
	void DiscordJSON(bool useDate = true)
	{
		m_useDate = useDate;
	}

	/*
		Description:
			It convert an unformated data to a JSON to send through
			DiscordHook class.
	*/
	string ConvertToJson()
	{
		string jsonData = "{";
		foreach (string key : m_object.GetKeyArray())
		{
			jsonData += FormatKey(key);
		}
		jsonData += "}";
	}

	// http://worldtimeapi.org/pages/faqs#what-can-i-use-it-for
	string GetTime()
	{
		CURLCallback cbx1 = new DiscordCallBack(this);
		CURLContext ctx = GetCURLCore().GetCURLContext("http://worldtimeapi.org/api/ip");
		ctx.GET(cbx1,"RequestPath?Argument=Something");
	}
};

class DiscordCallBack : CURLCallback
{
	ref DiscordJSON m_instance;

	void DiscordCallBack(ref DiscordJSON instance)
	{
		m_instance = instance;
	}

	override void OnError(int errorCode)
	{
		Print("[DiscordHook] An error occured during a call under error: " + errorCode);
	}
	
	override void OnTimeout()
	{
		Print("[DiscordHook] A call timeout...");
	}
	
	override void OnSuccess(string data, int dataSize)
	{
		Print("[DiscordHook] Hook has been successfuly used!");
	};
};