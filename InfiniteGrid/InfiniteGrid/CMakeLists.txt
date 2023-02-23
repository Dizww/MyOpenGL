
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE source CONFIGURE_DEPENDS *.hpp *.cpp)

add_executable(${PROJECT_NAME} ${source})

target_include_directories(${PROJECT_NAME} PRIVATE . .. include )
target_link_libraries(${PROJECT_NAME} PRIVATE  glfw glad common)
