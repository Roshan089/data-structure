#include <iostream>
using namespace std;

string reversearr(string a)
{
    if (a.length() == 0)
        return " ";
    char b = a[0];
    string ans = reversearr(a.substr(1));
    if (b == ans[0])
    {
        return ans;
    }
    else
        return b + ans;
        
}

int main()
{
    string a = "aabbcc";

    cout << reversearr(a);
}