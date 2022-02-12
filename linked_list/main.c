// Linked list, not to usual way to start

#include "element.h"
#include <stdio.h>
#include "llist.h"
#include "log.h"

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
    int data;

    FILE *log_file = fopen("log.txt", "w");
    log_add_fp(log_file, 0);

    linked_list *ll = new_list();
    log_trace("%p", ll);
    append_to_list(&ll, 3, log_file);
    append_to_list(&ll, -7, log_file);

    append_to_list(&ll, 15, log_file);
    linked_list *tv;
    // tv = ll; // point to the start of the linked list
    for (tv = copy_linked_list(ll); number_of_elements(tv) > 0; tv = next_element(tv))
    {
        log_trace("loop: tv = %p", tv);
        log_trace("loop: num elements[tv] = %i", number_of_elements(tv));
        data = get_data(tv);
    }

    log_trace("Finished");
}
