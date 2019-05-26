#include "../header_files/book_list.h"

void book_list::init(t_book_list &list)
{
    list.head = nullptr;
    list.curr = nullptr;
    list.prev = nullptr;
    list.last = nullptr;
}

void book_list::set_head(t_book_list &list, t_book_node *t)
{
    list.head = t;
}

void book_list::set_prev(t_book_list &list, t_book_node *t)
{
    list.prev = t;
}

void book_list::set_curr(t_book_list &list, t_book_node *t)
{
    list.curr = t;
}

void book_list::set_last(t_book_list &list, t_book_node *t)
{
    list.last = t;
}

t_book_node* book_list::get_head(t_book_list &list)
{
    return list.head;
}

t_book_node* book_list::get_prev(t_book_list &list)
{
    return list.prev;
}

t_book_node* book_list::get_curr(t_book_list &list)
{
    return list.curr;
}

t_book_node* book_list::get_last(t_book_list &list)
{
    return list.last;
}

void book_list::go_beg(t_book_list &list)
{
    set_prev(list, nullptr);
    set_curr(list, get_head(list));
}

void book_list::go_next(t_book_list &list)
{
    set_prev(list, get_curr(list));
    set_curr(list, book_node::get_next(get_curr(list)));
}

void book_list::go_end(t_book_list &list)
{
    go_beg(list);
    while (book_node::get_next(get_curr(list)) != nullptr)
    {
        go_next(list);
    }
}

void book_list::insert_end(t_book_list &list)
{
    t_book_node *node = new t_book_node;
    book_node::init_node(node, nullptr);
    book_node::set_next(get_last(list), node);
    set_last(list, node);
}

void book_list::delete_beg(t_book_list &list)
{
    go_beg(list);
    set_head(list, book_node::get_next(get_curr(list)));
    delete get_curr(list);
    go_beg(list);
}

void book_list::delete_last(t_book_list &list)
{
    go_beg(list);
    go_end(list);
    book_node::set_next(get_prev(list), nullptr);
    set_last(list, get_prev(list));
    delete (get_curr(list));
    go_beg(list);
}

void book_list::delete_all(t_book_list &list)
{
    while (get_head(list) != nullptr)
    {
        delete_beg(list);
    }
    init(list);
}
