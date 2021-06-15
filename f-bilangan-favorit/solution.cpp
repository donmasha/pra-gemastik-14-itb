#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const ll MOD = 1e9 + 7;

ll fc[N + 5];
ll ans;
int a, b, n;

bool good(int x) {
    bool ans = true;
    while (x) {
        ans &= (x % 10 == a) || (x % 10 == b);
        x /= 10;
    }
    return ans;
}

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

ll C(ll a, ll b) {
    ll ret = (fc[a] * inv(fc[b])) % MOD;
    ret = (ret * inv(fc[a - b])) % MOD;
    return ret;
}

void solve() {
    cin >> a >> b >> n;
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= n; i++) {
        ll sum = a * i + b * (n - i);
        if (good(sum)) {
            ans = (ans + C(n, i)) % MOD;
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