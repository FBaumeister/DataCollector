# Enumerate and add
file(GLOB test_files "test_*.cpp")

foreach(source_file ${test_files})

    # Remove leading path and file ending
    get_filename_component(TESTNAME ${source_file} NAME_WE)
    set(TARGETNAME ${TESTNAME})

    # Create the Testtarget
    add_executable(${TESTNAME} ${source_file})
    target_link_libraries(${TARGETNAME} PUBLIC GTest::gtest_main GTest::gtest)
    target_include_directories(${TARGETNAME} PRIVATE $<TARGET_PROPERTY:CollectorService,INCLUDE_DIRECTORIES>)

    # Create the Test from this Target
    add_test(NAME ${TESTNAME} COMMAND ${TARGETNAME})
    # Some properties
    set_tests_properties(${TESTNAME} PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set_tests_properties(${TESTNAME} PROPERTIES TIMEOUT 20)
    set_tests_properties(${TESTNAME} PROPERTIES LABELS UT_CollectorService)

endforeach()
