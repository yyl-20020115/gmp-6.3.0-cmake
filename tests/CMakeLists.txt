set(SRC_FILES 
    ${CMAKE_SOURCE_DIR}/tests/tests.h 
    ${CMAKE_SOURCE_DIR}/tests/trace.c 
    ${CMAKE_SOURCE_DIR}/tests/misc.c 
    ${CMAKE_SOURCE_DIR}/tests/memory.c 
    ${CMAKE_SOURCE_DIR}/tests/spinner.c
    ${CMAKE_SOURCE_DIR}/tests/refmpf.c
    ${CMAKE_SOURCE_DIR}/tests/refmpn.c
    ${CMAKE_SOURCE_DIR}/tests/refmpq.c
    ${CMAKE_SOURCE_DIR}/tests/refmpz.c
    )

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "ARM")
    set(SRC_FILES ${SRC_FILES}
        ${CMAKE_SOURCE_DIR}/tests/arm32check.c
    )
else()
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SRC_FILES ${SRC_FILES}
        ${CMAKE_SOURCE_DIR}/tests/amd64check.c
    )
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SRC_FILES ${SRC_FILES}
        ${CMAKE_SOURCE_DIR}/tests/x86check.c
    )
    else()
    message(STATUS "Unknown bitness build")
    endif()

endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(SRC_FILES ${SRC_FILES} 
    ${CMAKE_SOURCE_DIR}/tests/getopt.c 
    ${CMAKE_SOURCE_DIR}/tests/getopt.h 
    ${CMAKE_SOURCE_DIR}/tests/tailor.h)
endif()
add_library(tests ${SRC_FILES})

set(LIBS gmp mpn mpn_asm mpz mpf mpq printf scanf rand tests)



macro(build_test prefix name)
add_executable("${prefix}-${name}" ${name}.c )
target_link_libraries("${prefix}-${name}" ${LIBS})
target_compile_definitions("${prefix}-${name}" PRIVATE -D_CRT_SUPPRESS_RESTRICT)
target_include_directories("${prefix}-${name}" PRIVATE ${CMAKE_SOURCE_DIR}/tests)
endmacro()

macro(build_test_cc prefix name)
add_executable("${prefix}-${name}" ${name}.cc )
target_link_libraries("${prefix}-${name}" ${LIBS})
target_compile_definitions("${prefix}-${name}" PRIVATE -D_CRT_SUPPRESS_RESTRICT)
target_include_directories("${prefix}-${name}" PRIVATE ${CMAKE_SOURCE_DIR}/tests)
endmacro()


build_test(test t-bswap)
build_test(test t-constants)
build_test(test t-count_zeros)
build_test(test t-hightomask)
build_test(test t-modlinv)
build_test(test t-parity)
build_test(test t-popc)
build_test(test t-sub)

add_subdirectory(cxx)
add_subdirectory(devel)
add_subdirectory(misc)
add_subdirectory(mpf)
add_subdirectory(mpn)
add_subdirectory(mpq)
add_subdirectory(mpz)
add_subdirectory(rand)

