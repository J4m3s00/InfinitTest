#pragma once

#include <in\InfinitTypes.h>

namespace in { namespace graphics { namespace buffers {

	class IndexBuffer
	{
	private:
		INUint m_ID;
		INUint m_BufferCount;
	public:
		IndexBuffer(INUint* data, INUint count);
		~IndexBuffer();

		void Bind() const;
		
		void Unbind() const;

		INUint GetID() const { return m_ID; }

		inline INUint GetCount() { return m_BufferCount; }
	};

} } }