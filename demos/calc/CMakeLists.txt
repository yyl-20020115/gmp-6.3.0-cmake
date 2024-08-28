add_executable(calc 
    calc-common.h 
    calc-config.h 
    calc.c 
    calc.h 
    calclex.c 
    calcread.c 
    )
target_link_libraries(calc ${LIBS})