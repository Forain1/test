# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\learn_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\learn_autogen.dir\\ParseCache.txt"
  "learn_autogen"
  )
endif()
