#include <iostream>
using namespace std;

int frstocc(int arr[], int n, int i, int k)
{

    if (i == n)
        return -1;

    if (arr[i] == k)
        return i;

    return frstocc(arr, n, i + 1, k);
    
}

int lastocc(int arr[], int n, int i, int k)
{
    if (i == n)
        return -1;

    int restarr = lastocc(arr, n, i + 1, k);

    if (restarr != -1)
        return restarr;
        
    if (arr[i] == k)
        return i;

    return -1;
}

int main()
{
    int arr[] = {1, 9, 2, 5, 2, 6};

    int c = frstocc(arr, 6, 0, 2);
    cout << c << endl
         << lastocc(arr, 6, 0, 2);
}