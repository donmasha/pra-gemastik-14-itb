#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = (1 << 30);

ll calc (ll N) {
    if (N <= 1) return 0;
    ll lo = 1, hi = MX, ans = 1;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        ll check = 0;
        for (int i = 30; i >= 0; i--) {
            int on = (mid >> i) & 1;
            if (on) check += (1LL << (2 * i)) * 2;
        }
        if (check > N) {
            hi = mid - 1;
        } else {
            ans = mid;
            lo = mid + 1;
        }
    }
    return ans;
}

ll L, R;

void solve() {
    cin >> L >> R;
    cout << calc(R) - calc(L - 1) << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}