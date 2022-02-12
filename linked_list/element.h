typedef struct _element element;
element *new_element(int data);
element *get_element_address(element *node_ptr);
element *get_element_next_address(element *node_ptr);
int get_element_data(element *node_ptr);
void set_next_element_address(element **node_ptr, element *next_address);
void print_element_address(element *address);