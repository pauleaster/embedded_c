

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _element
{
    int data;
    void *next;
} element;

element *new_element(int data)
{
    element *new_el = (element *)malloc(sizeof(element));
    new_el->data = data;
    new_el->next = NULL;
    return new_el;
}

unsigned long get_element_address(element *node_ptr)
{
    return ((unsigned long)((void *)node_ptr));
}

unsigned long get_element_next_address(element *node_ptr)
{
    return ((unsigned long)(node_ptr->next));
}

int get_element_data(element *node_ptr)
{
    return (node_ptr->data);
}
