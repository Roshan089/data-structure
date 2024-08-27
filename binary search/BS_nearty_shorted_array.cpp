#include <iostream>
using namespace std;

int bs(int a[], int n, int t) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int m = (s + e) / 2;

        // Check if the target is found within the middle three elements
        if (a[m] == t) return a[m];
        if (m > 0 && a[m - 1] == t) return a[m - 1];
        if (m < n - 1 && a[m + 1] == t) return a[m + 1];

        // Adjust the search range based on the comparison
        if (a[m] > t) {
            e = m - 2; // Search in the left sub-array
        } else {
            s = m + 2; // Search in the right sub-array
        }
    }
    return -1; // Return -1 if the target is not found
}




int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int tar = 20;

    int result = bs(a, n, tar);
    cout << "Found: " << result << endl;

    return 0;
}
