# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\FSyncX_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FSyncX_autogen.dir\\ParseCache.txt"
  "FSyncX_autogen"
  )
endif()