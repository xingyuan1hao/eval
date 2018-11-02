class And: public SubExpression
{
public:
    And(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() && right->evaluate();
    }
};
