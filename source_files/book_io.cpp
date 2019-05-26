#include <iostream>
#include "../header_files/book_io.h"

void read_all_lists(t_book_list &library, t_book_list &other, t_ref_list title_map[], t_ref_list author_map[])
{
    for (int i = 0; i < CHARS_IN_ASKII; i++)
    {
        ref_list::init(title_map[i]);
        ref_list::init(author_map[i]);
    }
    std::fstream file;
    file.open("../res/lib.txt", std::ios::in);
    read_book_list(library, file, LIBRARY, title_map, author_map);
    file.close();
    file.open("../res/other.txt", std::ios::in);
    read_book_list(other, file, OTHER, title_map, author_map);
    file.close();
}

void read_book_list(t_book_list &list, std::fstream &file, storage book_storage, t_ref_list title_map[],
                    t_ref_list author_map[])
{
    file.unsetf(std::ios::skipws);
    while (true)
    {
        book_list::insert_end(list);
        book_list::get_last(list)->value.book_storage = book_storage;
        if (book_list::get_head(list) == nullptr)
        {
            book_list::set_head(list, book_list::get_last(list));
        }

        book_list::get_last(list)->value.title = read_line(file, '|');
        book_list::get_last(list)->value.author = read_line(file, '\n');

        bool isTitleNotRead = str_list::get_head(book_list::get_last(list)->value.title)->value.unit[0] ==
                             book_list::get_last(list)->value.title.marker;
        bool isAuthorNotRead = str_list::get_head(book_list::get_last(list)->value.author)->value.unit[0] ==
                             book_list::get_last(list)->value.author.marker;

        if (isTitleNotRead || isAuthorNotRead)
        {
            book_list::delete_last(list);
            return;
        }

        // Add books in maps for quick searching
        char title_first_letter = str_list::get_head(book_list::get_last(list)->value.title)->value.unit[0];
        save_reference(title_map[title_first_letter], book_list::get_last(list));
        char author_first_letter = str_list::get_head(book_list::get_last(list)->value.author)->value.unit[0];
        save_reference(author_map[author_first_letter], book_list::get_last(list));
    }
}

t_str_list read_line(std::fstream &file, char to)
{
    t_str_list string;
    str_list::init(string);
    char buffer, marker = '#';
    while (true)
    {
        str_list::insert_end(string);
        if (str_list::get_head(string) == nullptr)
        {
            str_list::set_head(string, str_list::get_last(string));
        }
        for (char &i : str_list::get_last(string)->value.unit)
        {
            file >> buffer;
            if (buffer == to)
            {
                i = marker;
                string.marker = marker;
                return string;
            }
            else if (file.eof())
            {
                str_list::get_head(string)->value.unit[0] = string.marker;
                return string;
            }
            else
            {
                i = buffer;
            }
        }
    }
}

void print_book_list(t_book_list list, std::fstream &file)
{
    book_list::go_beg(list);
    while (book_list::get_curr(list) != nullptr)
    {
        file << "\"";
        print_line(book_list::get_curr(list)->value.title, file);
        file << "\" by ";
        print_line(book_list::get_curr(list)->value.author, file);
        file << std::endl;
        book_list::go_next(list);
    }
}

void print_line(t_str_list string, std::fstream &file)
{
    str_list::go_beg(string);
    while (str_list::get_curr(string) != nullptr)
    {
        for (char i : str_list::get_curr(string)->value.unit)
        {
            if (i == string.marker)
            {
                return;
            }
            file << i;
        }
        str_list::go_next(string);
    }
}

void save_reference(t_ref_list &list, t_book_node *node)
{
    ref_list::insert_end(list);
    if (ref_list::get_head(list) == nullptr) {
        ref_list::set_head(list, ref_list::get_last(list));
    }
    ref_list::get_last(list)->original = node;
}

void print_search_query(t_search_query query, std::fstream &file) {
    file << "Search book";
    switch (query.search_type)
    {
        case AUTHOR_AND_TITLE:
            file << " with title \"";
            print_line(query.title, file);
            file << "\" by ";
            print_line(query.author, file);
            break;
        case TITLE:
            file << " with title \"";
            print_line(query.title, file);
            file << "\"";
            break;
        case AUTHOR:
            file << " by ";
            print_line(query.author, file);
            break;
    }
    switch (query.search_storage)
    {
        case ALL:
            file << " in all storage";
            break;
        case LIBRARY:
            file << " in library only";
            break;
        case OTHER:
            file << " in other storage only";
            break;
    }

}

void print_ref_list(t_ref_list list, std::fstream &file) {
    ref_list::go_beg(list);
    while (ref_list::get_curr(list) != nullptr)
    {
        file << "\"";
        print_line(ref_list::get_curr(list)->original->value.title, file);
        file << "\" by ";
        print_line(ref_list::get_curr(list)->original->value.author, file);
        if (ref_list::get_curr(list)->original->value.book_storage == LIBRARY)
        {
            file << " in library";
        } else {
            file << " in other storage";
        }

        file << std::endl;
        ref_list::go_next(list);
    }
}

t_str_list read_search(std::fstream &file, char to) {
    bool exit = false;
    char buffer, marker = '#';
    t_str_list string = t_str_list();
    file.unsetf(std::ios::skipws);
    file >> buffer;
    while (!exit) {
        str_list::insert_end(string);
        if (str_list::get_head(string) == nullptr) {
            str_list::set_head(string, str_list::get_last(string));
        }
        for (char &i : str_list::get_last(string)->value.unit) {
            file >> buffer;
            if (buffer == to) {
                i = marker;
                string.marker = marker;
                exit = true;
                break;
            } else {
                i = buffer;
            }
        }
    }
    return string;
}