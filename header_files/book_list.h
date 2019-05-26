#ifndef COURSE_WORK_BOOK_LIST_H
#define COURSE_WORK_BOOK_LIST_H

#include "book_node.h"

struct t_book_list
{
    t_book_node *head;   // the first node of linked list
    t_book_node *curr;   // the current node
    t_book_node *prev;   // node before current
    t_book_node *last;   // last node of list
};

namespace book_list
{
    void init(t_book_list &list);

    void set_head(t_book_list &list, t_book_node *t);

    void set_prev(t_book_list &list, t_book_node *t);

    void set_curr(t_book_list &list, t_book_node *t);

    void set_last(t_book_list &list, t_book_node *t);

    t_book_node* get_head(t_book_list &list);

    t_book_node* get_prev(t_book_list &list);

    t_book_node* get_curr(t_book_list &list);

    t_book_node* get_last(t_book_list &list);

    void go_beg(t_book_list &list);

    void go_next(t_book_list &list);

    void go_end(t_book_list &list);

    void insert_end(t_book_list &list);

    void delete_beg(t_book_list &list);

    void delete_last(t_book_list &list);

    void delete_all(t_book_list &list);
}

#endif //COURSE_WORK_BOOK_LIST_H