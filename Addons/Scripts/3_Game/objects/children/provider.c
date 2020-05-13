class DiscordObject_Provider : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object-embed-provider-structure
	
		Fields:
			name - string
			url - string
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
		}
		return false;
	}
};