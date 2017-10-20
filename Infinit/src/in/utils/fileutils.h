#pragma once

#include <Infinit.h>
#include "log.h"

namespace in { namespace utils {

	static INString ReadFile(const INString& path)
	{
		FILE* file;
		fopen_s(&file, path.c_str(), "rt");
		if (file == nullptr)
		{
			IN_WARNING("Could not find file ", path);
			return "";
		}

		fseek(file, 0, SEEK_END);
		INULong length = ftell(file);
		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);

		INString result(data);
		delete[] data;
		return result;
	}

	void WriteBytes(FILE* file, const INByte* data, INUint size);

	INByte* ReadBytes(FILE* file, INByte* buffer, INUint size);

} }