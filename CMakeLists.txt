cmake_minimum_required(VERSION 3.5)  
project(gmp LANGUAGES C CXX)  

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
add_definitions(-D_WIN32)
enable_language(ASM ASM_NASM)
set(CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS asm)
set(CMAKE_ASM_NASM_COMPILER "C:/Program Files (x86)/yasm/bin/yasm.exe")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd\"4018\" /wd\"4144\" /wd\"4146\" /wd\"4148\" /wd\"4244\" /wd\"4167\" /wd\"4267\" /wd\"4996\"")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd\"4018\" /wd\"4144\" /wd\"4146\" /wd\"4148\" /wd\"4244\" /wd\"4167\" /wd\"4267\" /wd\"4996\"")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_definitions(-DLINUX)
endif()

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILES
    assert.c
    bootstrap.c
    compat.c
    errno.c
    extract-dbl.c
    gen-bases.c
    gen-fac.c
    gen-fib.c
    gen-jacobitab.c
    gen-psqr.c
    gen-sieve.c
    gen-trialdivtab.c
    invalid.c
    memory.c
    mp_bpl.c
    mp_clz_tab.c
    mp_dv_tab.c
    mp_get_fns.c
    mp_minv_tab.c
    mp_set_fns.c
    nextprime.c
    primesieve.c
#    tal-debug.c
    tal-notreent.c
    tal-reent.c
    version.c
)
add_library(gmp ${SRC_FILES})
target_compile_definitions(gmp PRIVATE -DWANT_TMP_NOTREENTRANT)

add_subdirectory(mini-gmp)
add_subdirectory(mpf)
add_subdirectory(mpq)
add_subdirectory(mpz)
add_subdirectory(printf)
add_subdirectory(rand)
add_subdirectory(scanf)
add_subdirectory(mpn)
add_subdirectory(cxx)
add_subdirectory(demos)
#add_subdirectory(tests)
# add_subdirectory(tune)
# add_subdirectory(doc)


add_executable(m4caller m4caller.cpp)
