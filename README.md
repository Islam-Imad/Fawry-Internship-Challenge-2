# Fawry-Internship-Challenge-2
My solution to second Fawry challenge

[DeepWiki for this repo](https://deepwiki.com/Islam-Imad/Fawry-Internship-Challenge-2)

![Screenshot 1](./Screenshots/shot1.png)

## Project Structure

```text
Fawry-Internship-Challenge-2/
├── README.md
├── CMakeLists.txt
├── book_store.cc
├── include/
│   ├── BookStore.h
│   ├── EventType.h
│   ├── Product.h
│   ├── ProductCategory.h
│   ├── ProductProperty.h
│   └── subscribers.h
├── src/
│   ├── CMakeLists.txt
│   ├── BookStore.cc
│   ├── Product.cc
│   ├── ProductProperty.cc
│   └── subscribers.cc
├── test/
│   ├── CMakeLists.txt
│   └── basic.cc
└── Screenshots/
    └── shot1.png
```

## Building the Project

This project uses CMake as the build system. To build and run:

```bash
# Create build directory if it doesn't exist
mkdir -p build
cd build

# Configure the project
cmake ..

# Build the project
make

# Run the executable
./book_store
```

## Running Tests

To run the tests:

```bash
cd build
make test
# or run the test executable directly
./test/basic
```