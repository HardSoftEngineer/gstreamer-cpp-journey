cmake_minimum_required(VERSION 3.10)
project(gsthelloplugin CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GST REQUIRED
    gstreamer-1.0
    gstreamer-video-1.0
)

include_directories(
    ${GST_INCLUDE_DIRS}
    include
)

link_directories(${GST_LIBRARY_DIRS})

add_library(gsthelloplugin SHARED
    src/plugin.cpp
    src/gst_helloplugin.cpp
)

target_link_libraries(gsthelloplugin
    ${GST_LIBRARIES}
)

target_compile_options(gsthelloplugin PRIVATE ${GST_CFLAGS_OTHER})
