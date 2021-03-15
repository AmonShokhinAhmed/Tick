#pragma once
#include <memory>
#include "Core.h"
//using the spdlog library
#include "spdlog/spdlog.h"

namespace Tick {
	//Static logging class, for use by engine and client application
	class TICK_API Log
	{
	public:
		//Call Init before using any functionality
		static void Init();
		//Getter
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

	private:
	//Two different loggers depending on who wants to log something, the client application or the Tick engine
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Defines to make accessing the functionality easier
#define LOG_CORE_TRACE(...)       ::Tick::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)        ::Tick::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)        ::Tick::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)       ::Tick::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...)       ::Tick::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define LOG_TRACE(...)            ::Tick::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)             ::Tick::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)             ::Tick::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)            ::Tick::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)            ::Tick::Log::GetClientLogger()->fatal(__VA_ARGS__)
