#include "buffer.h"

#include <GL\glew.h>

namespace in { namespace graphics { namespace buffers {

	Buffer::Buffer(INUint target, INUint usage)
		: target(target), usage(usage)
	{
		glGenBuffers(1, &id);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &id);
	}

	void Buffer::Resize(INUint size)
	{
		this->size = size;
		glBufferData(target, size, NULL, usage);
	}

	void Buffer::SetData(INUint size, const void* data)
	{
		glBufferData(target, size, data, usage);
	}

	void Buffer::ReleasePointer()
	{
		glUnmapBuffer(target);
	}

	void* Buffer::MapBuffer(INUint flags)
	{
		return glMapBuffer(target, flags);
	}

	void Buffer::Bind()
	{
		glBindBuffer(target, id);
	}

	void Buffer::Unbind()
	{
		glBindBuffer(target, 0);
	}

} } }