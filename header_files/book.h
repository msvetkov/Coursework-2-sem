#ifndef COURSE_WORK_BOOK_H
#define COURSE_WORK_BOOK_H

#include "str_list.h"

struct t_book
{
    t_str_list title;
    t_str_list author;
    storage book_storage;
};

#endif //COURSE_WORK_BOOK_H
