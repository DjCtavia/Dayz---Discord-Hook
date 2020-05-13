class DiscordObject_Author : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object-embed-author-structure
	
		Fields:
			name - string
			url - string
			icon_url - string
			proxy_icon_url - string
	*/
	override string DefaultJSONConvert()
	{
		return ConvertToJsonCloseByObject("provider");
	}

	override protected bool CanSetKey(string key)
	{
		switch (key)
		{
			case "name":
				return true;
			case "url":
				return true;
			case "icon_url":
				return true;
			case "proxy_icon_url":
				return true;
		}
		return false;
	}
};