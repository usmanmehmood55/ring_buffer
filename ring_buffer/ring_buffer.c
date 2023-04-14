/**
 * @file    ring_buffer.c
 * 
 * @author  Usman Mehmood (usmanmehmood55@gmail.com)
 * 
 * @brief   This is a C implementation of a ring buffer data structure, which is a
 *          fixed-size buffer that behaves like a circular queue. The code defines
 *          a ring_buffer structure that holds the buffer array, its size, the head
 *          (i.e., the index of the first element), and the sum of the values in 
 *          the buffer. The code provides functions for creating, adding to, 
 *          getting values from, and destroying a ring buffer, as well as printing
 *          the buffer contents and getting its size and sum.
 * 
 * @version 0.1
 * 
 * @date    14-04-2023
 * 
 * Copyright (c) 2023, Usman Mehmood
 * 
 */

#include "ring_buffer.h"

/**
 * @brief Creates a new ring buffer with the specified size.
 *
 * @param[in,out] p_buffer Pointer to the ring buffer to create.
 * @param[in]     size     Size of the ring buffer to create.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_create(ring_buffer *p_buffer, uint16_t size)
{
    if (size == 0U)
    {
        printf("\r%s: Cannot create ring buffer with size 0\n", __func__);
        return -EINVAL;
    }

    p_buffer->buffer = NULL;
    p_buffer->size   = size;
    p_buffer->head   = 0;
    p_buffer->sum    = 0;

    p_buffer->buffer = (double *)malloc(size * sizeof(double));
    if (p_buffer->buffer == NULL)
    {
        printf("\r%s: Failed to allocate memory for ring buffer\n", __func__);
        return -ENOMEM;
    }

    (void)memset(p_buffer->buffer, 0, size * sizeof(double));

    return 0;
}

/**
 * @brief Gets the index of the head element of a ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer.
 * @param[out] index    Pointer to the location to store the head index.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get_head_index(const ring_buffer *p_buffer, uint16_t *index)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Cannot get index from uninitialized buffer\n", __func__);
        return -EINVAL;
    }

    *index = p_buffer->head;

    return 0;
}

/**
 * @brief Adds an item to the ring buffer.
 *
 * If the buffer is already full, the oldest element is discarded to make
 * room for the new element.
 *
 * @param[in,out] p_buffer Pointer to the ring buffer to add the item to.
 * @param[in]     item     Item to add to the buffer.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_add(ring_buffer *p_buffer, double item)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Attempted to add item to uninitialized buffer\n", __func__);
        return -EFAULT;
    }

    if (p_buffer->size == 0U)
    {
        printf("\r%s: Cannot add item to buffer with size 0\n", __func__);
        return -EINVAL;
    }

    // I don't understand this part of the code
    if ((p_buffer->head == 0U) && (p_buffer->sum != 0U))
    {
        // Buffer overflow, discarding oldest value
        p_buffer->sum -= p_buffer->buffer[p_buffer->size - 1U];
    }
    else if ((p_buffer->head > 0U) && (p_buffer->head < p_buffer->size) && (p_buffer->sum == 0U))
    {
        // Buffer underflow, discarding all values
        p_buffer->head = 0;
    }
    else
    {
        // do nothing
    }

    p_buffer->sum -= p_buffer->buffer[p_buffer->head];
    p_buffer->buffer[p_buffer->head] = item;
    p_buffer->head = (p_buffer->head + 1U) % p_buffer->size;
    p_buffer->sum += item;

    return 0;
}

/**
 * @brief Gets an item from the ring buffer at the specified index.
 *
 * @param[in]  p_buffer   Pointer to the ring buffer to get the item from.
 * @param[in]  index      Index of the item to get.
 * @param[out] out_value  Pointer to the location to store the retrieved value.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get(const ring_buffer *p_buffer, uint16_t index, double *out_value)
{
    if ((p_buffer == NULL) || (out_value == NULL))
    {
        printf("\r%s: Invalid parameters for ring buffer get operation\n", __func__);
        return -EFAULT;
    }

    if (index >= p_buffer->size)
    {
        printf("\r%s: Invalid index for ring buffer get operation\n", __func__);
        return -EINVAL;
    }

    uint16_t actual_index = (p_buffer->head + index) % p_buffer->size;
    *out_value = p_buffer->buffer[actual_index];

    return 0;
}

/**
 * @brief Gets the sum of all elements in the ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer to get the sum from.
 * @param[out] sum      Pointer to the location to store the sum.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_sum(const ring_buffer *p_buffer, double *sum)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Cannot get sum from uninitialized buffer\n", __func__);
        return -EFAULT;
    }

    *sum = p_buffer->sum;

    return 0;
}

/**
 * @brief Gets the size of the ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer to get the size from.
 * @param[out] size     Pointer to the location to store the size.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_size(const ring_buffer *p_buffer, uint16_t *size)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Cannot get size from uninitialized buffer\n", __func__);
        return -EFAULT;
    }

    *size = p_buffer->size;

    return 0;
}

/**
 * @brief Prints the contents of the ring buffer to stdout.
 *
 * @param[in] p_buffer Pointer to the ring buffer to print.
 */
void ring_buffer_print(const ring_buffer *p_buffer)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Cannot print uninitialized buffer\n", __func__);
        return;
    }

    printf("\rHead: %u, Sum: %lf, Buffer: { ", p_buffer->head, p_buffer->sum);
    for (uint16_t i = 0U; i < p_buffer->size; i++)
    {
        printf("%lf, ", p_buffer->buffer[i]);
    }
    printf("}\n");
}

/**
 * @brief Destroys a ring buffer, freeing its memory.
 *
 * @param[in,out] p_buffer Pointer to the ring buffer to destroy.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_destroy(ring_buffer *p_buffer)
{
    if (p_buffer == NULL)
    {
        printf("\r%s: Attempted to destroy uninitialized buffer\n", __func__);
        return -EFAULT;
    }

    free(p_buffer->buffer);
    p_buffer->buffer = NULL;
    p_buffer->size = 0;

    return 0;
}