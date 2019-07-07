#include "vdb.hh"

using namespace dbms2;

//Get the number of rows in the database
unsigned int VectorDbTable::rows() const{
        return vmovies.size();
}

//Add a new movie to the database
bool VectorDbTable::add(movie &m){
        vmovies.push_back(m);
        return true;
}

//Show a movie from the database, using an int for row number
bool VectorDbTable::show(unsigned int rowToShow) const {
        if(rowToShow < rows()) {
                unsigned int i = rowToShow;
                printf("Row %d:\n", i);
                printf("Id : %lu\n",vmovies[i].id);
                printf("Title : %d\n",vmovies[i].title);
                printf("Year of Release : %d\n", vmovies[i].year );
                printf("Director : %s\n", vmovies[i].director );
                return true;
        } else {
                return false;
        }
}

//Remove a movie from the database
bool VectorDbTable::remove(unsigned long b) {
        for(int i =0;i<vmovies.size();i++) {
                movie m = vmovies[i];
                if(m.id == b) {
                        vmovies.erase(vmovies.begin()+i);
                        return true;
                }
        }
        return false;
}
//Get a movie from the database
movie *VectorDbTable::get(unsigned int i) const{
        if(i<rows()) {
                return (&const_cast<movie &>(vmovies[i]));
        } else {
                return nullptr;
        }
}
