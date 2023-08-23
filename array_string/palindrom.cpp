#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char a[n+1];

    cin>>a;
    bool ispal=1;

    for(int i=0;i<n+1;i++){
      if(a[i]!=a[n-1-i]){
        ispal=0;
        
      }
        break;
    }
    if(ispal==1)
    cout<<"palindrom";
    else
    cout<<"no palindrom";

}