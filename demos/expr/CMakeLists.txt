set(SRC_EXPRS
expr-impl.h expr.h expr.c exprf.c exprfa.c exprq.c exprqa.c exprv.c exprz.c exprza.c exprqa.c exprv.c exprz.c exprza.c
)
set(ALL_LIBS
gmp mpz mpf mpn mpn_asm mpq rand printf)

add_library(exprlib ${SRC_EXPRS})

add_executable(run-expr run-expr.c)
target_link_libraries(run-expr ${ALL_LIBS} exprlib)
add_executable(t-expr t-expr.c ${PROJECT_SOURCE_DIR}/tests/misc.c ${PROJECT_SOURCE_DIR}/tests/memory.c ${exprs})
target_include_directories(t-expr PRIVATE ${PROJECT_SOURCE_DIR}/tests/)
target_link_libraries(t-expr ${ALL_LIBS} exprlib)

