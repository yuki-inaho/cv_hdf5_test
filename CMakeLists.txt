cmake_minimum_required(VERSION 3.5.1)

# project set
set(PROJ_NAME h5test)
project(${PROJ_NAME})
set(SOURCE_CODE
        src/main.cpp
    )

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

include_directories(
        include
)

add_executable(${PROJ_NAME} ${SOURCE_CODE})

find_package(PkgConfig REQUIRED)
pkg_check_modules(OpenCV REQUIRED opencv)
include_directories(${OpenCV_CFLAGS})
target_link_libraries(${PROJ_NAME} ${OpenCV_LDFLAGS})

