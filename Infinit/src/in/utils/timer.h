#pragma once

#include <windows.h>

namespace in { namespace utils {

	class Timer
	{
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}

		void Reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		float Elepsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_Frequency);
		}
	};

} }