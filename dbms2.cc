#include "dbms2.hh"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
using namespace dbms2;

/**
*Loads CSV file into the database
*/
bool AbstractDbTable::loadCSV(const char*intn) {
        string id,title,year,director;
        ifstream input(intn);
        if(!input) {
                cout <<"Can't find file" <<endl;
                return false;
        }
        while(!input.eof()) {
                if(!getline(input,id,',')){
                        break;
                }
                if(!getline(input,title,',')){
                        break;
                }
                if(!getline(input,year,',')){
                        break;
                }
                if(!getline(input,director,'\n')){
                        break;
                }
                movie m={};
                //Input values that were read into database
                m.id = stoul(id);
                strcpy(m.title,title.c_str());
                m.year = (unsigned short) stoul(year);
                strcpy(m.director,director.c_str());
                add(m);
        }
        input.close();
        return true;

}
/**
*Save database to a csv file
*/
bool AbstractDbTable::saveCSV(const char *outfn) {
        ofstream out(outfn);
        out.clear();
        if(!out) {
                cout <<"Can't find file" << endl;
                return false;
        }
        for(int i =0;i<rows();i++) {
                out<<get(i) -> id<<","<<get(i) ->title<<","<<get(i) ->year<<","<<get(i)->director<<endl; //Print to csv
        }
        out.close();
        return true;
}
