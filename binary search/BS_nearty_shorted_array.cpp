#include <iostream>
using namespace std;


int bs(int a[],int n ,int t){
    int s = 0;
    int e = n;
    cout << n;
    while(s<=e){
        int m = (s + e) / 2;
        if(  a[m]==t||a[m-1]==t||a[m+1]==t)
            return a[m];

            if(a[m]>t){
                e = m - 2;
            }
            else
                m =s+ 2;
    }
    return 9;
}
int main(){
    int a[] = {20, 10, 30, 50, 40, 70, 60};
    int n = 7;
    cout << "hgv";
    int tar = 20;

    int c = bs(a, n,tar);
    cout << c;
}