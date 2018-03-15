#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    double value;
    unsigned int id;
    struct node *next;
} node;

typedef struct linked_list {
    size_t id_count;
    node *head;
} linked_list;

linked_list *init_ll();
void destroy_ll(linked_list*);

void insert_first(linked_list, unsigned int, double);
void insert_last(linked_list, unsigned int, double);
void insert_before(linked_list, unsigned int, unsigned int, double);
void insert_after(linked_list, unsigned int, unsigned int, double);

void remove_first(linked_list);
void remove_last(linked_list);
void remove_by_id(linked_list, unsigned int);
void remove_by_value(linked_list, double);

int contains(linked_list, double);
int count(linked_list, double);

#endif
