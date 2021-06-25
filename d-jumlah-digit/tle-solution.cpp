#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long l, r;
    long long p, q;
    cin >> l >> r >> p >> q;
    long long ans = 0;
    for (long long i = l; i <= r; i++) {
        set<int> st;
        long long cur = 0;
        long long x = i;
        while (x > 0) {
            st.emplace(x % 10);
            cur += x % 10;
            x /= 10;
        }
        int len = st.size();
        if (len < p || len > q) {
            continue;
        }
        ans += cur;
    }
    cout << ans << '\n';

    return 0;
}