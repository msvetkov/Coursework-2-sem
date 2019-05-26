#ifndef COURSE_WORK_STR_NODE_H
#define COURSE_WORK_STR_NODE_H

#include "str.h"

struct t_str_node
{
    t_str value;
    t_str_node *next;
};

namespace str_node
{
    void init_node(t_str_node *init, t_str_node *next);

    void set_next(t_str_node *node, t_str_node *next);

    t_str_node* get_next(t_str_node *node);
}

#endif //COURSE_WORK_STR_NODE_H
