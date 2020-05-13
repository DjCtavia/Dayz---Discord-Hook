class DiscordJSON
{
	/*
		Source of discord hook help:
			https://discord.com/developers/docs/resources/channel#embed-object
	*/
	ref DiscordObject_Body m_body;
	ref DiscordObject_Footer m_footer;
	ref DiscordObject_Image m_image;
	ref DiscordObject_Thumbnail m_thumbnail;
	ref DiscordObject_Video m_video;
	ref DiscordObject_Provider m_provider;
	ref DiscordObject_Author m_author;

	/*
		Description:
			It convert an unformated data to a JSON to send through
			DiscordHook class.
	*/
	string GetJSON()
	{
		string jsonData = "{";
		
		jsonData += GetModuleJSON(m_body);
		jsonData += GetModuleJSON(m_footer);
		jsonData += GetModuleJSON(m_image);
		jsonData += GetModuleJSON(m_thumbnail);
		jsonData += GetModuleJSON(m_video);
		jsonData += GetModuleJSON(m_provider);
		jsonData += GetModuleJSON(m_author);
		jsonData += "}";
		jsonData = DiscordHelper.RemoveExtraCommasJSON(jsonData);
		return jsonData;
	}
	
	string GetModuleJSON(ref DiscordObject module)
	{
		if (module)
		{
			return module.DefaultJSONConvert();
		}
		return "";
	}
};