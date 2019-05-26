#ifndef COURSE_WORK_REF_NODE_H
#define COURSE_WORK_REF_NODE_H

#include "book_node.h"

// Structure for sorting and search book nodes from original lists
struct t_ref_node
{
    t_book_node *original;
    t_ref_node *next;
};

namespace ref_node
{
    void init_node(t_ref_node *init, t_ref_node *next);

    void set_next(t_ref_node *node, t_ref_node *next);

    t_ref_node* get_next(t_ref_node *node);
}
#endif //COURSE_WORK_REF_NODE_H
