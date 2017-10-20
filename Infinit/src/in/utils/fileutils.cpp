#include "fileutils.h"

namespace in { namespace utils {


	void WriteBytes(FILE* file, const INByte* data, INUint size)
	{
		fwrite(data, 1, size, file);
	}

	INByte* ReadBytes(FILE* file, INByte* buffer, INUint size)
	{
		fread(buffer, 1, size, file);
		return buffer;
	}

} }