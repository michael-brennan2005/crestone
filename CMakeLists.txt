project("crestone")
cmake_minimum_required(VERSION 3.22)

# doctest
add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ./libs/doctest)

# sfml
function(ADD_SFML target_name)
  target_link_directories(${target_name} PRIVATE
    ./libs/SFML/lib
  )

  target_include_directories(${target_name} PRIVATE
    ./libs/SFML/include
  )

  target_link_libraries(${target_name}
    sfml-window
    sfml-system
    sfml-graphics
  )
endfunction()

# crestone-lib
file(GLOB crestone-lib-files 
  ./src/crestone-lib/*.cpp 
  ./src/crestone-lib/*.hpp)

add_library(crestone-lib ${crestone-lib-files})
ADD_SFML(crestone-lib)

# crestone-exe
add_executable(crestone-exe src/main.cpp)
ADD_SFML(crestone-exe)

target_include_directories(crestone-exe
  PRIVATE
  ./src/crestone-lib)
  
target_link_libraries(crestone-exe
  crestone-lib)

# crestone-test
add_executable(crestone-test src/test.cpp)
ADD_SFML(crestone-test)

target_include_directories(crestone-test
  PRIVATE
  ./src/crestone-lib)
target_link_libraries(crestone-test
  crestone-lib
  doctest)