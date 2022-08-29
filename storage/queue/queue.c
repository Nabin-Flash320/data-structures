
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define nullptr NULL

typedef struct queue{
    int value;
    struct queue *next;
}queue_t;

void put(queue_t*, int);
int get(queue_t*);
void clear(queue_t*);

int main()
{
    queue_t *first = nullptr;

    printf("Queue!!\n");
    put(first, 2);
    put(first, 3);
    put(first, 4);
    put(first, 5);
    clear(first);
    first = NULL;
    printf("%d\n", get(first));
    return 0;
}

void put(queue_t* first, int val)
{
    
    queue_t *node = (queue_t*)malloc(sizeof(queue_t));
    queue_t *last = first;
    if(nullptr == node)
    {
        printf("Couldn't allocate memory!");
        return;
    }

    node->value = val;

    if(nullptr == first)
    {
        node->next = nullptr;
        first = node;
        return;
    }
    while (nullptr != last->next)
    {
        last = last->next;
    } 
    last->next = node;
    node->next = nullptr;

}

int get(queue_t *first)
{
    queue_t *node = first;
    if(nullptr == first)
    {
        printf("Queue is empty.");
        return -1;
    }
    first = node->next;
    int value = node->value;
    free(node);
    return value;
}

void clear(queue_t* start_node)
{
    if (nullptr != start_node)
    {
        clear(start_node->next);
        start_node->next = NULL;
        free(start_node);
    }
    
    return;
}


