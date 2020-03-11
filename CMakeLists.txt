
cmake_minimum_required(VERSION 3.13)

project(pb)
set(CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)

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
  include/pb/internal/linked_list.h
  include/pb/internal/misc.h
  include/pb/internal/pb.h
  include/pb/internal/xstring.h
  include/pb/pb.h
  include/pb/term.h
  src/misc.c
  src/misc_win.c
  src/misc_x.c
  src/pb.c
  src/pb_win.c
  src/pb_x.c
  src/term.c
  src/term_win.c
  src/term_x.c
  src/xstring.c
)

target_include_directories(
  pb
  PUBLIC

  ${CMAKE_CURRENT_LIST_DIR}/include/
)

install(TARGETS pb DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/pb"  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

##################################################

add_executable(sample01
  samples/sample01.c
)

target_link_libraries(
  sample01
  PUBLIC

  pb
)


