#include <iostream>
using namespace std;


 int checksort(int arr[],int n){


  if(n==0)
  return 0 ;
  if(n==1)
  return arr[0];

  

  

 int rem= checksort(arr+1,n-1 );

int sum= arr[0]+rem;
return sum;
 
  
}

int main(){
    int arr[]={2,9,5,6,8};

    int c=checksort(arr,5);
    cout<<c;
   


}