if (MSVC)
  target_compile_options (${PROJECT_NAME}
    PRIVATE
      /Wall
      /WX
      /wd4710
      /wd4711
      /wd5045
      /wd4820
      /wd4706
      /wd4255
      /wd4090
      /Qspectre
  )
  target_compile_definitions (${PROJECT_NAME}
    PRIVATE
      -D_CRT_SECURE_NO_WARNINGS
  )
else()
  target_compile_options (${PROJECT_NAME}
    PRIVATE
      -Wall
      -Wextra
      -pedantic
      -Werror
  )
endif()
