#include <iostream>
using namespace std;


void merse(int *arr, int s,int e){


int mid = (s+e)/2;
int len1= mid-s+1;
int len2 =e-mid;

int *frist= new int[len1];
int *second =new int [len2];





 int mainindex=s;
 
 for(int i=0;i<len1;i++){
    frist[i]=arr[mainindex++];
 }
 mainindex=mid+1;
  for(int i=0;i<len1;i++){
    second[i]=arr[mainindex++];
 }


 
int index1=0;
int index2=0;

 mainindex=s;
 

while(index1<len1  &&  index2<len2){
if(frist[index1]<second[index2])
arr[mainindex++]=frist[index1++];

else
   arr[mainindex++]=second[index2++];
}

while(index1<len1){
    arr[mainindex++]=frist[index1++];
}

while(index2<len2){
    arr[mainindex++]=second[index2++];
}


}

 void mergesort(int arr[],int s,int e){
 
if(s>=e)
return;

int mid = (s+e)/2;

mergesort(arr,s,mid);

mergesort(arr,mid+1,e);

merse(arr,s,e);
  
}

int main(){
    int arr[6]={2,7,5,1,6};
    int n=6 ;
    

mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
   


}