set(LIBS gmp mpq mpf mpz mpn mpn-asm rand printf)
add_subdirectory(calc)
add_subdirectory(expr)
#add_subdirectory(perl)

add_executable(isprime isprime.c)
target_link_libraries(isprime ${LIBS})

add_executable(factorize factorize.c )
target_link_libraries(factorize ${LIBS})

add_executable(pexpr pexpr.c)
target_link_libraries(pexpr ${LIBS})

add_executable(primes primes.c)
target_link_libraries(primes ${LIBS})

add_executable(qcn qcn.c)
target_link_libraries(qcn ${LIBS})

