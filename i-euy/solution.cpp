#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str;
    cin >> str;
    vector<int> v(3);
    for (char cc : str) {
        int num = cc - '0';
        if (num >= 3) {
            continue;
        }
        v[num]++;
    }
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        if (v[i] == 0) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "EUY" : "EDAN") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}