#include "../header_files/str_node.h"


void str_node::init_node(t_str_node *init, t_str_node *next)
{
    init->next = next;
}

void str_node::set_next(t_str_node *node, t_str_node *next)
{
    if (node != nullptr) node->next = next;
}

t_str_node* str_node::get_next(t_str_node *node)
{
    return node->next;
}


