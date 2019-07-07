#include <stdio.h>
#include <vector>
#include "dbms2.hh"

namespace dbms2 {

//Extends AbstractDbTable
class VectorDbTable : public AbstractDbTable {
private:
        std::vector<movie> vmovies;

public:
        //Included so that can get the number of rows
        unsigned int rows() const;
        //Included so that can show a single row based on an input value
        bool show(unsigned int) const;
        //Included so that can add a movie to the database
        bool add(movie&);
        //INclude so that can remove a movie from the database
        bool remove(unsigned long);
        //Included so that can get a movie from the database based on a given input
        movie* get(unsigned int) const;
};

}
