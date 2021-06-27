#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        a[i] = cc - 'A';
    }
    vector<vector<int>> dp(n, vector<int>(3, INF));
    for (int j = 0; j < 3; j++) {
        dp[0][j] = (a[0] != j);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cst = (a[i] != j);
            for (int k = 0; k < 3; k++) {
                if (j == k) {
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cst);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j < 3; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    cout << ans << '\n';

    return 0;
}