// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void recans(string str,int i){
    if(i>=str.length()){
    cout<<str<<" ";
    return;
    }
    
    for(int j=i;j<str.length();j++){
        swap(str[i],str[j]);
        recans(str,i+1);
    }
    
    
}

int main() {
   string word="abc";
   int i=0;
   
   recans(word,i);
   

    
}