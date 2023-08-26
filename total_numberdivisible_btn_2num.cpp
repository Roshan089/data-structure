#include <iostream>
using namespace std;


 int totnum(int a,int b,int c,int d){
    int q,w,e,f;
    q=(b/c)-(b/a);
    w=(b/d)-(b/a);

    e=(b/(c*d)) -(a/(c*d));

    f=(q+w)-e;

    return f;



  
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int h = totnum(a,b,c,d);
    cout<<h;


}