cmake_minimum_required(VERSION 3.6)
project(console_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES start.cpp system/terminal.cpp system/terminal.h object/game_object.cpp object/game_object.h object/component.h object/components/position.cpp object/components/position.h object/components/texture.cpp object/components/texture.h system/render.cpp system/render.h)

include_directories(object object/components system)
add_executable(console_engine ${SOURCE_FILES})