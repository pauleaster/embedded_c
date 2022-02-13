

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _el
{
    int data;
    void *next;
} element;

element *new_element(int data)
// to_do(): add reference counter
{
    element *new_el = (element *)malloc(sizeof(element));
    new_el->data = data;
    new_el->next = NULL;
    return new_el;
}

element *delete_element(element **node_ptr)
{
    element *next = (*node_ptr)->next;
    free(*node_ptr);
    return (next);
}

element *get_element_address(element *node_ptr)
{
    return (node_ptr);
}

element *get_element_next_address(element *node_ptr)
{
    return (node_ptr->next);
}

int get_element_data(element *node_ptr)
{
    return (node_ptr->data);
}

void print_element_address(element *address)
{
    printf("%p\n", address);
}

void set_next_element_address(element **node_ptr, element *next_address)
{
    (*node_ptr)->next = next_address;
}
