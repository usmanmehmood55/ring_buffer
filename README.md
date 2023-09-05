# Ring Buffer

A ring buffer, also known as a circular buffer or cyclic buffer, is a data structure
that is used to store a fixed amount of data in a contiguous memory space. The key 
characteristic of a ring buffer is that it is implemented as a circular array, where
the end of the buffer wraps around to the beginning of the buffer, forming a closed 
loop.

[![Build and Test](https://github.com/usmanmehmood55/ring_buffer/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/usmanmehmood55/ring_buffer/actions/workflows/build_and_test.yml)
[![codecov](https://codecov.io/github/usmanmehmood55/ring_buffer/graph/badge.svg?token=CZTTM7JXRB)](https://codecov.io/github/usmanmehmood55/ring_buffer) 

## Uses and Benefits

Ring buffers are commonly used in embedded systems, real-time applications, and data
acquisition systems where data needs to be continuously stored and processed. They
are also used in audio and video processing, where a fixed-size buffer is used to
store samples or frames for processing.

The ring buffer is an efficient data structure for storing data because it allows for
constant time insertion and removal of elements. Since the buffer has a fixed size,
the insertion and removal of elements can be done using pointer manipulation rather
than copying data. This makes it ideal for high-speed data acquisition and processing,
where the data is constantly being updated.

One of the main benefits of using a ring buffer is that it provides a simple way to
implement a first-in, first-out (FIFO) data structure. As new data is added to the
buffer, the oldest data is automatically removed, ensuring that the buffer always
contains the most recent data.

Another benefit of using a ring buffer is that it is very memory efficient. Since the
buffer has a fixed size, the memory allocation can be done once and reused repeatedly.
This is especially useful in embedded systems where memory is limited.


## Setup

Following tools are required to compile
- [CMake](https://cmake.org/)
- [Ninja](https://ninja-build.org/)
- [GCC](https://gcc.gnu.org/)

In the repository directory, use CMake and Ninja to build
```bash
cmake -GNinja -Bbuild
ninja -C build
```

To make a `Debug` build with coverage data,
```bash
cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug
ninja -C build
```

To run the test application
```bash
./build/ring_buffer.exe
```

## Files
```
ring_buffer
  |
  |- ring_buffer.h
  |- ring_buffer.c
  |- test.c
  |- Makefile 
```
- The library consists of [`ring_buffer.h`](include/ring_buffer.h) and 
  [`ring_buffer.c`](src/ring_buffer.c) files.
- The test and example code for using the library is provided in [`test.c`](test/test_ring_buffer.c)


## To Do

In the current implementation, the structure containing all the buffer's information
is visible and modifiable by external code, as it is placed in the header file.
```c
typedef struct ring_buffer
{
    double   *buffer; // pointer to the buffer
    uint16_t size;    // maximum size of the buffer
    uint16_t head;    // index of the current head element in the buffer
    double   sum;     // sum of all the elements in the buffer.
} ring_buffer;
```

This can cause issues. I plan on implementing it in a way that only the buffer's 
elements are visible to external code and things like `size`, `head`, and `sum` can
only be get, and not set by external code.