#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 7> cnt {};
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }

    int c3 = 0;
    for (int i = 1; i <= 6; i++) {
        if (cnt[i] > 0 && cnt[i] != 3) {
            cout << "No\n";
            return 0;
        }
        if (cnt[i] == 3) {
            c3 += 1;
        }
    }

    cout << (c3 == 3 ? "Yes" : "No") << '\n';
    
    return 0;
}