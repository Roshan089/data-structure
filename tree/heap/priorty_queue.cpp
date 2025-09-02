#include <iostream>
#include <queue>
using namespace std;

int main(){
    int arr[]={10,40,20,13,100};
    priority_queue<int> q;

   // kth greatest
    //    priority_queue<int, vector<int>, greater<int>> q;

    int n=5;
   
    int k;
    cout<<"put k";
    cin>>k;

    
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(arr[i]<q.top()){
            q.pop();
            q.push(arr[i]);
        }
    }

    //kth greatest
       
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(arr[i]>q.top()){
           q.pop();
            q.push(arr[i]);
        }
    }
    cout<<q.top();
}
