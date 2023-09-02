#include <iostream>
using namespace std;

void printdig( int n ,string a[10])

{
   if(n==0)
   return;

   int dig=n%10;
   int r=n/10;
   

   printdig(r,a);

cout<<a[dig] <<" ";
        
}

int main()
{
  
    string a[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  int n;
    cin>>n;

     printdig(n,a);
     return 0;
}