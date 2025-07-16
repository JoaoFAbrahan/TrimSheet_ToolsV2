# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TrimSheet_ToolsV2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TrimSheet_ToolsV2_autogen.dir\\ParseCache.txt"
  "TrimSheet_ToolsV2_autogen"
  )
endif()
