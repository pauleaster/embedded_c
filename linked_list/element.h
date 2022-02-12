typedef struct _element element;
element *new_element(int data);
unsigned long *get_element_address(element *node_ptr);
unsigned long get_element_next_address(element *node_ptr);
int get_element_data(element *node_ptr);