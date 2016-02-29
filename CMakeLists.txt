cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(tutorial_01)
project(tutorial_02)

if (${UNIX})
    include_directories(/usr/include/gstreamer-1.0)
    include_directories(/opt/gstreamer-sdk/include/glib-2.0)
    include_directories(/opt/gstreamer-sdk/lib/glib-2.0/include)

    FIND_LIBRARY(GSTREAMER_LIBRARY  NAMES gstreamer libgstreamer-1.0 gstreamer-1.0
                                    PATHS ${GSTREAMER_DIR}/bin ${GSTREAMER_DIR}/lib ${GSTREAMER_DIR}/win32/bin ${GSTREAMER_DIR}/bin/bin C:/gstreamer/bin ${GSTREAMER_DIR}/lib ${GSTREAMER_DIR}/win32/lib /usr/local/lib /usr/lib
                                    ENV LIB
                                    DOC "gstreamer library to link with"
                                    NO_SYSTEM_ENVIRONMENT_PATH)
elseif(${APPLE)
    include_directories(/Library/Frameworks/GStreamer.framework/Versions/1.0/Headers)
    include_directories(/Users/mexxik/.node-gyp/0.12.2/src)
    include_directories(/Users/mexxik/.node-gyp/0.12.2/deps/v8/src)

    find_library(GSTREAMER_LIBRARY GStreamer)
endif(${UNIX})





set(SOURCE_FILES_01 tutorials/tutorial_01.c)
add_executable(tutorial_01 ${SOURCE_FILES_01})

target_link_libraries(tutorial_01 ${GSTREAMER_LIBRARY})





set(SOURCE_FILES_02 tutorials/tutorial_02.c)
add_executable(tutorial_02 ${SOURCE_FILES_02})

target_link_libraries(tutorial_02 ${GSTREAMER_LIBRARY})