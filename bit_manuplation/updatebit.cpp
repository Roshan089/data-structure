#include <iostream>
using namespace std;



int clearbit(int n,int pos){
    int mak= ~(1<<pos);
    return(n & (mak));
}

int updatebit(int n,int pos,int value){
    return (n | (1<<pos));
} 


int main(){
cout<< clearbit(5,2)<<endl;
}