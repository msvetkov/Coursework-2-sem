#ifndef COURSE_WORK_STR_LIST_H
#define COURSE_WORK_STR_LIST_H

#include "str_node.h"

struct t_str_list
{
    t_str_node *head;   // the first node of linked list
    t_str_node *curr;   // the current node
    t_str_node *prev;   // node before current
    t_str_node *last;   // last node of list
    char marker;        // end of the string
};

namespace str_list
{
    void init(t_str_list &list);

    void set_head(t_str_list &list, t_str_node *node);

    void set_prev(t_str_list &list, t_str_node *node);

    void set_curr(t_str_list &list, t_str_node *node);

    void set_last(t_str_list &list, t_str_node *node);

    t_str_node* get_head(t_str_list &list);

    t_str_node* get_curr(t_str_list &list);

    t_str_node* get_last(t_str_list &list);

    void go_beg(t_str_list &list);

    void go_next(t_str_list &list);

    void insert_end(t_str_list &list);
}

#endif //COURSE_WORK_STR_LIST_H
