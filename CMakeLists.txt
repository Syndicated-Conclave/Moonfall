cmake_minimum_required(VERSION 3.14)
project(Moonfall)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin") # out/build/64x-debug vs build
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}")


#### Add External Dependencies ####
add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

add_subdirectory("lib/box2d")
set(B2D_INCS "lib/box2d/include")
link_directories("${CMAKE_BINARY_DIR}/lib/box2d/lib")


#### Add Executable ####
add_executable(Moonfall
engine/ecm.cpp 
  engine/physics.cpp
  engine/utils.cpp
  game/components/graphics.cpp
  game/components/physics.cpp
  game/entities/cityscape.cpp
  game/entities/moon.cpp
  game/entities/stardust.cpp
  game/scenes/level.cpp
  game/main.cpp
)
target_include_directories(Moonfall PRIVATE ${SFML_INCS} ${B2D_INCS} engine game)
target_link_libraries(Moonfall sfml-graphics box2d)


# Check Config type
if(CMAKE_CONFIGURATION_TYPES)
  SET(CONFIG_DIRECTORY $<CONFIGURATION>)
else()
  SET(CONFIG_DIRECTORY ${CMAKE_BUILD_TYPE})
endif()


#### copying resources to build to access them ####
set_target_properties(Moonfall
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CONFIG_DIRECTORY}
)

add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/resources"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CONFIG_DIRECTORY}/resources
)

add_dependencies(Moonfall copy_resources)


# copy all dll files to the right directory 

add_custom_command(
    TARGET Moonfall POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_RUNTIME_DLLS:Moonfall>
        $<TARGET_FILE_DIR:Moonfall>
    COMMAND_EXPAND_LISTS
)
