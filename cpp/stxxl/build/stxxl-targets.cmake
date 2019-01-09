# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget stxxl stxxl_static)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target stxxl
add_library(stxxl SHARED IMPORTED)

# Create imported target stxxl_static
add_library(stxxl_static STATIC IMPORTED)

# Import target "stxxl" for configuration "Debug"
set_property(TARGET stxxl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(stxxl PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/stxxl/build/lib/Debug/stxxl.lib"
  IMPORTED_LOCATION_DEBUG "C:/stxxl/build/lib/Debug/stxxl.dll"
  )

# Import target "stxxl_static" for configuration "Debug"
set_property(TARGET stxxl_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(stxxl_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/stxxl/build/lib/Debug/stxxl.lib"
  )

# Import target "stxxl" for configuration "Release"
set_property(TARGET stxxl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(stxxl PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/stxxl/build/lib/Release/stxxl.lib"
  IMPORTED_LOCATION_RELEASE "C:/stxxl/build/lib/Release/stxxl.dll"
  )

# Import target "stxxl_static" for configuration "Release"
set_property(TARGET stxxl_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(stxxl_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/stxxl/build/lib/Release/stxxl.lib"
  )

# Import target "stxxl" for configuration "MinSizeRel"
set_property(TARGET stxxl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stxxl PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/stxxl/build/lib/MinSizeRel/stxxl.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/stxxl/build/lib/MinSizeRel/stxxl.dll"
  )

# Import target "stxxl_static" for configuration "MinSizeRel"
set_property(TARGET stxxl_static APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stxxl_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "C:/stxxl/build/lib/MinSizeRel/stxxl.lib"
  )

# Import target "stxxl" for configuration "RelWithDebInfo"
set_property(TARGET stxxl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(stxxl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/stxxl/build/lib/RelWithDebInfo/stxxl.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/stxxl/build/lib/RelWithDebInfo/stxxl.dll"
  )

# Import target "stxxl_static" for configuration "RelWithDebInfo"
set_property(TARGET stxxl_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(stxxl_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/stxxl/build/lib/RelWithDebInfo/stxxl.lib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
