build_test(mpn logic)
build_test(mpn t-addaddmul)
build_test(mpn t-aors_1
    ${CMAKE_SOURCE_DIR}/mpn/sec_add_1.c)
    target_compile_definitions(
    t-aors_1-mpn PRIVATE 
    -DOPERATION_sec_add_1
)

build_test(mpn t-asmtype)
build_test(mpn t-bdiv)
build_test(mpn t-broot)
build_test(mpn t-brootinv)

build_test(mpn t-div 
    ${CMAKE_SOURCE_DIR}/mpn/sec_div_qr.c 
    ${CMAKE_SOURCE_DIR}/mpn/sec_pi1_div_qr.c)
target_compile_definitions(
    t-div-mpn PRIVATE 
    -DOPERATION_sec_div_qr
    -DOPERATION_sec_pi1_div_qr)

build_test(mpn t-divrem_1)
build_test(mpn t-fat)
build_test(mpn t-fib2m)
build_test(mpn t-gcdext_1)
build_test(mpn t-gcd_11)
build_test(mpn t-gcd_22)
build_test(mpn t-get_d)
build_test(mpn t-hgcd)
build_test(mpn t-hgcd_appr)
build_test(mpn t-instrument)
build_test(mpn t-invert)
build_test(mpn t-iord_u)
build_test(mpn t-matrix22)
build_test(mpn t-minvert 
${CMAKE_SOURCE_DIR}/mpn/sec_add_1.c)
target_compile_definitions(
    t-minvert-mpn PRIVATE 
    -DOPERATION_sec_add_1
)
    
    
build_test(mpn t-mod_1)
build_test(mpn t-mp_bases)
build_test(mpn t-mul)
build_test(mpn t-mullo)
build_test(mpn t-mulmid)
build_test(mpn t-mulmod_bknp1)
build_test(mpn t-mulmod_bnm1)
build_test(mpn t-perfsqr)
build_test(mpn t-scan)
build_test(mpn t-sizeinbase)
build_test(mpn t-sqrlo)
build_test(mpn t-sqrmod_bknp1)
build_test(mpn t-sqrmod_bnm1)
build_test(mpn t-toom2-sqr)
build_test(mpn t-toom22)
build_test(mpn t-toom3-sqr)
build_test(mpn t-toom32)
build_test(mpn t-toom33)
build_test(mpn t-toom4-sqr)
build_test(mpn t-toom42)
build_test(mpn t-toom43)
build_test(mpn t-toom44)
build_test(mpn t-toom52)
build_test(mpn t-toom53)
build_test(mpn t-toom54)
build_test(mpn t-toom6-sqr)
build_test(mpn t-toom62)
build_test(mpn t-toom63)
build_test(mpn t-toom6h)
build_test(mpn t-toom8-sqr)
build_test(mpn t-toom8h)

set(TEST_TARGETS ${LOCAL_TARGETS} ${TEST_TARGETS} PARENT_SCOPE)
