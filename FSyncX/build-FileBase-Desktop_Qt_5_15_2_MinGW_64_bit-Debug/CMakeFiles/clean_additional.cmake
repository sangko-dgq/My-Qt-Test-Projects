# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FileBase_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FileBase_autogen.dir\\ParseCache.txt"
  "FileBase_autogen"
  )
endif()
