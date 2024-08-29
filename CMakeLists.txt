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
    asl.h
    config.h
    fac_table.h
    fib_table.h
    gmp-impl.h
    gmp-mparam.h
    gmp.h
    gmpxx.h
    longlong.h
    mp_bases.h
    sieve_table.h
    trialdivtab.h
    assert.c
    bootstrap.c
    compat.c
    errno.c
    extract-dbl.c
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
#    tal-reent.c
    tal-notreent.c
    version.c
)
add_library(gmp ${SRC_FILES})
set(TEST_TARGETS "")

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
add_subdirectory(tests)
# add_subdirectory(tune)
# add_subdirectory(doc)

#always make m4/m4.exe available on your PATH
add_executable(m4caller m4caller.cpp)

add_custom_target(gen_asm_files
    COMMAND m4caller  "${CMAKE_CURRENT_SOURCE_DIR}/mpn" 
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/mpn"
    DEPENDS m4caller
    COMMENT "Generating asm files with m4"
)

add_executable(gen-bases gen-bases.c)
target_link_libraries(gen-bases gmp)
add_executable(gen-fac gen-fac.c)
target_link_libraries(gen-fac gmp)
add_executable(gen-fib gen-fib.c)
target_link_libraries(gen-fib gmp)
add_executable(gen-jacobitab gen-jacobitab.c)
target_link_libraries(gen-jacobitab gmp)
add_executable(gen-psqr gen-psqr.c)
target_link_libraries(gen-psqr gmp)
add_executable(gen-sieve gen-sieve.c)
target_link_libraries(gen-sieve gmp)
add_executable(gen-trialdivtab gen-trialdivtab.c)
target_link_libraries(gen-trialdivtab gmp)

