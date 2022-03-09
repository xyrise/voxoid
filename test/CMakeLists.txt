add_executable (voxoidTestRunner "testrunner.c")
target_link_libraries (voxoidTestRunner PRIVATE MinCTest)

target_include_directories (voxoidTestRunner
  PRIVATE
    "./"
)

add_subdirectory ("./empty")
