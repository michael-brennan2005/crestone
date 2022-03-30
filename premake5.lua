workspace "Crestone"
    configurations { "Debug", "Release" }

project "Crestone"
    kind "ConsoleApp"
    language "C++"
    files { "src/*.hpp", "src/*.cpp"}
    
    libdirs { "libs/SFML/lib" }
    includedirs { "libs/SFML/include" }
    links { "sfml-window", "sfml-system", "sfml-graphics" }

    