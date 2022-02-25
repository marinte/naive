workspace "naive"
  configurations { "Debug", "Release" }
  platforms { "x64" }
  startproject "naive"

  filter "system:windows"
    location "../build/solution/vs2019" -- TODO: Add it modular depending on the visual studio version.
  filter {}

group "Dependencies"
  include "../vendor/glfw"
  include "../vendor/glad"
  include "../vendor/imgui"
group""

project "naive"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++17"
 
  debugdir "../data"
  location "%{wks.location}/projects"

  targetdir "../bin/"
  objdir "%{cfg.targetdir}/%{prj.name}/obj"

  includedirs{
    "../include",
    "../src",
    "../vendor/spdlog/include",
    "../vendor",
    "../vendor/glfw/include",
    "../vendor/glad/include",
    "../vendor/imgui",
    "../vendor/glm"
  }

  files { 
    "../include/**.h",
    "../src/**.h",
    "../src/**.cpp",
    "../vendor/minitrace/minitrace.h",
    "../vendor/minitrace/minitrace.c",
    "../vendor/glm/**.hpp",
    "../vendor/glm/**.inl"
  }

  defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

  links {
    "GLFW",
    "Glad",
    "ImGui"
  }

  filter "system:windows"
    systemversion "latest" 
    staticruntime "on"
    defines { "NV_PLATFORM_WINDOWS" }
    
  filter "configurations:Debug"
    defines { "NV_DEBUG", "MTR_ENABLED" }
    runtime "Debug"
    symbols "on"
    
  filter "configurations:Release"
    defines { "NV_RELEASE" }
    runtime "Release"
    optimize "on"