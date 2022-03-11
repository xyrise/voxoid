target_sources (${PROJECT_NAME}
  PRIVATE
    "./voxoid.c"
)

add_subdirectory ("./state")
add_subdirectory ("./system")
