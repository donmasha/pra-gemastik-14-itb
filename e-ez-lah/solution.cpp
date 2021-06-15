#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int n;

void solve() {
    cin >> n;
    vector<int> ve(n);
    int mn = INF;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        mn = min(mn, ve[i]);
    }
    int last_idx = -1;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (ve[i] == mn) {
            if (last_idx != -1) {
                ans = min(ans, i - last_idx);
            }
            last_idx = i;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}