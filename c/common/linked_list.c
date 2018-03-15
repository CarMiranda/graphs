#include "list.h"

void insert_first(linked_list, node_val);
void insert_last(linked_list, node_val);
void insert_before(linked_list, node_val, node_val);
void insert_after(linked_list, node_val, node_val);

void remove_first(linked_list);
void remove_last(linked_list);
void remove_once(linked_list, node_val);
void remove_all(linked_list, node_val);

int contains(linked_list, node_val);
int count(linked_list, node_val);
