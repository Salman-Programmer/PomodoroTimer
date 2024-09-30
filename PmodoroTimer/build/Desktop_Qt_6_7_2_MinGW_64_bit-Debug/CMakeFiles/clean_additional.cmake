# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PmodoroTimer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PmodoroTimer_autogen.dir\\ParseCache.txt"
  "PmodoroTimer_autogen"
  )
endif()
