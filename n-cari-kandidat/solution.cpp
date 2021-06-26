#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10;

int n, q;
int ar[N];
int ans[N];
vector<pair<pii, int>> quers;
vector<pii> asked;
int bsz;

int cnt[N];
int bit[N];

bool comp(const pair<pii, int>& a, const pair<pii, int>& b){
    pii tempa = mp((a.fi.fi - 1) / bsz, a.fi.se);
    pii tempb = mp((b.fi.fi - 1) / bsz, b.fi.se);
    if (tempa.fi & 1) tempa.se = -tempa.se;
    if (tempb.fi & 1) tempb.se = -tempb.se;
    return tempa < tempb;
}
void upd(int x, int val){
    if (x == 0) return;
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}
int ask(int l, int r){
    return ask(r) - ask(l - 1);
}
void add(int pos){
    upd(cnt[ar[pos]], -1);
    upd(++cnt[ar[pos]], 1);
}
void del(int pos){
    upd(cnt[ar[pos]], -1);
    upd(--cnt[ar[pos]], 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bsz = sqrt(n) + 1;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    cin >> q;
    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        quers.pb(mp(mp(l, r), i));
        cin >> l >> r;
        asked.pb(mp(l, r));
    }
    sort(quers.begin(), quers.end(), &comp);
    int l = 1, r = 0;
    for (auto& x : quers){
        int ll = x.fi.fi;
        int rr = x.fi.se;
        int id = x.se;
        int a = asked[id].fi;
        int b = asked[id].se;
        
        while (ll < l) add(--l);
        while (r < rr) add(++r);
        while (l < ll) del(l++);
        while (rr < r) del(r--);

        ans[id] = ask(a, b);
    }
    for (int i=0;i<q;i++){
        cout << ans[i] << el;
    }

    return 0;
}