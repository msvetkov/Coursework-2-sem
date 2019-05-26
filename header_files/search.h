#ifndef COURSE_WORK_SEARCH_H
#define COURSE_WORK_SEARCH_H

#include "str_list.h"
#include "ref_list.h"
#include "consts.h"

struct t_search_query
{
    t_str_list title;
    t_str_list author;
    search_by search_type;
    storage search_storage;
};

void search(t_ref_list &result, t_search_query &query, t_ref_list title_map[], t_ref_list author_map[]);

void search_book(t_ref_list &result, t_search_query query, t_ref_list map[]);

void search_title(t_ref_list &result, t_search_query query, t_ref_list map[]);

void search_author(t_ref_list &result, t_search_query query, t_ref_list map[]);

bool is_strings_equal(t_str_list first_str, t_str_list second_str);

#endif //COURSE_WORK_SEARCH_H
