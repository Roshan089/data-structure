#include <iostream>
using namespace std;

string reversearr(string a)
{
    if(a.length()==0)
    return "*";
char c=a[0];
string q=reversearr(a.substr(1));

if(c=='x')
return q+c;
else
 return c+q;



        
}

int main()
{
    string a = "axxbbdxndxxj";

    cout << reversearr(a);
}