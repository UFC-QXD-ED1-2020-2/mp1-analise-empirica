cmake_minimum_required(VERSION 3.0.0)
project(analise-empirica VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/libs/ubench/)
include_directories(${CMAKE_SOURCE_DIR}/libs/argtable-3.1.5-amalgamation/)

add_executable(analise-empirica
    main.c
    benchmarks.c
    ordenacao/algoritmos.c
    ordenacao/gera_instancias.c
    libs/argtable-3.1.5-amalgamation/argtable3.c
    ordenacao/algoritmos.h
    ordenacao/gera_instancias.h
    libs/ubench/ubench.h
    libs/argtable-3.1.5-amalgamation/argtable3.h
)

add_compile_definitions(QXD_QXCODE_PROGNAME="${PROJECT_NAME}")

target_link_libraries(analise-empirica -lm)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set_source_files_properties(benchmarks.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra"
  )
  set_source_files_properties(ordenacao/algoritmos.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra"
  )
  set_source_files_properties(ordenacao/gera_instancias.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra"
  )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set_source_files_properties(benchmarks.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Weverything"
  )
  set_source_files_properties(ordenacao/algoritmos.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Weverything"
  )
  set_source_files_properties(ordenacao/gera_instancias.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Weverything"
  )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_source_files_properties(benchmarks.c PROPERTIES
    COMPILE_FLAGS "/Wall /WX /wd4514 /wd5045"
  )
  set_source_files_properties(ordenacao/algoritmos.c PROPERTIES
    COMPILE_FLAGS "/Wall /WX /wd4514 /wd5045"
  )
  set_source_files_properties(ordenacao/gera_instancias.c PROPERTIES
    COMPILE_FLAGS "/Wall /WX /wd4514 /wd5045"
  )
else()
  message(WARNING "Unknown compiler '${CMAKE_C_COMPILER_ID}'!")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
