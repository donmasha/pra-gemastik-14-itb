#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = 1;
        if (a[i] < a[i - 1]) {
            pre[i] += pre[i - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = 1;
        if (a[i] > a[i + 1]) {
            suf[i] += suf[i + 1];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1 + pre[i - 1]);
        ans = max(ans, 1 + suf[i + 1]);
        if (2 <= i && i <= n - 1 && a[i - 1] - 1 > a[i + 1]) {
            ans = max(ans, pre[i - 1] + 1 + suf[i + 1]);
        }
    }
    cout << ans << '\n';

    return 0;
}