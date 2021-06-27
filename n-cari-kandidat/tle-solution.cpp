#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
        cin >> x;
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        l--, r--;
        map<int, int> mp;
        for (int i = l; i <= r; i++) {
            mp[v[i]]++;
        }
        int ans = 0;
        for (auto& e : mp) {
            int freq = e.second;
            if (freq < p || freq > q) {
                continue;
            }
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}