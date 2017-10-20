#include "vertexarray.h"

#include "bufferlayout.h"

#include <GL\glew.h>

namespace in { namespace graphics { namespace buffers {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}

	Buffer* VertexArray::GetBuffer(INUint index)
	{
		return m_Buffers[index];
	}

	void VertexArray::PushBuffer(Buffer* buffer)
	{
		m_Buffers.push_back(buffer);

		const std::vector<BufferLayoutType>& layout = buffer->layout.GetLayout();
		for (INUint i = 0; i < layout.size(); i++)
		{
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, layout[i].count, layout[i].type, layout[i].normalized ? GL_TRUE : GL_FALSE, buffer->layout.GetStride(), (const GLvoid*)layout[i].offset);
		}
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_ID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::Draw(INUint count) const
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, NULL);
	}

} } }