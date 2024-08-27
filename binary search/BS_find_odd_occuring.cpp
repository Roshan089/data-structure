#include <iostream>
using namespace std;

int bs(int a[], int n, int t) {
    int s = 0;
    int e = n - 1;
    
    while(s<=e){
        int m = s + (e - s) / 2;

        if( s==e){
            return a[s];

        }
        if(m%2==0){
            if(a[m]==a[m+1]){
                s = m + 2;
            }
            else
                e = m;

        }
        else 
        if(a[m]==a[m-1]){
            s = m + 1;
        }
        else
            e = m - 1;
    }
    return 0;
}




int main() {
    int a[] = {1,1,2};
    int n = 11;
    int tar = 20;

    int result = bs(a, n, tar);
    cout << "Found: " << result << endl;

    return 0;
}
