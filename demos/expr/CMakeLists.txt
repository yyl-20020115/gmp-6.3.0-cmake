set(exprs
expr-impl.h expr.h expr.c exprf.c exprfa.c exprq.c exprqa.c exprv.c exprz.c exprza.c exprqa.c exprv.c exprz.c exprza.c
)
set(libs
gmp mpz mpf mpn mpn_asm mpq rand printf)

add_executable(expr ${exprs})
target_link_libraries(expr ${libs})

add_executable(run-expr run-expr.c ${exprs})
target_link_libraries(run-expr ${libs})
add_executable(t-expr t-expr.c ${PROJECT_SOURCE_DIR}/tests/misc.c ${PROJECT_SOURCE_DIR}/tests/memory.c ${exprs})
target_include_directories(t-expr PRIVATE ${PROJECT_SOURCE_DIR}/tests/)
target_link_libraries(t-expr ${libs})

