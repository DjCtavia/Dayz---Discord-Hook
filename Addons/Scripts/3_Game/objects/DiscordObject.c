class DiscordObject
{
	protected ref map<string, string> m_fields;

	void DiscordObject()
	{
		m_fields = new map<string, string>;
	}
	
	// Override this function for overriding the default method
	string DefaultJSONConvert()
	{
		return ConvertToJson();
	}

	protected string ConvertToJson()
	{
		string jsonData = "";
		
		foreach (string key : m_fields.GetKeyArray())
		{
			jsonData += FormatField(key);
		}
		jsonData += ConvertSpecialFields();
		return jsonData;
	}

	protected string ConvertToJsonCloseByObject()
	{
		string jsonData = "{";
		
		foreach (string key : m_fields.GetKeyArray())
		{
			jsonData += FormatField(key);
		}
		jsonData += ConvertSpecialFields() + "}";
		return jsonData;
	}

	protected string ConvertToJsonCloseByArray()
	{
		string jsonData = "[";
		
		foreach (string key : m_fields.GetKeyArray())
		{
			jsonData += FormatField(key);
		}
		jsonData += ConvertSpecialFields() + "]";
		return jsonData;
	}

	// It need to be override in children
	protected string ConvertSpecialFields() {return "";}
	
	protected string FormatField(string key)
	{
		return helperJSON.GetJSONLineString(key, m_fields.Get(key));
	}
	
	// Can limit what key name can be include in children class if modified
	protected bool CanSetKey(string key)
	{
		return true;
	}
	
	protected void SetField(string field, string value)
	{
		if (CanSetKey())
		{
			m_fields.Set(field, value);
		}
	}
	
	protected void RemoveField(string field)
	{
		if (m_fields.Contains(field))
		{
			m_fields.Remove(field);
		}
	}
};