#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
namespace Tick {
	class TICK_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

	private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define TICK_CORE_TRACE(...)       ::Tick::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TICK_CORE_INFO(...)        ::Tick::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TICK_CORE_WARN(...)        ::Tick::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TICK_CORE_ERROR(...)       ::Tick::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TICK_CORE_FATAL(...)       ::Tick::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define TICK_TRACE(...)            ::Tick::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TICK_INFO(...)             ::Tick::Log::GetClientLogger()->info(__VA_ARGS__)
#define TICK_WARN(...)             ::Tick::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TICK_ERROR(...)            ::Tick::Log::GetClientLogger()->error(__VA_ARGS__)
#define TICK_FATAL(...)            ::Tick::Log::GetClientLogger()->fatal(__VA_ARGS__)
