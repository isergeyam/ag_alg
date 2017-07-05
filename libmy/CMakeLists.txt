cmake_minimum_required (VERSION 2.6)
project(libmy)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB LIB_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  )
file(GLOB LIB_HDR
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
  )
add_library(my ${LIB_HDR} ${LIB_SRC})
