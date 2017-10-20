#pragma once

#include <Infinit.h>

namespace in { namespace utils {

	static std::vector<INString> SplitString(const INString& string, const char delimiter)
	{
		size_t start = 0;
		size_t end = string.find_first_of(delimiter);

		std::vector<INString> result;

		while (end <= INString::npos)
		{
			result.emplace_back(string.substr(start, end - start));

			if (end == INString::npos)
				break;

			start = end + 1;
			end = string.find_first_of(delimiter, start);
		}

		return result;
	}

} }