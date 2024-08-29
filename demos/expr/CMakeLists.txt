set(SRC_EXPRS
    expr-impl.h 
    expr.h expr.c exprf.c exprfa.c exprq.c exprqa.c exprv.c exprz.c exprza.c exprqa.c exprv.c exprz.c exprza.c
)

add_library(exprlib ${SRC_EXPRS})

add_executable(run-expr run-expr.c)
target_link_libraries(run-expr ${LIBS} exprlib)

add_executable(t-expr t-expr.c )
target_link_libraries(t-expr ${LIBS} exprlib tests)

target_include_directories(t-expr PRIVATE ${PROJECT_SOURCE_DIR}/tests/)
target_link_libraries(t-expr ${LIBS} exprlib)

