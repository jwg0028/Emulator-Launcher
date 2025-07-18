# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EmuLauncher_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EmuLauncher_autogen.dir\\ParseCache.txt"
  "EmuLauncher_autogen"
  )
endif()
