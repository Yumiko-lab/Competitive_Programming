#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    vector<int> bits;
    for (int i = 0; i < 60; i++) {
        if (n >> i & 1) {
            bits.emplace_back(i);
        }
    }

    int m = bits.size();
    for (int i = 0; i < 1 << m; i++) {
        i64 now = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                now |= (1LL << bits[j]);
            }
        }
        cout << now << '\n';
    }
    
    return 0;
}