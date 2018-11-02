class Greater: public SubExpression
{
public:
    Greater(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() > right->evaluate();
    }
};
