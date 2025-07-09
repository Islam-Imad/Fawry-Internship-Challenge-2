# Check if Google Test is installed
find_package(GTest QUIET)

if (NOT GTest_FOUND)
    message(STATUS "Google Test not found. Installing Google Test...")

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Set Google Test variables
set(google_test GTest::gtest GTest::gtest_main)

add_executable(
    basic
    basic.cc
)

target_link_libraries(
    basic
    book_store_lib
    ${google_test}
)

add_test(
    NAME basic
    COMMAND basic
)