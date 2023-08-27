#include <iostream>
using namespace std;

void reversearr(string a)
{
if(a.length()==0)
return ;

if(a[0]=='p' && a[1]=='i'){
cout<<3.14;
string s=a.substr(2);
reversearr(s);
}
else
   cout<<a[0];
   reversearr(a.substr(1));



string s=a.substr(2);

   
}

int main()
{
string a;
cin>>a;
reversearr(a);
   
}