// Linked list, not to usual way to start

#include "element.h"
#include <stdio.h>

// struct llist
// {
//     void *start;
//     int num_elements;
// };

// void new_ll (llist *ll, int data)
// {
//     first_element = new_element()
// }

int main(void)
{
    // element n1;

    element *n1 = new_element(3);
    element *n2 = new_element(55);
    set_next_element_address(&n1, get_element_address(n2));
}
