#include <fstream>
#include "../header_files/search.h"
#include "../header_files/book_io.h"

void search(t_ref_list &result, t_search_query &query, t_ref_list title_map[], t_ref_list author_map[])
{
    std::fstream file;
    file.open("../res/search.txt", std::ios::in);

    int buffer;
    file >> buffer;
    query.search_type = static_cast<search_by>(buffer);
    file >> buffer;
    query.search_storage = static_cast<storage>(buffer);

    switch (query.search_type) {
        case AUTHOR_AND_TITLE:
            query.title = read_search(file, '|');
            query.author = read_search(file, '\n');
            search_book(result, query, title_map);
            break;
        case TITLE:
            query.title = read_search(file, '\n');
            search_title(result, query, title_map);
            break;
        case AUTHOR:
            query.author = read_search(file, '\n');
            search_author(result, query, author_map);
    }
    for (int i = 0; i < CHARS_IN_ASKII; i++)
    {
        ref_list::delete_all(title_map[i]);
        ref_list::delete_all(author_map[i]);
    }
}

void search_book(t_ref_list &result, t_search_query query, t_ref_list map[])
{
    char title_first_letter = str_list::get_head(query.title)->value.unit[0];
    t_ref_list search_list = map[title_first_letter];
    if (ref_list::get_head(search_list) == nullptr) return;

    ref_list::go_beg(search_list);
    while (ref_list::get_curr(search_list) != nullptr)
    {
        if ((query.search_storage != ALL) &&
             query.search_storage != ref_list::get_curr(search_list)->original->value.book_storage)
        {
            ref_list::go_next(search_list);
            continue;
        }
        if (is_strings_equal(ref_list::get_curr(search_list)->original->value.author, query.author) &&
                is_strings_equal(ref_list::get_curr(search_list)->original->value.title, query.title))
        {
            save_reference(result, ref_list::get_curr(search_list)->original);
        }
        ref_list::go_next(search_list);
    }
}

void search_title(t_ref_list &result, t_search_query query, t_ref_list map[])
{
    char title_first_letter = str_list::get_head(query.title)->value.unit[0];
    t_ref_list search_list = map[title_first_letter];
    if (ref_list::get_head(search_list) == nullptr) return;

    ref_list::go_beg(search_list);
    while (ref_list::get_curr(search_list) != nullptr)
    {
        if ((query.search_storage != ALL) &&
            query.search_storage != ref_list::get_curr(search_list)->original->value.book_storage)
        {
            ref_list::go_next(search_list);
            continue;
        }
        if (is_strings_equal(ref_list::get_curr(search_list)->original->value.title, query.title))
        {
            save_reference(result, ref_list::get_curr(search_list)->original);
        }
        ref_list::go_next(search_list);
    }
}

void search_author(t_ref_list &result, t_search_query query, t_ref_list map[])
{
    char author_first_letter = str_list::get_head(query.author)->value.unit[0];
    t_ref_list search_list = map[author_first_letter];
    if (ref_list::get_head(search_list) == nullptr) return;

    ref_list::go_beg(search_list);
    while (ref_list::get_curr(search_list) != nullptr)
    {
        if ((query.search_storage != ALL) &&
            query.search_storage != ref_list::get_curr(search_list)->original->value.book_storage)
        {
            ref_list::go_next(search_list);
            continue;
        }
        if (is_strings_equal(ref_list::get_curr(search_list)->original->value.author, query.author))
        {
            save_reference(result, ref_list::get_curr(search_list)->original);
        }
        ref_list::go_next(search_list);
    }
}

bool is_strings_equal(t_str_list first_str, t_str_list second_str)
{
    str_list::go_beg(first_str);
    str_list::go_beg(second_str);

    while (true) {
        for (int i = 0; i < UNIT_LENGTH; i++) {
            char first_char = str_list::get_curr(first_str)->value.unit[i];
            char second_char = str_list::get_curr(second_str)->value.unit[i];

            if (first_char == first_str.marker && second_char == second_str.marker)
            {
                return true;
            }
            if (first_char != second_char)
            {
                return false;
            }
        }
        str_list::go_next(first_str);
        str_list::go_next(second_str);
    }
}