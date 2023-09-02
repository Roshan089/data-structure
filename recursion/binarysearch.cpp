#include <iostream>
using namespace std;


 bool binarysearch(int arr[],int s,int e,int k){
  

  if(s>e)
  return false;

  int mid=s+(e-s)/2;

  if(arr[mid] ==k)
  return true;




 
  if(arr[mid]>k)
  return binarysearch(arr,s,mid-1,k);

  
  else
  return binarysearch(arr,mid+1,e,k);
  



  
}

int main(){
    int arr[]={2,9,5,6};
    

    bool c=binarysearch(arr,0,3,6);
    cout<<c;
   


}