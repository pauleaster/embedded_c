
#include "element.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "log.h"

typedef struct _ll
{
    element *start_address;
    element *last_address;
    int number_of_elements;
} linked_list;

linked_list *new_list()
{
    linked_list *new_ll = (linked_list *)malloc(sizeof(linked_list));
    new_ll->number_of_elements = 0;
    new_ll->start_address = NULL;
    new_ll->last_address = NULL;
    return (new_ll);
}

linked_list *copy_linked_list(linked_list *ll)
{

    linked_list *ll_copy = new_list();
    ll_copy->number_of_elements = ll->number_of_elements;
    ll_copy->start_address = ll->start_address;
    ll_copy->last_address = ll->last_address;
    return ll_copy;
}

int number_of_elements(linked_list *ll)
{
    return ll->number_of_elements;
}
void append_to_list(linked_list **ll, int data, FILE *log_file)
{

    element *new_el = new_element(data); // allocate the memory for the node
    log_trace("New element %p", new_el);
    element *new_el_address = get_element_address(new_el);
    log_trace("New element address confirmation %p", new_el);
    log_trace("New element data %i", get_element_data(new_el));
    if ((*ll)->number_of_elements == 0)
    {
        (*ll)->start_address = get_element_address(new_el);
        (*ll)->number_of_elements = 1;
        (*ll)->last_address = (*ll)->start_address; // First and last elements are the same for a single length linked list
        return;
    }
    else
    {
        element *second_last = (*ll)->last_address;                // save the last element pointer, this will become second last
        set_next_element_address(&second_last, new_el_address);    // 2nd last element points to new_el
        (*ll)->number_of_elements = ++((*ll)->number_of_elements); // increment the number of elements
        (*ll)->last_address = new_el_address;
        return;
    }
}

linked_list *next_element(linked_list *position)
{

    // Should be a check here to MAKE sure that position points to within a linked list!!!!!
    element *this_address = position->start_address;
    element *next_address = get_element_next_address(this_address);
    position->start_address = next_address;
    --position->number_of_elements;

    // linked_list *linked_address = (linked_list *)next_address;
    // log_trace("new linked_list=%p", position);
    // log_trace("next_address=%p", next_address);
    // log_trace("linked_address=%p", linked_address);

    return position;
}

int get_data(linked_list *position)
{
    int data = get_element_data(position->start_address);
    log_trace("get_data[%p]=%i", position, data);
    return data;
}
