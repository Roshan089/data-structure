#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char getMaxOccurringChar(const string& str) {
    // Create an unordered_map to store the frequency of every character
    unordered_map<char, int> mp;

    int n = str.length();
    char ans = '\0';
    int count = 0;

    // Iterate through the string and update the map and the most frequent character
    for (int i = 0; i < n; ++i) {
        mp[str[i]]++;
        
        if (count < mp[str[i]]) {
            count = mp[str[i]];
            ans = str[i];
        }
    }

    return ans;
}

// Driver Code
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Max occurring character is: "
         << getMaxOccurringChar(str) << endl;
    return 0;
}
