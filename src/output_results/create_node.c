#include "pathfinder.h"

t_list_mat *create_node(char **way, int *dist) {
    t_list_mat *head = NULL;

    head = (t_list_mat *) malloc(sizeof(t_list_mat));

    head->dist = dist;
    head->next = NULL;
    return head;
}
