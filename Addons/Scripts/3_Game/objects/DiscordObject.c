class DiscordObject
{
	protected ref map<string, string> m_fields;

	void DiscordObject()
	{
		m_fields = new map<string, string>;
	}
	
	/*
		Description:
			This method is used for defining which type of
			method it should use by default.
	*/
	string DefaultJSONConvert()
	{
		return ConvertToJson();
	}

	/*
		Description:
			The data converted as JSON will not be between "{}" or "[]",
			this is pure data.
	*/
	protected string ConvertToJson()
	{
		string jsonData = "";
		array<string> keys =  m_fields.GetKeyArray();
		
		for (int keyIndex = 0; keyIndex < keys.Count(); keyIndex++)
		{
			jsonData += FormatField(keys.Get(keyIndex));
		}
		jsonData += ConvertSpecialFields();
		return jsonData;
	}

	/*
		Description:
			The data converted as JSON is opened and close with "{}"
	*/
	protected string ConvertToJsonCloseByObject(string fieldName)
	{
		string jsonData = "\"" + fieldName + "\":{";
		
		foreach (string key : m_fields.GetKeyArray())
		{
			jsonData += FormatField(key);
		}
		jsonData += ConvertSpecialFields() + "},";
		return jsonData;
	}

	/*
		Description:
			The data converted as JSON is opened and close with "[]"
	*/
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

	/*
		Description:
			The data that is not a string, like integer, float, boolean,
			or more complex like class, go through this method. The easy
			way to use it, is to create a method for each specific issue.
		Example:
			Let's say we need a color as is the case in the "DiscordObject_Body" class,
			we need to convert an integer into a string.

			Code ------------------------------------------------
			override protected string ConvertSpecialFields()
			{
				string addedFieldsToJson = "";
		
				addedFieldsToJson += GetColorField();
				return addedFieldsToJson;
			}

			private string GetColorField()
			{
				if (m_color > -1)
				{
				return DiscordHelper.GetJSONLineOthers("color", m_color.ToString());
				}
				return "";
			}
			-----------------------------------------------------

			As we see above, we perform an override on the "ConvertSpecialFields" method.
			This allows us to have a more appropriate return value.

			We need to look at the way we see the problem, when we return our data for json,
			we need to have something like: `"somedata": "this is a text", "color":50000`.

			Anything that only uses strings will be processed from the "m_fields" variable.
			So we only generate the last part `"color":50000`.

			The second method creates "GetColorField", which will allow us to check if
			the conditions are met to return the variable without sending too much data, or an incorrect variable.
	*/
	protected string ConvertSpecialFields() {return "";}

	// Just a shortcut to call the helper.
	protected string FormatField(string key)
	{
		return DiscordHelper.GetJSONLineString(key, m_fields.Get(key));
	}
	
	/*
		Description:
			Limit what key name can be include in children class if modified.
			See children class like body, author...
	*/
	protected bool CanSetKey(string key)
	{
		return true;
	}
	
	void SetField(string field, string value)
	{
		if (CanSetKey(field))
		{
			m_fields.Set(field, value);
		}
	}
	
	void RemoveField(string field)
	{
		if (m_fields.Contains(field))
		{
			m_fields.Remove(field);
		}
	}
};