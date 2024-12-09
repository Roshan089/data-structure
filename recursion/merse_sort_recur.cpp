// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merse(int arr[], int s,int e){
    int m=(s+e)/2;
    
    int lsize=m-s+1;
    int rsize=e-m;
    
    int *larr=new int[lsize];
    int * rarr=new int[rsize];
    
    int k=s;
    for(int i=0;i<lsize;i++){
        larr[i]=arr[k];
        k++;
    }
    
    k=m+1;
    for(int i=0;i<rsize;i++){
        rarr[i]=arr[k];
        k++;
    }
    
    int lindex=0;
    int rindex=0;
    int mindex=s;
   while(lindex<lsize && rindex<rsize){
       
       if(larr[lindex]<rarr[rindex]){
           arr[mindex++]=larr[lindex++];
       }
       else
       arr[mindex++]=rarr[rindex++];
       
   }
   
   while(lindex<lsize){
        arr[mindex++]=larr[lindex++];
   }
    while(rindex<rsize){
       arr[mindex++]=rarr[rindex++];
   }
    
    delete[] larr;
    delete[] rarr;
    
}


void recmer(int arr[],int s,int e){
    int mid=(s+e)/2;
    
    if(s==e)
    return;
    
    recmer(arr,s,mid);
    recmer(arr,mid+1,e);
    
    merse(arr,s,e);
}

int main() {
  
  int arr[2]={4,2};
  
  recmer(arr,0,1);
  
  for(int i=0; i<2;i++){
      cout<<arr[i]<<" ";
  }

    return 0;
}