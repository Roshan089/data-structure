#include <iostream>
using namespace std;


 bool checksort(int arr[],int n){
  

  if(n==1)
  return true;

  bool prearr=checksort( arr+1,n-1);
  return arr[0]<arr[1] && prearr;



  
}

int main(){
    int arr[]={2,9,5,6};

    int c=checksort(arr,1);
    cout<<c;
   


}