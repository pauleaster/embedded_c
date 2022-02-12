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
    printf("data = %i\n\n", get_element_data(n1));
    printf("address = %lu\n\n", get_element_address(n1));
    printf("next address = %lu\n\n", get_element_next_address(n1));
}
