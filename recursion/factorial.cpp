#include <iostream>
using namespace std;


 int factorial(int n ){
    if(n==1){
        return 1;
    }

    int fact= factorial(n-1);
    return n*fact;
   
}

int main(){
    int n;
    cin>>n;

    int h = factorial(n);
    cout<<h;


}