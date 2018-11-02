class Negation: public SubExpression
{
public:
    Negation(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return !(left->evaluate());
    }
};
