cmake_minimum_required(VERSION 3.10)

project (dump740 C)

set(VERSION_INFO_MAJOR_VERSION 0)
set(VERSION_INFO_MINOR_VERSION 1)
set(VERSION_INFO_PATCH_VERSION 11)

add_definitions(-DVERSION_MAJOR=${VERSION_INFO_MAJOR_VERSION})
add_definitions(-DVERSION_MINOR=${VERSION_INFO_MINOR_VERSION})
add_definitions(-DVERSION_PATCH=${VERSION_INFO_PATCH_VERSION})
add_definitions("-O3 -Wall")

set(SOURCES
    src/decoder.c
    src/dump740.c
    src/options.c
    src/receiver.c
    src/routines.c
    src/thread.c)

# Define the library
add_library(dump740 SHARED ${SOURCES})

# Include headers
target_include_directories(dump740 PUBLIC include)

# Define the export macro for Windows
target_compile_definitions(dump740 PRIVATE DUMP740_EXPORTS)


include(FindPkgConfig)
pkg_check_modules(LIBRTLSDR librtlsdr)
include_directories(${LIBRTLSDR_INCLUDE_DIRS})
target_link_libraries (dump740 pthread m ${LIBRTLSDR_LIBRARIES})

add_executable(dump740_app example/example.c)

target_link_libraries(dump740_app PRIVATE dump740)

add_dependencies(dump740_app dump740)

set_target_properties(dump740_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)