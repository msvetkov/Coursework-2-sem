#include "../header_files/ref_node.h"

void ref_node::init_node(t_ref_node *init, t_ref_node *next)
{
    init->next = next;
}

void ref_node::set_next(t_ref_node *node, t_ref_node *next)
{
    if (node != nullptr) node->next = next;
}

t_ref_node* ref_node::get_next(t_ref_node *node)
{
    return node->next;
}
