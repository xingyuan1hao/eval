class Equals: public SubExpression
{
public:
    Equals(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() == right->evaluate();
    }
};
