# Dayz Discord Hook

This is a mod for the DayZ game, it is used on the server side only, and allows server creators with minimal effort to integrate Discord messages through the hooks provided by Discord.

## Mod on Steam Workshop: [Link to steam](https://steamcommunity.com/sharedfiles/filedetails/?id=2094926525)

## Getting Started

The following instructions will detail the prerequisites, how to install the mod on a server. And we'll see how to link to Discord through a usage example.

### Prerequisites

```
- DayZ Server installed
- A slight knowledge base in code in general
```

### Installing

A step by step series of examples that tell you how to implement the mod on your server

#### 1.
```
- Download the zip file on Github https://github.com/DjCtavia/Dayz---Discord-Hook/archive/master.zip
if you decide to use this method, be careful, you'll need to pack it into PBO.

OR

- Download the mod on steam workshop https://steamcommunity.com/sharedfiles/filedetails/?id=2094926525
- Go to the path where steam is installed, and follow this path: 'Steam\steamapps\workshop\content\221100'
- Find the folder with the id '2094926525'
```

#### 2.
```
- Extract the folder inside 'Steam\steamapps\common\DayZServer'

OR

 - Copy the folder inside your DayZ Server: 'Steam\steamapps\common\DayZServer'
 - Rename it '@DiscordHook'
```

#### 3.
```
- Launch your server with at least this parameter: '-servermod="@DiscordHook"'
```

## How to create a mod using this mod ?

Just call the primary functions, call the right classes, more examples will be available later. For our current example, let's say we want to know when the server starts.

### Example

```c
void MissionServer()
{
    GetDiscordHook().SetAlias("YourAlias", "YourDiscordWebHookURL");
    // We call our method that will send a request to our discord hook
    ServerStartMessage();
}

void ServerStartMessage()
{
    // We init our discordJSON, that represent the data we will give to the hook
    ref DiscordJSON dataJSON = new DiscordJSON();
    // We choose the module we want to use, here we're using "body" and "thumbnail"
    ref DiscordObject_Body dataBody = new DiscordObject_Body(5019904);
    ref DiscordObject_Thumbnail dataThumb = new DiscordObject_Thumbnail(64, 64);

    // The "body" let us choose a color for or embed, have description and others things
    dataBody.SetField("title", "Server start!");
    dataBody.SetField("description", "Server has started! You can now connect!");
    // We set our image url, fields can be found inside the DiscordObject_Thumbnail class
    dataThumb.SetField("url", "https://gamehag.com/img/rewards/logo/dayz.png");
		
    // And we assign the Modules to our data converter
    dataJSON.m_body = dataBody;
    dataJSON.m_thumbnail = dataThumb;
    // And the library will finish the work, sending the hook to your discord server
    GetDiscordHook().SendHook("YourAlias", dataJSON);
}
```

## Versioning

We use [SemVer](http://semver.org/) for versioning.
