#include <iostream>
using namespace std;


 bool palindrom(string st ,int i,int j){

    if(i>j){
        return true;
    }

    if(st[i]!=st[j])
    return false;

    else{
   return  palindrom(st,i+1,j-1);

    }
  

 


  
}

int main(){
    string st="bsaaaab";
  
    

    bool c=palindrom(st,0,st.length()-1);
    cout<<c;
   


}