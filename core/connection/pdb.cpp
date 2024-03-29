#include "pdb.h"

#include <string>
#include <vector>

#include <iostream>
using namespace std;

connection DD("user=postgres dbname=sce");

P_DB::P_DB()
{
    init();
}

P_DB::~P_DB()
{
    delete C;
}

bool P_DB::init()
{
    try {
        connection *C = new connection("user=postgres dbname=sce");
        if (C->is_open()) {
            cout << "Opened database successfully: " << C->dbname() << endl;
            return true;
        } else {
            cout << "Can't open database" << endl;
            return false;
        }
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return false;
    }
}

int P_DB::rows()
{
    return 0;
}

int P_DB::columns()
{
    return 0;
}

char *P_DB::columnName(int columnNumber)
{

}

int P_DB::columnNumber(const char *columnName)
{
    return 0;
}

char *P_DB::getValue(int rowNumber, int columnNumber)
{

}
