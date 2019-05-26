#include "../header_files/ref_list.h"

void ref_list::init(t_ref_list &list)
{
    list.head = nullptr;
    list.curr = nullptr;
    list.prev = nullptr;
    list.last = nullptr;
}

void ref_list::set_head(t_ref_list &list, t_ref_node *node)
{
    list.head = node;
}

void ref_list::set_prev(t_ref_list &list, t_ref_node *node)
{
    list.prev = node;
}

void ref_list::set_curr(t_ref_list &list, t_ref_node *node)
{
    list.curr = node;
}

void ref_list::set_last(t_ref_list &list, t_ref_node *node)
{
    list.last = node;
}

t_ref_node* ref_list::get_head(t_ref_list &list)
{
    return list.head;
}

t_ref_node* ref_list::get_curr(t_ref_list &list)
{
    return list.curr;
}

t_ref_node* ref_list::get_last(t_ref_list &list)
{
    return list.last;
}

void ref_list::go_beg(t_ref_list &list)
{
    set_prev(list, nullptr);
    set_curr(list, get_head(list));
}

void ref_list::go_next(t_ref_list &list)
{
    set_prev(list, get_curr(list));
    set_curr(list, ref_node::get_next(get_curr(list)));
}

void ref_list::insert_end(t_ref_list &list)
{
    auto *node = new t_ref_node;
    ref_node::init_node(node, nullptr);
    ref_node::set_next(get_last(list), node);
    set_last(list, node);
}

void ref_list::delete_beg(t_ref_list &list)
{
    go_beg(list);
    set_head(list, ref_node::get_next(get_curr(list)));
    delete get_curr(list);
    go_beg(list);
}

void ref_list::delete_all(t_ref_list &list)
{
    while (get_head(list) != nullptr) {
        delete_beg(list);
    }
    init(list);
}
