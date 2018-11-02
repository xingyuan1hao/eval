#include <cctype>
#include <sstream>
#include <string>
using namespace std;

#include "parse.h"

string parseName(istringstream& iss)
{
    char alnum;
    string name = "";

    iss >> ws;
    while (isalnum(iss.peek()))
    {
        iss >> alnum;
        name += alnum;
    }
    return name;
}
