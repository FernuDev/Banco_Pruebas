# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Banco_Pruebas_autogen"
  "CMakeFiles/Banco_Pruebas_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Banco_Pruebas_autogen.dir/ParseCache.txt"
  )
endif()
