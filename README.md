# Dayz Discord Hook

This is a mod for the DayZ game, it is used on the server side only, and allows server creators with minimal effort to integrate Discord messages through the hooks provided by Discord.

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
- Download the zip file on Github [here](link)

OR

- Download the mod on steam workshop [here](link)
- Go to the path where steam is installed, and follow this path: 'Steam\steamapps\workshop\content\221100'
- Find the folder with the id 'place holder'
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

## Versioning

We use [SemVer](http://semver.org/) for versioning.

## API used

* [World Time API](http://worldtimeapi.org)