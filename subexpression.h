class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(istringstream& iss);
protected:
    Expression* left;
    Expression* right;
};
