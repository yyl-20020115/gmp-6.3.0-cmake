set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

set(SRC_FILES 
    tests.h 
    trace.c 
    misc.c 
    memory.c 
    spinner.c
    refmpf.c
    refmpn.c
    refmpq.c
    refmpz.c
    )

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "ARM")
    set(SRC_FILES ${SRC_FILES}
        arm32check.c
    )
else()
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SRC_FILES ${SRC_FILES}
        amd64check.c
    )
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SRC_FILES ${SRC_FILES}
        x86check.c
    )
    else()
    message(STATUS "Unknown bitness build")
    endif()

endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(SRC_FILES ${SRC_FILES} 
    getopt.c 
    getopt.h 
    tailor.h)
endif()

set(LIBS gmp mpn mpn-asm mpz mpf mpq printf scanf rand tests)

add_library(tests ${SRC_FILES})

macro(build_test suffix name)
add_executable("${name}-${suffix}" ${name}.c ${ARGN})
target_link_libraries("${name}-${suffix}" ${LIBS})
target_compile_definitions("${name}-${suffix}" PRIVATE -D_CRT_SUPPRESS_RESTRICT)
target_include_directories("${name}-${suffix}" PRIVATE ${CMAKE_SOURCE_DIR}/tests)
set(LOCAL_TARGETS ${LOCAL_TARGETS} "${name}-${suffix}")
endmacro()

macro(build_test_cc suffix name)
add_executable("${name}-${suffix}" ${name}.cc ${ARGN})
target_link_libraries("${name}-${suffix}" ${LIBS})
target_compile_definitions("${name}-${suffix}" PRIVATE -D_CRT_SUPPRESS_RESTRICT)
target_include_directories("${name}-${suffix}" PRIVATE ${CMAKE_SOURCE_DIR}/tests)
set(LOCAL_TARGETS ${LOCAL_TARGETS} "${name}-${suffix}")
endmacro()


build_test(test t-bswap)
build_test(test t-constants)
build_test(test t-count_zeros)
build_test(test t-hightomask)
build_test(test t-modlinv)
build_test(test t-parity)
build_test(test t-popc)
build_test(test t-sub)

set(TEST_TARGETS ${LOCAL_TARGETS} ${TEST_TARGETS})

add_subdirectory(cxx)
add_subdirectory(devel)
add_subdirectory(misc)
add_subdirectory(mpf)
add_subdirectory(mpn)
add_subdirectory(mpq)
add_subdirectory(mpz)
add_subdirectory(rand)

#message(STATUS "TEST_TARGETS: ${TEST_TARGETS}")
LIST(REMOVE_ITEM TEST_TARGETS 
    "sqrtrem_1_2-devel"
    "try-devel" 
    "primes-dev-devel" 
    "gen-test-longlong_h-devel"
    "t-addaddmul-mpn")
#message(STATUS "TEST_TARGETS: ${TEST_TARGETS}")

add_executable(testsverifier testsverifier.cpp)

add_custom_target(do_tests
    COMMAND ${CMAKE_COMMAND} -E echo "Running tests"
    COMMAND testsverifier "${TEST_TARGETS}"
    DEPENDS testsverifier ${TEST_TARGETS}
    COMMENT "Test all targets"
)
