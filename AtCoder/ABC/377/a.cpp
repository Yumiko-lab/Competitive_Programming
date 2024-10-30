#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << (s == "ABC" ? "Yes" : "No") << '\n';
    
    return 0;
}