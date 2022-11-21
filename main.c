
#include "circular_buffer.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"


int main()
{
    size_t buffer_size = 5;
    uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t) * buffer_size);
    s_circular_buffer_t *circular_buffer = circular_buffer_init(buffer, buffer_size);
    printf("Current buffer size is %ld\nis buffer full %d\nis buffer empty %d\n", buffer_capacity(circular_buffer), 
                                        is_buffer_full(circular_buffer),
                                        is_buffer_empty(circular_buffer));
    
    uint8_t data = 5;
    circular_buffer_put(circular_buffer, 5);
    circular_buffer_put(circular_buffer, 10);
    circular_buffer_put(circular_buffer, 15);
    circular_buffer_put(circular_buffer, 20);
    circular_buffer_put(circular_buffer, 25);

    printf("Current buffer size is %ld\nis buffer full %d\nis buffer empty %d\n", buffer_capacity(circular_buffer), 
                                        is_buffer_full(circular_buffer),
                                        is_buffer_empty(circular_buffer));

    uint8_t dat;
    for(int i = 0; i < buffer_size; i++)
    {
        circular_buffer_get(circular_buffer, &dat);
        printf("Data is %d\n", dat);
    }

    free(buffer);
    release_buffer(circular_buffer);
    return 0;
}

