#include <stdlib.h>
#include <stdio.h>

typedef struct __node
{
    int data;
    struct __node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
    int size;
} linked_list;

int insert_last(linked_list *l, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
        return 1;

    new_node->data = value;
    l->tail->next = new_node;
    l->tail = new_node;
    l->size++;
    return 0;
}

linked_list *create_linked_list()
{
    linked_list *l = (linked_list *)malloc(sizeof(linked_list));
    if (!l)
        return NULL;

    l->size = 0;
    l->head = l->tail = (node *)malloc(sizeof(node));
    if (!l->head)
    {
        free(l);
        return NULL;
    }
    return l;
}

void print_linked_list(linked_list *l)
{
    if (!l->size)
    {
        printf("<empty list>");
        return;
    }

    for (node *curr = l->head->next; curr != NULL; curr = curr->next)
        printf("%d -> ", curr->data);
    printf("\n");
}

void free_linked_list(linked_list *l)
{
    node *curr = l->head;
    while (curr)
    {
        node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(l);
}