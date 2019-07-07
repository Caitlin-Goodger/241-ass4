#include "vdb.hh"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
using namespace dbms2;

//Options for arguments
enum options{show,showall,invalid};

/**
*Check what argument the user has given
*/
eval(const char *c) {
        if(strcmp(c,"showall")==0) {
                return showall;
        } else if(strcmp(c,"show")==0) {
                return show;
        } else {
                return invalid;
        }
}

int main(int argc, char const *argv[]) {
        //Create a new database and load in the file
        VectorDbTable *db;
        db = new VectorDbTable();
        db->loadCSV("default.csv");
        //Check that there is at least one more argument than the file name
        if(argc>1) {
                switch(eval(argv[1])) {
                        case showall:
                        //If show all then display all the rows of the database
                                cout <<endl;
                                for(unsigned int i =0;i<db->rows();i++) {
                                        db->show(i);
                                }
                                cout <<endl;
                                break;
                        case show:
                                //Check that there is another argument
                                if(argc>2) {
                                        //If there is then show that row
                                        db->show((unsigned int)stoul(string(argv[2])));
                                } else {
                                        cout<<"Please provide a row number"<< endl;
                                }
                                break;
                        default:
                                //Else it is invalid
                                cout<<"Invalid arguments"<<endl;
                                break;

                }
        }
        delete(db);
        return 0;
}
