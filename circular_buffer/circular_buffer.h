

#ifndef _CIRCULAR_BUF_H
#define _CIRCULAR_BUF_H


#include "stdint.h"
#include "stddef.h"
#include "stdbool.h"


#define CIRCULAR_BUFFER_MAX_SIZE 20
#define nullptr NULL

enum circular_buffer_status {
    CIRCULAR_BUFFER_STATUS_EMPTY = -1,
    CIRCULAR_CUFFER_STATUS_NOT_EMPTY = 0
};

struct circular_buffer {
    uint8_t *buffer; 
    size_t head;
    size_t tail;
    size_t max;
    bool full;
};

typedef struct circular_buffer s_circular_buffer_t;
typedef enum circular_buffer_status e_circular_buffer_status;


s_circular_buffer_t* circular_buffer_init(uint8_t* buffer, size_t size);
void reset_cbuf(s_circular_buffer_t *circular_buffer);
void release_buffer(s_circular_buffer_t *circular_buffer);
bool is_buffer_full(s_circular_buffer_t *circular_buffer);
bool is_buffer_empty(s_circular_buffer_t *circular_buffer);
size_t buffer_capacity(s_circular_buffer_t *circular_buffer);
size_t buffer_size(s_circular_buffer_t *circular_buffer);
void circular_buffer_put(s_circular_buffer_t *circular_buffer, uint8_t data);
e_circular_buffer_status circular_buffer_get(s_circular_buffer_t *circular_buffer, uint8_t *data);

#endif //_CIRCULAR_BUF_H


