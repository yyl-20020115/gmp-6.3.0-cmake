build_test(devel try)
build_test(devel sqrtrem_1_2)
build_test(devel primes-dev)
build_test(devel gen-test-longlong_h)

set(TEST_TARGETS ${LOCAL_TARGETS} ${TEST_TARGETS} PARENT_SCOPE)
