#ifndef COURSE_WORK_BOOK_NODE_H
#define COURSE_WORK_BOOK_NODE_H

#include "book.h"

struct t_book_node
{
    t_book value;
    t_book_node *next;
};

namespace book_node
{
    void init_node(t_book_node *init, t_book_node *next);

    void set_next(t_book_node *node, t_book_node *next);

    t_book_node* get_next(t_book_node *node);
}

#endif //COURSE_WORK_BOOK_NODE_H