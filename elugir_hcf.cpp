#include <iostream>
using namespace std;


 int hcf(int a,int b){

    while(b){
    int rem=a%b;
    a=b;
    b=rem;
    }
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;

    int c = hcf(a,b);
    cout<<c;


}