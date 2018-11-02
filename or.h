class Or: public SubExpression
{
public:
    Or(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() || right->evaluate();
    }
};
