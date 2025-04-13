cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
project(CPP_PRIMER)
message(STATUS "operating system: ${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_VERSION}")

# spdlog
#define SPDLOG_LEVEL_TRACE 0
#define SPDLOG_LEVEL_DEBUG 1
#define SPDLOG_LEVEL_INFO 2
#define SPDLOG_LEVEL_WARN 3
#define SPDLOG_LEVEL_ERROR 4
#define SPDLOG_LEVEL_CRITICAL 5
#define SPDLOG_LEVEL_OFF 6
add_compile_definitions(SPDLOG_ACTIVE_LEVEL=1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/spdlog)

# cpp_primer_library
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/source ALL_SOURCE)
add_library(cpp_primer_library STATIC ${ALL_SOURCE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/spdlog/include)

link_libraries(spdlog::spdlog cpp_primer_library)

add_executable(chapter_10 ${CMAKE_CURRENT_SOURCE_DIR}/app/chapter_10.cpp)
add_executable(chapter_11 ${CMAKE_CURRENT_SOURCE_DIR}/app/chapter_11.cpp)
