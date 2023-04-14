#include <stdio.h>
#include "ring_buffer/ring_buffer.h"

#define ERR_CHECK(err) ( (err != 0) ? (ERROR_CHECK(err, __LINE__)) : ((int)err) )

static inline void ERROR_CHECK(int err, int line)
{
    printf("\rError on line %d\n", line);
    exit(err);
}

int main(void)
{
    int err = 0;

    ring_buffer buffer;

    ERR_CHECK(ring_buffer_create(&buffer, 5));

    ERR_CHECK(ring_buffer_add(&buffer, 1.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 2.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 3.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 4.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 5.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 6.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_add(&buffer, 7.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_destroy(&buffer));

    ERR_CHECK(ring_buffer_add(&buffer, 8.0));
    ring_buffer_print(&buffer);

    ERR_CHECK(ring_buffer_destroy(&buffer));

    return 0;
}