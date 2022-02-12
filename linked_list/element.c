

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
