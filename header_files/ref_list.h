#ifndef COURSE_WORK_REF_LIST_H
#define COURSE_WORK_REF_LIST_H

#include "ref_node.h"

struct t_ref_list
{
    t_ref_node *head;   // the first node of linked list
    t_ref_node *curr;   // the current node
    t_ref_node *prev;   // node before current
    t_ref_node *last;   // last node of list
};

namespace ref_list
{
    void init(t_ref_list &list);

    void set_head(t_ref_list &list, t_ref_node *node);

    void set_prev(t_ref_list &list, t_ref_node *node);

    void set_curr(t_ref_list &list, t_ref_node *node);

    void set_last(t_ref_list &list, t_ref_node *node);

    t_ref_node* get_head(t_ref_list &list);

    t_ref_node* get_curr(t_ref_list &list);

    t_ref_node* get_last(t_ref_list &list);

    void go_beg(t_ref_list &list);

    void go_next(t_ref_list &list);

    void insert_end(t_ref_list &list);

    void delete_beg(t_ref_list &list);

    void delete_all(t_ref_list &list);
}

#endif //COURSE_WORK_REF_LIST_H
