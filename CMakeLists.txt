cmake_minimum_required(VERSION 3.6)
project(console_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES cge/test.cpp cge/system/terminal.cpp cge/system/terminal.h cge/object/game_object.cpp cge/object/game_object.h cge/object/component.h cge/object/components/position.cpp cge/object/components/position.h cge/object/components/texture.cpp cge/object/components/texture.h cge/system/render.cpp cge/system/render.h cge/map/room.cpp cge/map/room.h cge/global.h cge/loader.cpp cge/test.h cge/global.cpp)

include_directories(cge/ cge/object cge/object/components cge/system cge/map)
add_executable(console_engine ${SOURCE_FILES})