modded class MissionServer
{
	void MissionServer()
	{
		Print("[DiscordHook] Started.");
		// GetDiscordHook().SetAlias("YourAlias", "YourDiscordWebHookURL");
		// GetDiscordHook().SetAlias("AnotherAlias", "AnotherWebHookURL");
		// ServerStartMessage();
	}
	
	void ~MissionServer()
	{
		// ServerStopMessage();
	}
	
	// void ServerStartMessage()
	// {
	// 	ref DiscordJSON dataJSON = new DiscordJSON();
	// 	ref DiscordObject_Body dataBody = new DiscordObject_Body(5019904);
	// 	ref DiscordObject_Thumbnail dataThumb = new DiscordObject_Thumbnail(64, 64);

	// 	dataBody.SetField("title", "Server start!");
	// 	dataBody.SetField("description", "Server has started! You can now connect!");
	// 	dataThumb.SetField("url", "https://gamehag.com/img/rewards/logo/dayz.png");
		
	// 	dataJSON.m_body = dataBody;
	// 	dataJSON.m_thumbnail = dataThumb;
	// 	GetDiscordHook().SendHook("indep", dataJSON);
	// }
	
	// void ServerStopMessage()
	// {
	// 	ref DiscordJSON dataJSON = new DiscordJSON();
	// 	ref DiscordObject_Body dataBody = new DiscordObject_Body(11872553);
	// 	ref DiscordObject_Thumbnail dataThumb = new DiscordObject_Thumbnail(64, 64);
		
	// 	dataBody.SetField("title", "Server stopped...");
	// 	dataBody.SetField("description", "Server has been shutdown.");
	// 	dataThumb.SetField("url", "https://gamehag.com/img/rewards/logo/dayz.png");
		
	// 	dataJSON.m_body = dataBody;
	// 	dataJSON.m_thumbnail = dataThumb;
	// 	GetDiscordHook().SendHook("indep", dataJSON);
	// }
};