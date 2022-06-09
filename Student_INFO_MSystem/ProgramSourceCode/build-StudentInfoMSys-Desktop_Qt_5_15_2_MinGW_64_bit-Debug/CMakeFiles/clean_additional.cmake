# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\StudentInfoMSys_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\StudentInfoMSys_autogen.dir\\ParseCache.txt"
  "StudentInfoMSys_autogen"
  )
endif()
