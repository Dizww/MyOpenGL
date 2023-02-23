project(common)

file(GLOB_RECURSE source CONFIGURE_DEPENDS *.hpp *.cpp)

add_library(common OBJECT ${source})

target_include_directories(common PUBLIC . .. include)
target_link_libraries(common PUBLIC glad)
