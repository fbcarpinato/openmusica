cmake_minimum_required(VERSION 3.15)

project(OpenMusica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_GENERATOR "Ninja")
set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Gui Widgets Network NetworkAuth REQUIRED)

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/src/core)

set(SOURCES
    src/main.cpp
    src/core/MainWindow.cpp
    src/core/SpotifyAuth.cpp
    src/core/ConfigManager.cpp
)

set(HEADERS
  src/core/MainWindow.h
  src/core/SpotifyAuth.h
  src/core/ConfigManager.h
)

add_executable(OpenMusica
  ${SOURCES}
)

target_link_libraries(OpenMusica PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::NetworkAuth)

if (UNIX)
  find_package(Qt6 COMPONENTS WaylandClient REQUIRED)
  target_link_libraries(OpenMusica PRIVATE Qt6::WaylandClient)
endif()
