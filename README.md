# Ring Buffer

A ring buffer, also known as a circular buffer or cyclic buffer, is a data 
structure that is used to store a fixed amount of data in a contiguous memory 
space. The key characteristic of a ring buffer is that it is implemented as a 
circular array, where the end of the buffer wraps around to the beginning of 
the buffer, forming a closed loop.

[![Build and Test](https://github.com/usmanmehmood55/ring_buffer/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/usmanmehmood55/ring_buffer/actions/workflows/build_and_test.yml)
[![codecov](https://codecov.io/github/usmanmehmood55/ring_buffer/graph/badge.svg?token=CZTTM7JXRB)](https://codecov.io/github/usmanmehmood55/ring_buffer) 

## Uses and Benefits

Ring buffers are commonly used in embedded systems, real-time applications, 
and data acquisition systems where data needs to be continuously stored and 
processed. They are also used in audio and video processing, where a 
fixed-size buffer is used to store samples or frames for processing.

The ring buffer is an efficient data structure for storing data because it 
allows for constant time insertion and removal of elements. Since the buffer 
has a fixed size, the insertion and removal of elements can be done using 
pointer manipulation rather than copying data. This makes it ideal for 
high-speed data acquisition and processing, where the data is constantly being 
updated.

One of the main benefits of using a ring buffer is that it provides a simple 
way to implement a first-in, first-out (FIFO) data structure. As new data is 
added to the buffer, the oldest data is automatically removed, ensuring that 
the buffer always contains the most recent data.

Another benefit of using a ring buffer is that it is very memory efficient. 
Since the buffer has a fixed size, the memory allocation can be done once and 
reused repeatedly. This is especially useful in embedded systems where memory 
is limited.


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
  |- test_ring_buffer.c
  |- CMakeLists.txt 
```
- The library consists of [`ring_buffer.h`](ring_buffer.h) and 
  [`ring_buffer.c`](ring_buffer.c) files.
- The test and example code for using the library is provided in 
  [`test_ring_buffer.c`](test_ring_buffer.c)

## Notes

In the current implementation, To prevent any external code from being able to write to properties of the buffer like `size` and `head`, the structure for the buffer has been made available only to the source file 
[`ring_buffer.c`](ring_buffer.c).
```c
struct ring_buffer_t
{
    double   *buffer;    // pointer to the buffer
    uint16_t size;       // maximum size of the buffer
    uint16_t head;       // index of the current head element in the buffer
    double   sum;        // sum of all the elements in the buffer.
    uint16_t occupancy;  // number of elements currently in the buffer
};
```

The external code can use it's opaque type defined in the header file and this way it can only use the provided API to get any information it wants.
```c
typedef struct ring_buffer_t ring_buffer_t;
```

This however can be very counterintuitive because external code should be able
to read the data from this structure without having to resort to an API. But 
such is the nature of C language, I guess.