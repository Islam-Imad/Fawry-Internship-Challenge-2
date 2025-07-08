add_library(
    book_store_lib
    "subscribers.cc"
    "BookStore.cc"
    "ProductProperty.cc"
    "Product.cc"
)

target_include_directories(
    book_store_lib
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)