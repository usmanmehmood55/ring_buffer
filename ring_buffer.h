/**
 * @file    ring_buffer.h
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

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct ring_buffer_t ring_buffer_t;

/**
 * @brief Creates a new ring buffer with the specified size.
 *
 * @param[in,out] p_buffer Pointer to the ring buffer to create.
 * @param[in]     size     Size of the ring buffer to create.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_create(ring_buffer_t **p_buffer, uint16_t size);

/**
 * @brief Gets the index of the head element of a ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer.
 * @param[out] index    Pointer to the location to store the head index.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get_head_index(const ring_buffer_t *p_buffer, uint16_t *index);

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
int ring_buffer_add(ring_buffer_t *p_buffer, double item);

/**
 * @brief Gets an item from the ring buffer at the specified index.
 *
 * @param[in]  p_buffer   Pointer to the ring buffer to get the item from.
 * @param[in]  index      Index of the item to get.
 * @param[out] out_value  Pointer to the location to store the retrieved value.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get_element(const ring_buffer_t *p_buffer, uint16_t index, double *out_val);

/**
 * @brief Gets the sum of all elements in the ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer to get the sum from.
 * @param[out] sum      Pointer to the location to store the sum.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get_sum(const ring_buffer_t *p_buffer, double *sum);

/**
 * @brief Gets the size of the ring buffer.
 *
 * @param[in]  p_buffer Pointer to the ring buffer to get the size from.
 * @param[out] size     Pointer to the location to store the size.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_get_size(const ring_buffer_t *p_buffer, uint16_t *size);

/**
 * @brief Prints the contents of the ring buffer to stdout.
 *
 * @param[in] p_buffer Pointer to the ring buffer to print.
 */
void ring_buffer_print(const ring_buffer_t *p_buffer);

/**
 * @brief Destroys a ring buffer, freeing its memory.
 *
 * @param[in,out] p_buffer Pointer to the ring buffer to destroy.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int ring_buffer_destroy(ring_buffer_t *p_buffer);

#endif