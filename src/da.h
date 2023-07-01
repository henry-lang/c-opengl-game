#pragma once

#define DA_INIT_CAPACITY 8

#define da_impl(T) struct {                                                            \
    size_t capacity;                                                                   \
    size_t length;                                                                     \
    T *data;                                                                           \
};                                                                                      

#define da_append(da, item) do {                                                       \
    if ((da)->length >= (da)->capacity) {                                              \
        (da)->capacity = (da)->capacity == 0 ? 8 : (da)->capacity*2;                   \
        (da)->items = reallocate((da)->items, (da)->capacity*sizeof(*(da)->items));    \
    }                                                                                  \
    (da)->items[(da)->length++] = (item);                                              \
} while (0)

#define da_reserve(da, desired_capacity) do {                                          \
   if ((da)->capacity < desired_capacity) {                                            \
       (da)->capacity = desired_capacity;                                              \
       (da)->items = reallocate((da)->items, (da)->capacity*sizeof(*(da)->items));     \
   }                                                                                   \
} while(0)
