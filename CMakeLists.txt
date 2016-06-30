project(psd)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_MACOSX_RPATH 1)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME
  "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_SOURCE_IGNORE_FILES
  "/build/;/.git/;/tmp/;~$;${CPACK_SOURCE_IGNORE_FILES}")
add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")
if (APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.7")
endif ()

set(CMAKE_INSTALL_LIBDIR lib)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(Threads REQUIRED)
find_package(ROOT REQUIRED)
string(REPLACE "." ";" VERSION_LIST ${ROOT_VERSION})
list(GET VERSION_LIST 0 ROOT_VERSION_MAJOR)
if (ROOT_VERSION_MAJOR GREATER 5)
  include(RootNewMacros)
endif (ROOT_VERSION_MAJOR GREATER 5)
include(root-utils)

option (OPENMP "Use OpenMP" ON)

if(OPENMP)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    option (USE_OPENMP "Use OpenMP" ON)
endif()
endif()

include_directories("${PROJECT_BINARY_DIR}")

if(PAR)
add_custom_target(par-all ALL)
endif()

include(CPack)

add_subdirectory(PSD)

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

