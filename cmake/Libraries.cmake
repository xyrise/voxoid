cmake_minimum_required (VERSION 3.11)
include (FetchContent)

# Declarations
FetchContent_Declare (
  MinCTest
  URL https://github.com/xyrise/MinCTest/archive/refs/tags/v0.0.2.tar.gz
)
FetchContent_Declare (
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
)


# Populate
FetchContent_Populate (MinCTest)
add_subdirectory (${minctest_SOURCE_DIR})

FetchContent_Populate (raylib)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
