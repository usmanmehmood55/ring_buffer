#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ring_buffer.h"

static void test_ring_buffer_create(void)
{
    ring_buffer buf;
    int ret = ring_buffer_create(&buf, 10);

    assert(ret == 0);
    assert(buf.size == 10U);
    assert(buf.head == 0U);
    assert(buf.sum == 0);
    assert(buf.buffer != NULL);

    (void)ring_buffer_destroy(&buf);

    printf("\r%s passed\n", __func__);
}

static void test_ring_buffer_get_head_index(void)
{
    ring_buffer buf;
    int ret = ring_buffer_create(&buf, 10);
    assert(ret == 0);

    uint16_t head_index;
    ret = ring_buffer_get_head_index(&buf, &head_index);
    assert(ret == 0);
    assert(head_index == 0U);

    (void)ring_buffer_add(&buf, 1.0);
    (void)ring_buffer_add(&buf, 2.0);
    ret = ring_buffer_get_head_index(&buf, &head_index);
    assert(ret == 0);
    assert(head_index == 2U);

    (void)ring_buffer_destroy(&buf);

    printf("\r%s passed\n", __func__);
}

static void test_ring_buffer_add(void)
{
    ring_buffer buf;
    int ret = ring_buffer_create(&buf, 3);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 1.0);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 2.0);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 3.0);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 4.0);
    assert(ret == 0);

    double val;
    ret = ring_buffer_get(&buf, 0, &val);
    assert(ret == 0);
    assert(val == 2.0);

    ret = ring_buffer_get(&buf, 1, &val);
    assert(ret == 0);
    assert(val == 3.0);

    ret = ring_buffer_get(&buf, 2, &val);
    assert(ret == 0);
    assert(val == 4.0);

    ret = ring_buffer_destroy(&buf);
    assert(ret == 0);

    printf("\r%s passed\n", __func__);
}

static void test_ring_buffer_get(void)
{
    ring_buffer buf;
    int ret = ring_buffer_create(&buf, 3);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 1.0);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 2.0);
    assert(ret == 0);

    ret = ring_buffer_add(&buf, 3.0);
    assert(ret == 0);

    double val;
    ret = ring_buffer_get(&buf, 0, &val);
    assert(ret == 0);
    assert(val == 1.0);

    ret = ring_buffer_get(&buf, 1, &val);
    assert(ret == 0);
    assert(val == 2.0);

    ret = ring_buffer_get(&buf, 2, &val);
    assert(ret == 0);
    assert(val == 3.0);

    ret = ring_buffer_get(&buf, 3, &val);
    assert(ret != 0);

    (void)ring_buffer_destroy(&buf);

    printf("\r%s passed\n", __func__);
}

int main(void)
{
    test_ring_buffer_create();
    test_ring_buffer_get_head_index();
    test_ring_buffer_add();
    test_ring_buffer_get();
}