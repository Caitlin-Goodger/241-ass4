#include <stdio.h>
#include <vector>
#include "dbms2.hh"

using namespace dbms2;

struct node {
        movie m;
        struct node* next;
};

//Extends AbstractDbTable
class LinkedListDbTable : public AbstractDbTable {
private:
        int rowsAmount;
        node* n;
public:
        //INcluded so can get the number of rows in the database
        const int rows() {
                return vmovies.size();
        }
        //INcluded so can show a row based on input int
        const bool show(int rowToShow);
        //Included so that can add a movie to database
        bool add(movie&);
        //Included so that can remove a movie from the database
        bool remove(unsigned long);
        //Included so that can get a movie from database
        const movie* get(unsigned int);
};
