# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.


# Find the nasm assembler. yasm (http://www.tortall.net/projects/yasm/) is nasm compatible

set(CMAKE_ASM_YASM_COMPILER_LIST nasm yasm)

if(NOT CMAKE_ASM_YASM_COMPILER)
  set(_CMAKE_ENV_VARX86 "ProgramFiles(x86)")
  set(_CMAKE_ASM_YASM_COMPILER_PATHS
    "[HKEY_CURRENT_USER\\SOFTWARE\\nasm]"
    "$ENV{ProgramFiles}/yasm"
    "$ENV{${ENV_VARX86}}/yasm"
    "$ENV{LOCALAPPDATA}/yasm"
    )
  find_program(CMAKE_ASM_YASM_COMPILER
    NAMES ${CMAKE_ASM_YASM_COMPILER_LIST}
    PATHS ${_CMAKE_ASM_YASM_COMPILER_PATHS}
    NO_DEFAULT_PATH
    DOC "YASM compiler"
  )
  unset(_CMAKE_ENV_VARX86)
  unset(_CMAKE_ASM_YASM_COMPILER_PATHS)
endif()

# Load the generic DetermineASM compiler file with the DIALECT set properly:
set(ASM_DIALECT "_YASM")
include(CMakeDetermineASMCompiler)
set(ASM_DIALECT)
