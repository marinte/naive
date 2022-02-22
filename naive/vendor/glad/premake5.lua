project "Glad"
  kind "StaticLib"
  language "C"
 
  location "%{wks.location}/projects"

  targetdir "bin/"
  objdir "%{cfg.targetdir}/%{prj.name}/obj"

  includedirs{
    "include"
  }

  files { 
    "include/glad/glad.h",
    "include/KHR/khrplatform.h",
    "src/glad.c"
  }

  filter "system:windows"
    systemversion "latest"
    staticruntime "on"
    
  filter "configurations:Debug"
    runtime "Debug"
    symbols "on"
    
  filter "configurations:Release"
    runtime "Release"
    optimize "on"