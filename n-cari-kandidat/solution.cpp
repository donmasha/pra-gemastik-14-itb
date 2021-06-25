#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const int INF = 1e9 + 10;

int n, q;
int ar[N];
vector<int> pos[N];
vector<pair<int, pii>> vec;
vector<vector<pair<int, pii>>> t;

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v].pb(vec[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].resize(tr - tl + 1);
    merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
    pii mx = {-1, -1};
    for (auto& x : t[v]){
        mx = max(mx, x.se);
        x.se = mx;
    }
}
pii ask(int v, int tl, int tr, int l, int r, int left){
    if (l > r || tr < l || r < tl) return mp(-1, -1);
    if (l <= tl && tr <= r){
        pair<int, pii> cari = mp(left, mp(INF, INF));
        auto it = upper_bound(t[v].begin(), t[v].end(), cari);
        if (it == t[v].begin()) return mp(-1, -1);
        it--;
        return it->se;
    }
    int tm = (tl + tr) / 2;
    return max(ask(v * 2, tl, tm, l, r, left), ask(v * 2 + 1, tm + 1, tr, l, r, left));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (pos[ar[i]].empty()) pos[ar[i]].pb(0);
        pos[ar[i]].pb(i);
    }
    vec.resize(n + 1);
    t.resize(n * 4 + 1);
    for (int i=1;i<N;i++){
        if (pos[i].size()) pos[i].pb(n + 1);
        int len = pos[i].size();
        for (int j=1;j<len - 1;j++){
            int l = pos[i][j - 1] + 1;
            int cur = pos[i][j];
            int r = pos[i][j + 1] - 1;
            vec[cur] = mp(l, mp(r, i));
        }
    }
    build(1, 1, n);
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        auto temp = ask(1, 1, n, l, r, l);
        if (r <= temp.fi) cout << temp.se << el;
        else cout << -1 << el;
    }

    return 0;
}