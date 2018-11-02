#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "conditional.h"
#include "negation.h"
#include "greater.h"
#include "less.h"
#include "equals.h"
#include "and.h"
#include "or.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(istringstream& iss)
{
    Expression* left;
    Expression* right;
    Expression* condition;
    char operation, paren, question;

    left = Operand::parse(iss);
    iss >> operation;
    // Supporting the conditional expression operator
    if (operation == ':')
    {
        right = Operand::parse(iss);
        iss >> question;
        condition = Operand::parse(iss);
        iss >> paren;
        return new Conditional(left, right, condition);
    }
    // Supporting the negation operator
    else if (operation == '!')
    {
        iss >> paren;
        return new Negation(left, NULL);
    }
    else
    {
        right = Operand::parse(iss);
        iss >> paren;
        switch (operation)
        {
            case '+':
                return new Plus(left, right);
            case '-':
                return new Minus(left, right);
            case '*':
                return new Times(left, right);
            case '/':
                return new Divide(left, right);
            // Supporting relational operators
            case '>':
                return new Greater(left, right);
            case '<':
                return new Less(left, right);
            case '=':
                return new Equals(left, right);
            // Supporting logical operators
            case '&':
                return new And(left, right);
            case '|':
                return new Or(left, right);
        }
    }
    return 0;
}
