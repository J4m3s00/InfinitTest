#pragma once

#pragma warning (disable:4996)

//#include <in\infinit.h>

#include <in\String.h>

#include <in\maths\vec2.h>
#include <in\maths\vec3.h>
#include <in\maths\vec4.h>
#include <iostream>

#define INFINIT_LOG_LEVEL_INFO		0
#define INFINIT_LOG_LEVEL_WARN		1
#define INFINIT_LOG_LEVEL_ERROR		2
#define INFINIT_LOG_LEVEL_FATAL		3

#define INFINIT_LOG_LEVEL INFINIT_LOG_LEVEL_FATAL

namespace std
{
	template<typename T>
	std::string to_string(const T& t)
	{
		return std::string("[Unsupported type(") + typeid(T).name() + std::string(")!] (to_string)");
	}
}

namespace in {
	namespace internal {

		static char to_string_buffer[1024 * 10];
		static char sprintf_buffer[1024 * 10];

		extern void PlatformLogMessage(unsigned int level, const char* message);

		template <class T>
		struct has_iterator
		{
			template<class U> static char(&test(typename U::iterator const*))[1];
			template<class U> static char(&test(...))[2];
			static const bool value = (sizeof(test<T>(0)) == 1);
		};

		template <typename T>
		static const char* to_string(const T& t)
		{
			return to_string_internal<T>(t, std::integral_constant<bool, has_iterator<T>::value>());
		}

		template<>
		static const char* to_string<char>(char const& t)
		{
			return &t;
		}

		template<>
		static const char* to_string<char*>(char* const& t)
		{
			return t;
		}

		/*template<>
		static const char* to_string<int>(const int& t)
		{
		std::string string = std::to_string(t);
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
		}

		template<>
		static const char* to_string<unsigned int>(const unsigned int& t)
		{
		std::string string = std::to_string(t);
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
		}

		template<>
		static const char* to_string<double>(const double& t)
		{
		std::string string = std::to_string(t);
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
		}

		template<>
		static const char* to_string<long>(const long& t)
		{
		std::string string = std::to_string(t);
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
		}

		template<>
		static const char* to_string<float>(const float& t)
		{
		std::string string = std::to_string(t);
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
		}*/

		template<>
		static const char* to_string<unsigned char const*>(unsigned char const* const& t)
		{
			return (const char*)t;
		}

		template<>
		static const char* to_string<const char*>(const char* const& t)
		{
			return t;
		}

		template<>
		static const char* to_string<std::string>(const std::string& t)
		{
			return t.c_str();
		}

		template<>
		static const char* to_string<maths::vec2>(const maths::vec2& t)
		{
			std::string string = std::string("vec2: (") + std::to_string(t.x) + ", " + std::to_string(t.y) + ")";
			char* result = new char[string.length()];
			strcpy(result, &string[0]);
			return result;
		}

		template<>
		static const char* to_string<maths::vec3>(const maths::vec3& t)
		{
			std::string string = std::string("vec3: (") + std::to_string(t.x) + ", " + std::to_string(t.y) + ", " + std::to_string(t.z) + ")";
			char* result = new char[string.length()];
			strcpy(result, &string[0]);
			return result;
		}

		template<>
		static const char* to_string<maths::vec4>(const maths::vec4& t)
		{
			std::string string = std::string("vec2: (") + std::to_string(t.x) + ", " + std::to_string(t.y) + ", " + std::to_string(t.z) + ", " + std::to_string(t.w) + ")";
			char* result = new char[string.length()];
			strcpy(result, &string[0]);
			return result;
		}

		template <typename T>
		static const char* to_string_internal(const T& v, const std::true_type& ignored)
		{
			sprintf(to_string_buffer, "Container of size: %d, contents: %s", v.size(), format_iterators(v.begin(), v.end()).c_str());
			return to_string_buffer;
		}

		template <typename T>
		static const char* to_string_internal(const T& t, const std::false_type& ignored)
		{
			auto x = StringFormat::ToString(t);
			return strcpy(to_string_buffer, x.c_str());
		}

		template<typename First>
		static void print_log_internal(char* buffer, int& position, First&& first)
		{
			const char* formatted = in::internal::to_string<First>(first);
			int length = strlen(formatted);
			memcpy(&buffer[position], formatted, length);
			position += length;
		}

		template<typename First, typename... Args>
		static void print_log_internal(char* buffer, int& position, First&& first, Args... args)
		{
			const char* formatted = in::internal::to_string<First>(first);
			int length = std::strlen(formatted);
			memcpy(&buffer[position], formatted, length);
			position += length;
			if (sizeof...(Args))
				print_log_internal(buffer, position, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void log_message(int level, bool newline, Args... args)
		{
			char buffer[1024 * 10];
			int position = 0;
			print_log_internal(buffer, position, std::forward<Args>(args)...);

			if (newline)
			{
				buffer[position++] = '\n';
			}

			buffer[position] = 0;

			PlatformLogMessage(level, buffer);
		}
	}
}

#ifndef INFINIT_LOG_LEVEL
#define INFINIT_LOG_LEVEL INFINIT_LOG_LEVEL_FATAL
#endif

#if INFINIT_LOG_LEVEL >= INFINIT_LOG_LEVEL_FATAL
#define IN_FATAL(...) in::internal::log_message(INFINIT_LOG_LEVEL_FATAL, true, "Infinit		", __VA_ARGS__);
#else
#define IN_FATAL(...)
#endif

#if INFINIT_LOG_LEVEL >= INFINIT_LOG_LEVEL_ERROR
#define IN_ERROR(...) in::internal::log_message(INFINIT_LOG_LEVEL_ERROR, true,	"Infinit		", __VA_ARGS__);
#else
#define IN_ERROR(...)
#endif

#if INFINIT_LOG_LEVEL >= INFINIT_LOG_LEVEL_WARN
#define IN_WARNING(...) in::internal::log_message(INFINIT_LOG_LEVEL_WARN, true,	"Infinit		", __VA_ARGS__);
#else
#define IN_WARNING(...)
#endif

#if INFINIT_LOG_LEVEL >= INFINIT_LOG_LEVEL_INFO
#define IN_INFO(...) in::internal::log_message(INFINIT_LOG_LEVEL_INFO, true, "Infinit		", __VA_ARGS__);
#else
#define IN_INFO(...)
#endif

#define IN_DEBUG

#ifdef IN_DEBUG 
#define INFINIT_ASSERT(x, ...) \
	if (!x) {\
	IN_FATAL("|---------------|")\
	IN_FATAL("ASSERTION FAILED!")\
	IN_FATAL("|---------------|")\
	IN_FATAL(__FILE__, ", ", __FUNCTION__, "(l. ", __LINE__, ")")\
	IN_FATAL(__VA_ARGS__) \
	__debugbreak(); \
	}
#else
#defiene INFINIT_ASSERT(x, ...)
#endif