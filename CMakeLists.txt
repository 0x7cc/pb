
cmake_minimum_required(VERSION 3.13)

project(pb)
set(CMAKE_CXX_STANDARD 11)

if ( NOT _0x7cc_sys_root )
  message(FATAL_ERROR "_0x7cc_sys_root not set.")
endif()

link_directories(${_0x7cc_sys_root}/lib/)
include_directories(${_0x7cc_sys_root}/include/)

set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY         ${PROJECT_SOURCE_DIR}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         ${PROJECT_SOURCE_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/bin/debug/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/bin/debug/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/release/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/release/)

##################################################

add_library(pb
  src/pb.c
  src/pb_win.c
  src/pb_x.c
  src/term.c
  src/term_win.c
  src/term_x.c
)

target_include_directories(
  pb
  PUBLIC

  ${CMAKE_CURRENT_LIST_DIR}/include/
)

##################################################

add_executable(pb1
  samples/sample01.c
)

target_link_libraries(
  pb1
  PUBLIC

  pb
)


