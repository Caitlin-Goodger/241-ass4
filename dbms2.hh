#include <stdio.h>

namespace dbms2
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    class AbstractDbTable {
    public:
            //Pure Virtual Functions
            virtual unsigned int rows() const = 0;
            virtual bool show(unsigned int) const = 0;
            virtual bool add(movie&)= 0;
            virtual bool remove(unsigned long)  = 0;
            virtual movie* get(unsigned int) const = 0;

            //Not virtual functions
            bool loadCSV(const char *intn);
            bool saveCSV(const char *outfn);
    };
}
