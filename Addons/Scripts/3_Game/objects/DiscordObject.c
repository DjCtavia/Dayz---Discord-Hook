class DiscordObject
{
	protected ref map<string, string> m_fields;

	void DiscordObject()
	{
		m_fields = new map<string, string>;
	}
	
	string ConvertToJson()
	{
		string jsonData = "{";
		foreach (string key : m_object.GetKeyArray())
		{
			jsonData += FormatKey(key);
		}
		jsonData += "}";
	}
	
	protected string FormatKey(string key)
	{
		return "\"" + key + "\":" + "\"" + m_object.Get(key) + "\"";
	}
};