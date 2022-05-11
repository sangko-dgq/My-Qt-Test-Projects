# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FileSync_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FileSync_autogen.dir\\ParseCache.txt"
  "FileSync_autogen"
  )
endif()
