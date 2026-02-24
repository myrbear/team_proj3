# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appteam_proj3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appteam_proj3_autogen.dir\\ParseCache.txt"
  "appteam_proj3_autogen"
  )
endif()
