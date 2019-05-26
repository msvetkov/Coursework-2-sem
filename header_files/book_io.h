#ifndef COURSE_WORK_BOOK_IO_H
#define COURSE_WORK_BOOK_IO_H

#include "book_list.h"
#include "ref_list.h"
#include "search.h"
#include <fstream>

void read_all_lists(t_book_list &library, t_book_list &other, t_ref_list *title_map, t_ref_list author_map[]);

void read_book_list(t_book_list &list, std::fstream &file, storage book_storage, t_ref_list title_map[],
                    t_ref_list author_map[]);

t_str_list read_line(std::fstream &file, char to);

void print_book_list(t_book_list list, std::fstream &file);

void print_line(t_str_list string, std::fstream &file);

void print_search_query(t_search_query query, std::fstream &file);

void print_ref_list(t_ref_list list, std::fstream &file);

void save_reference(t_ref_list &list, t_book_node *node);

t_str_list read_search(std::fstream &file, char to);

#endif //COURSE_WORK_BOOK_IO_H