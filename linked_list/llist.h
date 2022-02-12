typedef struct _ll linked_list;
linked_list *new_list();
void append_to_list(linked_list **ll, int data, FILE *log_file);
linked_list *next_element(linked_list *position);
int get_data(linked_list *position);
linked_list *copy_linked_list(linked_list *ll);
int number_of_elements(linked_list *ll);