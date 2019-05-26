#include "../header_files/book_node.h"

void book_node::init_node(t_book_node *init, t_book_node *next)
{
    init->next = next;
}

void book_node::set_next(t_book_node *node, t_book_node *next)
{
    if (node != nullptr) node->next = next;
}

t_book_node* book_node::get_next(t_book_node *node)
{
    return node->next;
}