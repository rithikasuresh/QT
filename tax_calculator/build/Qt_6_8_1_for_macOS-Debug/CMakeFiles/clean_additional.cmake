# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/tax_calculator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tax_calculator_autogen.dir/ParseCache.txt"
  "tax_calculator_autogen"
  )
endif()
