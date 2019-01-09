#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "stxxl" for configuration "RelWithDebInfo"
set_property(TARGET stxxl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(stxxl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/stxxl.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stxxl )
list(APPEND _IMPORT_CHECK_FILES_FOR_stxxl "${_IMPORT_PREFIX}/lib/stxxl.lib" )

# Import target "stxxl_static" for configuration "RelWithDebInfo"
set_property(TARGET stxxl_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(stxxl_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/stxxl.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stxxl_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_stxxl_static "${_IMPORT_PREFIX}/lib/stxxl.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
