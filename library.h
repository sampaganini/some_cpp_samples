# ifndef library_h
# define library_h
#include <string.h>


class library
{
  public:
    string category;
    string author;
    string status;
    int numb_of_pg;
    
    library(string new_cat = "unknown", string new_aut = "unknown", string new_stat = "unknown", int new_numb = 0)
    {
        category = new_cat;
        author = new_aut;
        status = new_stat;
        numb_of_pg = new_numb;
    }
    ~library() {};
    friend ostream&  operator <<(ostream& os, library& lib)
    {
        return os << lib.category << ' ' << lib.author << ' ' << lib.status << ' ' << lib.numb_of_pg; 
    }
    
};






# endif /* library.h */ 