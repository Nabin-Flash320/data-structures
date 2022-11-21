

#include "circular_buffer.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

static void increase_pointers(s_circular_buffer_t *circular_buffer);
static void decrease_pointers(s_circular_buffer_t *circular_buffer);


s_circular_buffer_t* circular_buffer_init(uint8_t* buffer, size_t size)
{
    assert(buffer);
    s_circular_buffer_t *cir_buf = (s_circular_buffer_t*)malloc(sizeof(s_circular_buffer_t));
    cir_buf->buffer = buffer;
    cir_buf->max = size;
    if(cir_buf->max == 0)
    {
        printf("Buffer size was found to be '0'. Using default size to be %d\n", CIRCULAR_BUFFER_MAX_SIZE);
        cir_buf->max = CIRCULAR_BUFFER_MAX_SIZE;
    }
    reset_cbuf(cir_buf);
    assert(is_buffer_empty(cir_buf));

    return cir_buf;
}


void reset_cbuf(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    circular_buffer->head = 0;
    circular_buffer->tail = 0;
    circular_buffer->full = false;
}

void release_buffer(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    free(circular_buffer);
}


bool is_buffer_full(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    return circular_buffer->full;
}

bool is_buffer_empty(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    return ((circular_buffer->head == circular_buffer->tail) && !circular_buffer->full) ? true : false;
}

size_t buffer_capacity(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    return circular_buffer->max;
}

size_t buffer_size(s_circular_buffer_t *circular_buffer)
{
     assert(circular_buffer);
    size_t size = circular_buffer->max;
    if(!circular_buffer->full)
    {
        if(circular_buffer->head >= circular_buffer->tail)
        {
            size = circular_buffer->head - circular_buffer->tail;
        }
        else
        {
            size = circular_buffer->max + circular_buffer->head - circular_buffer->tail;
        }
    }
    return size;
}

void circular_buffer_put(s_circular_buffer_t *circular_buffer, uint8_t data)
{
    assert(circular_buffer && circular_buffer->buffer);
    circular_buffer->buffer[circular_buffer->head] = data;
    increase_pointers(circular_buffer);
}

e_circular_buffer_status circular_buffer_get(s_circular_buffer_t *circular_buffer, uint8_t *data)
{
    assert(circular_buffer && data && circular_buffer->buffer);
    e_circular_buffer_status ret = CIRCULAR_BUFFER_STATUS_EMPTY;
    if(!is_buffer_empty(circular_buffer))
    {
        *data = circular_buffer->buffer[circular_buffer->tail];
        decrease_pointers(circular_buffer);
        ret = CIRCULAR_CUFFER_STATUS_NOT_EMPTY;
    }
    return ret;
}

static void increase_pointers(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    if(circular_buffer->full)
    {
        if(++circular_buffer->tail == circular_buffer->max)
        {
            circular_buffer->tail = 0;
        }
    }
    if(++circular_buffer->head == circular_buffer->max)
    {
        circular_buffer->head = 0;
    }
    circular_buffer->full = (circular_buffer->head == circular_buffer->tail);
}

static void decrease_pointers(s_circular_buffer_t *circular_buffer)
{
    assert(circular_buffer);
    circular_buffer->full = false;
    if(++circular_buffer->tail == circular_buffer->max)
    {
        circular_buffer->tail = 0;
    }
}
