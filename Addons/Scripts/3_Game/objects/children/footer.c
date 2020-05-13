class DiscordObject_Footer : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object-embed-footer-structure

		Fields:
			text - string
			icon_url - string
			proxy_icon_url - string
	*/
	override protected bool CanSetKey(string key)
	{
		switch (key)
		{
			case "text":
				return true;
			case "icon_url":
				return true;
			case "proxy_icon_url":
				return true;
		}
		return false;
	}
};