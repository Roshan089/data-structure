#include <iostream>
using namespace std;

void reversearr(string a)
{
if(a.length()==0){
return ;
}
string ros = a.substr(1);
reversearr(ros);
cout<<a[0];
   
}

int main()
{
string a;
cin>>a;
reversearr(a);
   
}