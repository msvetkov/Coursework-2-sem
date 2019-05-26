#include "header_files/search.h"
#include "header_files/book_list.h"
#include "header_files/book_io.h"

int main()
{
    t_book_list lib, other;
    book_list::init(lib);
    book_list::init(other);
    t_ref_list title_map[CHARS_IN_ASKII], author_map[CHARS_IN_ASKII];
    read_all_lists(lib, other, title_map, author_map);
    std::fstream output;
    output.open("../res/output.txt", std::ios::out);
    output << "Books in library:\n";
    print_book_list(lib, output);
    output << "\nBooks in other storage:\n";
    print_book_list(other, output);
    t_ref_list result;
    ref_list::init(result);
    t_search_query query;
    search(result, query, title_map, author_map);
    output << "\n";
    print_search_query(query, output);
    output << "\n\nSearch result:\n";
    print_ref_list(result, output);
    output << "\n";
    book_list::delete_all(lib);
    book_list::delete_all(other);
    ref_list::delete_all(result);
    return 0;
}