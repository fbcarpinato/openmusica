cmake_minimum_required(VERSION 3.15)

project(OpenMusica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_GENERATOR "Ninja")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(OpenMusica
  src/main.cpp
)

target_link_libraries(OpenMusica PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

if (UNIX)
  find_package(Qt6 COMPONENTS WaylandClient REQUIRED)
  target_link_libraries(OpenMusica PRIVATE Qt6::WaylandClient)
endif()
