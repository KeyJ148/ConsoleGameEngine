cmake_minimum_required(VERSION 3.6)
project(console_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES cge/system/test.cpp cge/io/terminal.cpp cge/io/terminal.h cge/object/game_object.cpp cge/object/game_object.h cge/object/component.h cge/object/components/position.cpp cge/object/components/position.h cge/object/components/texture.cpp cge/object/components/texture.h cge/io/render.cpp cge/io/render.h cge/map/room.cpp cge/map/room.h cge/system/global.h cge/system/loader.cpp cge/system/test.h cge/system/global.cpp cge/cycle/cycle.h cge/cycle/listener.h cge/cycle/cycle.cpp cge/cycle/listener.cpp)

include_directories(cge/ cge/object cge/object/components cge/system cge/map)
add_executable(console_engine ${SOURCE_FILES})