class CfgPatches
{
	class discordhook_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};

class CfgMods
{
	class discordhook
	{
		dir = "@DiscordHook";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Discord Hook";
		credits = "";
		author = "DjCtavia";
		authorID = "0"; 
		version = "1.0.0"; 
		extra = 0;
		type = "mod";
		
		dependencies[] = {"Game", "Mission", "World"};

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"discordhook/scripts/3_Game"};
			}

			class worldScriptModule
			{
				value = "";
				files[] = {"discordhook/scripts/4_World"};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {"discordhook/scripts/5_Mission"};
			};
		};
	};
};