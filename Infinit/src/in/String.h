#pragma once

#include "InfinitTypes.h"

typedef std::string String;

namespace in {

#define STRINGFORMAT_BUFFER_SIZE 10 * 1024

	class StringFormat
	{
	private:
		static char* s_Buffer;
	public:
		template<typename T>
		static String Hex(const T& input)
		{
			memset(s_Buffer, 0, STRINGFORMAT_BUFFER_SIZE);
			sprintf(s_Buffer, "%02x", input);
			return String(s_Buffer);
		}

		template<typename T>
		static String Hex(const T* input, INUint size)
		{
			memset(s_Buffer, 0, STRINGFORMAT_BUFFER_SIZE);
			for (uint i = 0; i < size; i++)
				sprintf(s_Buffer + i * 3, "%02x ", input[i]);
			return String(s_Buffer);
		}

		static String Float(const float input, INUint places = 2)
		{
			memset(s_Buffer, 0, STRINGFORMAT_BUFFER_SIZE);
			sprintf(s_Buffer, "%.2f", input);
			return String(s_Buffer);
		}

		template<typename T>
		static String ToString(const T& input)
		{
			return std::to_string(input);
		}
	};

	std::vector<String> SplitString(const String& string, const String& delimiters);
	std::vector<String> SplitString(const String& string, const char delimiter);
	std::vector<String> Tokenize(const String& string);
	std::vector<String> GetLines(const String& string);

	const char* FindToken(const char* str, const String& token);
	const char* FindToken(const String& string, const String& token);
	int FindStringPosition(const String& string, const String& search, INUint offset = 0);
	String RemoveStringRange(const String& string, INUint start, INUint length);

	String GetBlock(const char* str, const char** outPosition = nullptr);
	String GetBlock(const String& string, INUint offset = 0);

	String GetStatement(const char* str, const char** outPosition = nullptr);

	bool StartsWith(const String& string, const String& start);
	int NextInt(const String& string);

}
