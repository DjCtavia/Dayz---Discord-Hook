class DiscordObject_Body : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object
	
		Fields:
			color - int
			title - string
			description - string
			url - string
			timpestamp - string (ISO8601 timestamp)
			fields - array of Field object
		Note:
			We don't include field for type, cause by default it use the "rich" type,
			that mean we can use any type of media.
	*/
	private int m_color;
	private ref array<ref DiscordObject_Fields> m_otherFields;

	void DiscordObject_Body(int color = -1)
	{
		m_color = color;
		m_otherFields = new array<ref DiscordObject_Fields>;
	}
	
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
			return m_color.ToString();
		}
		return "";
	}
	
	private string GetOtherFields()
	{
		string dataFields = "";

		if (m_otherFields.Count() > 0)
		{
			dataFields += "[";
			foreach (auto otherField : m_otherFields)
			{
				dataFields += otherField.ConvertToJson();
			}
			dataFields += "],";
		}
		return dataFields;
	}

	override protected bool CanSetKey(string key)
	{
		switch (key)
		{
			case "title":
				return true;
			case "description":
				return true;
			case "url":
				return true;
			case "timestamp":
				return false;
		}
		return false;
	}
};