class DiscordHelper
{
	static int RGBToDecimal(int r, int g, int b)
	{
		return (r * 65536) + (g * 256) + b;
	}

	// Only used for string type
	static string GetJSONLineString(string field, string value)
	{
		return "\"" + field + "\":\"" + value + "\",";
	}
	
	// Used for type like integer, boolean, float...
	static string GetJSONLineOthers(string field, string value)
	{
		return "\"" + field + "\":" + value + ",";
	}

	static string RemoveExtraCommasJSON(string json)
	{
		bool isInsideText = false;

		for (int iChar = 1; (iChar + 1) < json.Length(); iChar++)
		{
			string prevChar = json.Substring((iChar - 1), 1);
			string actChar = json.Substring(iChar, 1);
			string nextChar = json.Substring((iChar + 1), 1);
			string firstPart;
			string secondPart;

			if (actChar == "\"")
			{
				isInsideText = !isInsideText;
			}
			if (!isInsideText && actChar == ",")
			{
				if ((nextChar != "\"" && nextChar != "[" && nextChar != "{") || (prevChar == "{" || prevChar == "["))
				{
					firstPart = json.Substring(0, iChar);
					secondPart = json.Substring((iChar + 1), (json.Length() - iChar - 1));
					json = firstPart + secondPart;
					iChar--;
				}
			}
		}
		return json;
	}
};