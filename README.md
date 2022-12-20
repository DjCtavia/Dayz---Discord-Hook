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

- Automatically created DH_DiscordConfigDataFile.json file, you only need to change!

```json
{
    "m_discordHookServerName": "HERE_SERVER_NAME",
    "m_discordHook": "HERE_LINK_DISCORD_HOOK"
}
```

## Versioning

We use [SemVer](http://semver.org/) for versioning.
