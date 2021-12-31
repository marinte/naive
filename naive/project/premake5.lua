workspace "naive"
  configurations { "Debug", "Release" }
  platforms { "x64" }

  filter "system:windows"
    location "../build/solution/vs2019" -- TODO: Add it modular depending on the visual studio version.
  filter {}

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
    "../vendor"
  }

  files { 
    "../include/**.h",
    "../src/**.cpp",
    "../vendor/minitrace/minitrace.h",
    "../vendor/minitrace/minitrace.c"
  }

  filter "system:windows"
    systemversion "latest"
    
  filter "configurations:Debug"
    defines { "NV_DEBUG", "MTR_ENABLED" }
    symbols "on"
    
  filter "configurations:Release"
    defines { "NV_RELEASE" }
    optimize "on"