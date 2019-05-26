#include "../header_files/str_list.h"

void str_list::init(t_str_list &list)
{
    list.head = nullptr;
    list.curr = nullptr;
    list.prev = nullptr;
    list.last = nullptr;
}

void str_list::set_head(t_str_list &list, t_str_node *node)
{
    list.head = node;
}

void str_list::set_prev(t_str_list &list, t_str_node *node)
{
    list.prev = node;
}

void str_list::set_curr(t_str_list &list, t_str_node *node)
{
    list.curr = node;
}

void str_list::set_last(t_str_list &list, t_str_node *node)
{
    list.last = node;
}

t_str_node* str_list::get_head(t_str_list &list)
{
    return list.head;
}

t_str_node* str_list::get_curr(t_str_list &list)
{
    return list.curr;
}

t_str_node* str_list::get_last(t_str_list &list)
{
    return list.last;
}

void str_list::go_beg(t_str_list &list)
{
    set_prev(list, nullptr);
    set_curr(list, get_head(list));
}

void str_list::go_next(t_str_list &list)
{
    set_prev(list, get_curr(list));
    set_curr(list, str_node::get_next(get_curr(list)));
}

void str_list::insert_end(t_str_list &list)
{
    auto *node = new t_str_node;
    str_node::init_node(node, nullptr);
    str_node::set_next(get_last(list), node);
    set_last(list, node);
}