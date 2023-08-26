#include <iostream>
using namespace std;


 int dec(int n){

    if(n==0)
    return n;


  cout<<n<<endl;
    dec(n-1);
 }

  int inc(int n){
      if(n==1)
    return n;

    inc(n-1);
    cout<<n<<endl;
  }



  


int main(){
   int n;
   cin>>n;


   dec(n);
   inc(n);



}