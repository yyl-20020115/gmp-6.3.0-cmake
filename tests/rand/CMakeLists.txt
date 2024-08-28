if(CMAKE_SYSTEM_NAME MATCHES "Windows")
add_definitions(-D_USE_MATH_DEFINES)
endif()
set(LIBSTAT_SRC_FILES findlc.c zdiv_round.c stat.c statlib.c)

add_library(stat ${LIBSTAT_SRC_FILES})
target_include_directories(stat PRIVATE ${CMAKE_SOURCE_DIR}/tests)

set(LIBS ${LIBS} stat)

build_test(rand t-iset)
build_test(rand t-lc2exp)
build_test(rand t-mt)
build_test(rand t-rand)
build_test(rand t-urbui)
build_test(rand t-urmui)
build_test(rand t-urndmm)

set(TEST_TARGETS ${LOCAL_TARGETS} ${TEST_TARGETS} PARENT_SCOPE)

