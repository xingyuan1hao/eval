class SymbolTable
{
public:
    SymbolTable() {}
    void insert(string variable, int value);
    double lookUp(string variable) const;
    void clear();
private:
    struct Symbol
    {
        Symbol(string variable, int value)
        {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        int value;
    };
    vector <Symbol> elements;
};
