cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



include_directories(/Library/Frameworks/GStreamer.framework/Versions/1.0/Headers)
include_directories(/Users/mexxik/.node-gyp/0.12.2/src)
include_directories(/Users/mexxik/.node-gyp/0.12.2/deps/v8/src)

find_library(GSTREAMER_LIBRARY GStreamer)



project(tutorial_01)

set(SOURCE_FILES_01 tutorials/tutorial_01.c)
add_executable(tutorial_01 ${SOURCE_FILES_01})

target_link_libraries(tutorial_01 ${GSTREAMER_LIBRARY})



project(tutorial_02)

set(SOURCE_FILES_02 tutorials/tutorial_02.c)
add_executable(tutorial_02 ${SOURCE_FILES_02})

target_link_libraries(tutorial_02 ${GSTREAMER_LIBRARY})