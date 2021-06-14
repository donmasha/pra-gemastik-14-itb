#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18 + 100;

int n;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long maxi = -INF, mini = INF;
    for (int i = 0; i < 4; i++) {
        long long pre = 1;
        for (int j = 1; j <= 3 - i; j++) {
            pre *= a[j];
        }
        long long suf = 1;
        for (int j = n; j >= n - i + 1; j--) {
            suf *= a[j];
        }
        long long cur = pre * suf;
        maxi = max(maxi, cur);
        mini = min(mini, cur);
    }
    cout << maxi << ' ' << mini << '\n';

    return 0;
}