#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义结构体用于存储每个区间的开始和结束位置以及评分
struct Contest {
    int start, end, score;
};

// 比较函数，用于排序
bool compare(const Contest& a, const Contest& b) {
    return a.end < b.end;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Contest> contests(n);
        for (int i = 0; i < n; ++i) {
            cin >> contests[i].start >> contests[i].end >> contests[i].score;
        }

        // 对比赛进行排序
        sort(contests.begin(), contests.end(), compare);

        // 动态规划数组，dp[i]表示考虑前i个比赛时能获得的最大评分
        vector<int> dp(n, 0);
        vector<int> p(n, -1); // 记录最后一个与第i个比赛不重叠的比赛的索引

        // 填充p数组
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (contests[j].end <= contests[i].start) {
                    p[i] = j;
                    break;
                }
            }
        }

        // 动态规划求解
        for (int i = 0; i < n; ++i) {
            dp[i] = max(dp[i - 1], contests[i].score + (p[i] != -1 ? dp[p[i]] : 0));
        }

        // 输出最大评分
        cout << dp[n - 1] << endl;
    }
    return 0;
}