project("Crestone")
cmake_minimum_required(VERSION 3.22)

# Crestone-lib
add_library("crestone-lib"
  "src/common.hpp"
  "src/debug.cpp"
  "src/debug.hpp"
  "src/emulator.cpp"
  "src/emulator.hpp"
  "src/emulatorstate.cpp"
  "src/emulatorstate.hpp"
)

target_link_directories("crestone-lib" PRIVATE
  ./libs/SFML/lib
)

target_include_directories("crestone-lib" PRIVATE
  ./libs/SFML/include
)

target_link_libraries("crestone-lib"
  sfml-window
  sfml-system
  sfml-graphics
)

# Crestone-exe
add_executable("crestone-exe" "src/main.cpp")
target_link_libraries("crestone-exe" PRIVATE "crestone-lib")

target_link_directories("crestone-exe" PRIVATE
  ./libs/SFML/lib
)

target_include_directories("crestone-exe" PRIVATE
  ./libs/SFML/include
)

target_link_libraries("crestone-exe" PRIVATE
  sfml-window
  sfml-system
  sfml-graphics
)