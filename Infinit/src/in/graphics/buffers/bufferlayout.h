#pragma once

#include <iostream>
#include <in\InfinitTypes.h>
#include <in\maths\Maths.h>

#define GL_FLOAT 0x1406
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405

namespace in { namespace graphics { namespace buffers {

	struct BufferLayoutType
	{
		INString name;
		INUint type;
		INUint size;
		INUint count;
		INUint offset;
		bool normalized;
	};

	class BufferLayout
	{
	private:
		INUint m_Size;
		std::vector<BufferLayoutType> m_Layout;
	public:
		BufferLayout();

		template<typename T>
		void Push(const INString& name, INUint count = 1, bool normalized = false)
		{
			IN_WARNING("Unknown buffertype!");
		}

		template<> void Push<float>(const INString& name, INUint count, bool normalized) { Push(name, GL_FLOAT, sizeof(float) * count, count, normalized); }
		template<> void Push<INUint>(const INString& name, INUint count, bool normalized) { Push(name, GL_UNSIGNED_INT, sizeof(INUint) * count, count, normalized); }
		template<> void Push<INByte>(const INString& name, INUint count, bool normalized) { Push(name, GL_UNSIGNED_BYTE, sizeof(INByte) * count, count, normalized); }
		template<> void Push<maths::vec2>(const INString& name, INUint count, bool normalized) { Push(name, GL_FLOAT, sizeof(maths::vec2) * count, 2 * count, normalized); }
		template<> void Push<maths::vec3>(const INString& name, INUint count, bool normalized) { Push(name, GL_FLOAT, sizeof(maths::vec3) * count, 3 * count, normalized); }
		template<> void Push<maths::vec4>(const INString& name, INUint count, bool normalized) { Push(name, GL_FLOAT, sizeof(maths::vec4) * count, 4 * count, normalized); }

		inline const std::vector<BufferLayoutType>& GetLayout() const { return m_Layout; }
		inline INUint GetStride() const { return m_Size; }
	private:
		void Push(const INString& name, INUint type, INUint size, INUint count, bool normalized);
	};

} } }