#include <iostream>
using namespace std;


 bool checksort(int arr[],int n ,int k){
   
if (n==0)
return false;



if (k== arr[0])

 return true;

else {
bool rem =checksort(arr+1,n-1,k);
return rem;
}




  
}

int main(){
    int arr[]={2,9,5,6,8};

    bool c=checksort(arr,5, 1);
    cout<<c;
   


}