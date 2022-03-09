cmake_minimum_required (VERSION 3.13)

project (voxoid
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "https://github.com/xyrise/voxoid"
  LANGUAGES C
)
set (PROJECT_NAME "voxoid")
set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED 11)

add_executable (${PROJECT_NAME} "")

include (cmake/CompileOptions.cmake)
include (cmake/Libraries.cmake)

target_include_directories (${PROJECT_NAME}
  PRIVATE
    "./include/${PROJECT_NAME}"
)

target_link_libraries (${PROJECT_NAME} raylib)

add_subdirectory ("./src")

install (
  TARGETS
    ${PROJECT_NAME}
  DESTINATION
    bin
)
