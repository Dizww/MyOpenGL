project(glad)

file(GLOB_RECURSE glad_source CONFIGURE_DEPENDS   *.c)

add_library(glad  ${glad_source})
target_include_directories(glad PUBLIC include) 
     
