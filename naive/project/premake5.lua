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

  location "%{wks.location}/projects"

  targetdir "../bin/"
  objdir "%{cfg.targetdir}/%{prj.name}/obj"

  includedirs{
    "../include",
    "../src",
    "../vendor/spdlog/include"

  }

  files { 
    "../include/**.h",
    "../src/**.cpp"
  }

  filter "system:windows"
    systemversion "latest"
    
  filter "configurations:Debug"
    defines { "NV_DEBUG" }
    symbols "on"
    
  filter "configurations:Release"
    defines { "NV_RELEASE" }
    optimize "on"