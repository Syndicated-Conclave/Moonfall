cmake_minimum_required(VERSION 3.11)
project(Moonfall)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

add_subdirectory("lib/box2d")
set(B2D_INCS "lib/box2d/include")
link_directories("${CMAKE_BINARY_DIR}/lib/box2d/lib")

#### Practical 1 ####
add_executable(Moonfall main.cpp)
target_include_directories(Moonfall PRIVATE ${SFML_INCS} ${B2D_INCS})
target_link_libraries(Moonfall sfml-graphics box2d)



#### copying resources to build to access them ####
set_target_properties(Moonfall
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>
)


add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/resources"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/resources
)

add_dependencies(Moonfall copy_resources)