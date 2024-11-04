#include <bits/stdc++.h>
using namespace std;
using i64 = long long;



void solve() {
    int n, m;
    cin >> n >> m;
    if ((n * m) % 4 != 0) {
        cout << "NO\n";
        return;
    }

    // 2 * 6 

    if (n == 1) {
        if (m % 4 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int c = 1;
            for (int j = 0; j < m; j += 4) {
                for (int i = 0; i < 4; i++) {
                    cout << c << ' ';
                }
                c++;
            }
            cout << '\n';
        }
        return;
    }

    if (m == 1) {
        if (n % 4 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int c = 1;
            for (int i = 0; i < n; i += 4) {
                for (int j = 0; j < 4; j++) {
                    cout << c << '\n';
                }
                c++;
            }
            cout << '\n';
        }
        return;
    }

    // --- ;

    auto print = [&](auto &g) {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << g[i][j] << ' ';
            }
            cout << '\n';
        }
    };
    auto _print = [&](auto &g) {
        int n = g.size(), m = g[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                cout << g[i][j] << ' ';
            }
            cout << '\n';
        }
    };

    // ---

    if (n % 4 == 0 && m % 4 == 0) {
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(m));
        int c = 1;
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < m; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        print(ans);
        return;
    }

    if (n & 1 && (n - 1) % 4 == 0 && m % 4 == 0) {
        cout << "YES\n";
        vector<vector<int>> ans(n - 1, vector<int>(m));
        int c = 1;
        for (int i = 0; i < n - 1; i += 4) {
            for (int j = 0; j < m; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        print(ans);
        for (int j = 0; j < m; j += 4) {
            for (int i = 0; i < 4; i++) {
                cout << c << ' ';
            }
            c++;
        }
        cout << '\n';
        return;
    }

    if (m & 1 && n % 4 == 0 && (m - 1) % 4 == 0) {
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(m));
        int c = 1;
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < m - 1; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < 4; j++) {
                ans[i + j][m - 1] = c;
            }
            c++;
        }
        print(ans);
        cout << '\n';
        return;
    }

    // ---

    if (n % 4 == 2 && m % 4 == 0) {
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(m));
        int c = 1;
        for (int i = 0; i < n - 2; i += 4) {
            for (int j = 0; j < m; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        for (int j = 0; j < m; j += 4) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 4; y++) {
                    int a = n - 2 + x, b = j + y;
                    if (x == 0) {
                        ans[a][b] = (y <= 2 ? c : c + 1);
                    } else {
                        ans[a][b] = (y <= 0 ? c : c + 1);
                    }
                }
            }
            c += 2;
        }
        print(ans);
        cout << '\n';
        return;
    }

    if (n & 1 && (n - 1) % 4 == 2 && m % 4 == 0) {
        cout << "YES\n";
        vector<vector<int>> ans(n - 1, vector<int>(m));
        int c = 1;
        for (int i = 0; i < n - 2 - 1; i += 4) {
            for (int j = 0; j < m; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        for (int j = 0; j < m; j += 4) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 4; y++) {
                    int a = n - 2 - 1 + x, b = j + y;
                    if (x == 0) {
                        ans[a][b] = (y <= 2 ? c : c + 1);
                    } else {
                        ans[a][b] = (y <= 0 ? c : c + 1);
                    }
                }
            }
            c += 2;
        }
        print(ans);
        for (int j = 0; j < m; j += 4) {
            for (int i = 0; i < 4; i++) {
                cout << c << ' ';
            }
            c++;
        }
        cout << '\n';
        return;
    }

    // ---


    if (n % 4 == 0 && m % 4 == 2) {
        cout << "YES\n";
        vector<vector<int>> ans(m, vector<int>(n));
        int c = 1;
        for (int i = 0; i < m - 2; i += 4) {
            for (int j = 0; j < n; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        for (int j = 0; j < n; j += 4) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 4; y++) {
                    int a = m - 2 + x, b = j + y;
                    if (x == 0) {
                        ans[a][b] = (y <= 2 ? c : c + 1);
                    } else {
                        ans[a][b] = (y <= 0 ? c : c + 1);
                    }
                }
            }
            c += 2;
        }
        _print(ans);
        cout << '\n';
        return;
    }

    if (m & 1 && n % 4 == 0 && (m - 1) % 4 == 2) {
        cout << "YES\n";
        vector<vector<int>> ans(m, vector<int>(n));
        int c = 1;
        for (int i = 0; i < m - 2 - 1; i += 4) {
            for (int j = 0; j < n; j += 4) {
                for (auto t : {0, 2}) {
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            int a = i + x + t, b = j + y;
                            if (x == 0) {
                                ans[a][b] = (y <= 2 ? c : c + 1);
                            } else {
                                ans[a][b] = (y <= 0 ? c : c + 1);
                            }
                        }
                    }
                    c += 2;
                }
            }
        }
        for (int j = 0; j < n; j += 4) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 4; y++) {
                    int a = m - 2 - 1 + x, b = j + y;
                    if (x == 0) {
                        ans[a][b] = (y <= 2 ? c : c + 1);
                    } else {
                        ans[a][b] = (y <= 0 ? c : c + 1);
                    }
                }
            }
            c += 2;
        }
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < 4; j++) {
                ans[m - 1][i + j] = c;
            }
            c++;
        }
        _print(ans);
        cout << '\n';
        return;
    }

    // ---

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}