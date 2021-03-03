workspace "Tick"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Tick"
	location "Tick"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"TICK_PLATFORM_WINDOWS",
			"TICK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "TICK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TICK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TICK_DIST"
		symbols "On"


project "Sandbox"
	location "Tick"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Tick/vendor/spdlog/include",
		"Tick/src"
	}

	links
	{
		"Tick"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"TICK_PLATFORM_WINDOWS",
		}
	
	filter "configurations:Debug"
		defines "TICK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TICK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TICK_DIST"
		symbols "On"
 