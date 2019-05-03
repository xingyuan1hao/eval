#cppeval类库示例
#include "CppEval.h"
#include <iostream>
#include <numeric>

using namespace std;

class functions
{
public:
    int operator()( const char* name, const ::std::vector< int >& params )
    {
        if( stricmp( name, "return1" ) == 0 )
        {
            if( params.size() != 0 )
                throw 1;
            return 1;
        }
        else if( stricmp( name, "negative" ) == 0 )
        {
            if( params.size() != 1 )
                throw 1;
            return - params[ 0 ];
        }
        else if( stricmp( name, "sum" ) == 0 )
        {
            return accumulate( params.begin(), params.end(), 0 );
        }
    }
};

int main()
{
    map< string, int > variables;
    variables[ "aa" ] = 100;
    variables[ "b" ] = 200;
    functions f;
    cout<<cpp_eval::eval< int >( " + aa * aa / b - b / -2 /2/2 -- 5 ** 2 + -100 "
        " + ( aa * aa / b - b / -2 /2/2 -- 5 ** 2 + -100 )"
        " + return1() + negative( 1 ) + sum( 1, 2, 3, sum( 1 + 2 *5-7, 555, 111 ) )", variables, f )<<endl;
    return 0;
}
