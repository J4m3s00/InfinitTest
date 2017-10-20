#pragma once

#include "buffer.h"

namespace in { namespace graphics { namespace buffers {

	class VertexArray
	{
	private:
		INUint m_ID;
		std::vector<Buffer*> m_Buffers;
	public:
		VertexArray();
		~VertexArray();

		Buffer* GetBuffer(INUint index = 0);

		void PushBuffer(Buffer* buffer);
		void Bind();
		void Unbind();

		INUint GetID() const { return m_ID; }

		void Draw(INUint indexCount) const;
	};

} } }