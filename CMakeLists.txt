cmake_minimum_required(VERSION 3.1)
project(GLFW-App)

# Add the GLFW library as a subdirectory
add_subdirectory(glfw)

# Specify your source files
set(APP_SRC
    main.cpp
)

# Create the executable
add_executable(App WIN32 ${APP_SRC})

# Link the executable with the GLFW library
target_link_libraries(App glfw)

# Exclude building the GLFW examples
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only" FORCE)