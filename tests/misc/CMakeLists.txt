build_test(misc t-locale)
build_test(misc t-printf)
build_test(misc t-scanf)

set(TEST_TARGETS ${LOCAL_TARGETS} ${TEST_TARGETS} PARENT_SCOPE)
