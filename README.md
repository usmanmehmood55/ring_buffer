# Ring Buffer

A ring buffer, also known as a circular buffer or cyclic buffer, is a data structure
that is used to store a fixed amount of data in a contiguous memory space. The key 
characteristic of a ring buffer is that it is implemented as a circular array, where
the end of the buffer wraps around to the beginning of the buffer, forming a closed 
loop.


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
- make
- gcc

In the repository directory, `make` and then execute the .exe file.
```bash
make
./ring_buffer.exe
```

## Example Code

The example code for using this ring buffer is provided in [`main.c`](main.c)


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