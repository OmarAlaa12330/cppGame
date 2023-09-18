cmake_minimum_required(VERSION 3.26)
project(Platformer)

set(CMAKE_CXX_STANDARD 20)


# Set the build type to Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# Or use Release for release builds
# set(CMAKE_BUILD_TYPE Release)

if(CMAKE_CXX_COMPILER_ID MATCHES STREQUAL"GNU" AND CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()


set(SOURCE_FILES
        src/main.cpp
        src/Player.cpp
        src/FrameRateController.cpp
        src/Math.cpp
        src/RenderWindow.cpp
        src/InputManager.cpp
        src/ResourceManager.cpp
        src/Renderable.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})


