#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(istringstream& iss);

int main()
{
    Expression* expression;
    char paren, comma;
    // Accept input from a file
    cout << "Reading from file." << endl;
    ifstream inFile("test.txt");
    if (!inFile) {
        cout << "test.txt not found." << endl;
        return -1;
    }
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
        {
            continue;
        }
        symbolTable.clear();
        istringstream iss(line);
        cout << line << endl;
        iss >> paren;
        expression = SubExpression::parse(iss);
        iss >> comma;
        parseAssignments(iss);
        cout << "Value = " << expression->evaluate() << endl;
    }
    cout << "EOF." << endl;
    inFile.close();
    return 0;
}

void parseAssignments(istringstream& iss)
{
    char assignop, delimiter;
    string variable;
    int value;
    do
    {
        variable = parseName(iss);
        iss >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
