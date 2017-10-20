#pragma once

#include <in\InfinitTypes.h>
#include "bufferlayout.h"

#define GL_WRITE_ONLY 0x88B9

namespace in { namespace graphics { namespace buffers {

	struct Buffer
	{
		INUint id;
		INUint target, usage;
		INUint size;
		BufferLayout layout;

		Buffer(INUint target, INUint usage);
		~Buffer();

		void Resize(INUint size);
		void SetData(INUint size, const void* data);

		template<typename T>
		T* GetPointer(INUint flags = GL_WRITE_ONLY)
		{
			return (T*)MapBuffer(flags);
		}

		void ReleasePointer();

		void Bind();
		void Unbind();
	private:
		void* MapBuffer(INUint flags);
	};

} } }