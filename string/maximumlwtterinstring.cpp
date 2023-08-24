#include <iostream>
using namespace std;

int main(){
    string str="jjgdjqq";

  int feq[26];

    for(int i =0;i<26;i++){
        feq[i]=0;
    }
    
    for(int i=0;i<str.size();i++){
        feq[str[i]-'a']++;

    }
    int max=0;
    char ans='a';
    for(int i=0;i<26;i++){
        if(feq[i]>max){
            max=feq[i];
            ans=i+'a';
        }
    }
    cout<<max<<"  "<<ans<<endl;
    

  
}