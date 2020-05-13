class DiscordObject_Fields : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object-embed-field-structure
	
		Fields:
			name - string
			value - string
			inline - boolean
	*/
	private bool m_inline;

	void DiscordObject_Fields(string name, string value, bool inline = false)
	{
		m_inline = inline;
		m_fields.Set("name", name);
		m_fields.Set("value", value);
	}

	override string DefaultJSONConvert()
	{
		return ConvertToJsonCloseByObject("");
	}
	
	override protected string ConvertSpecialFields()
	{
		string addedFieldsToJson = "";
		
		addedFieldsToJson += GetInlineField();
		return addedFieldsToJson;
	}
	
	private string GetInlineField()
	{
		return m_inline.ToString();
	}

	override protected bool CanSetKey(string key)
	{
		return false;
	}
};