#pragma once

#include <in\InfinitTypes.h>

namespace in { namespace manager {

	class Manageable
	{
	protected:
		INString m_Name;
	protected:
		Manageable(const INString& name) : m_Name(name) {}
	public:
		const INString& GetName() const { return m_Name; }
	};

} }