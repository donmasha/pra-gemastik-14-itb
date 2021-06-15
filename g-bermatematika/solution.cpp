#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 1e18;

ll a, b;

void solve() {
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    if (a < b) swap(a, b);
    ll diff = a - b;
    ll cur = MX;
    ll ans, bk;
    for (ll i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            for (auto j : {i, diff / i}) {
                ll fac = b / j;
                bk = j * fac;
                if (bk < b) {
                    bk += j;
                    fac++;
                }
                while (__gcd(fac, diff / j) != 1) {
                    fac++;
                    bk += j;
                }
                ll tmp = bk * (bk + diff) / j;
                if (cur > tmp) {
                    cur = tmp;
                    ans = bk - b;
                } else if (cur == tmp) {
                    ans = min(ans, bk - b);
                }
            }
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