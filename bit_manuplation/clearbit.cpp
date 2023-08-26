#include <iostream>
using namespace std;



int clearbit(int n,int pos){
    int mak= ~(1<<pos);
    return(n & (mak));
}

int main(){
cout<< clearbit(5,2)<<endl;
}