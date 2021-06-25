#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+3;
int n,m;
vector<int> v[N];
int vis[N];
priority_queue<int, vector<int>, greater<int> > pq;

void dfs(int s){
    vis[s] = 1;
    cout << s << " ";
    for(auto e:v[s]){
        if(!vis[e]){
            vis[e] = 1;
            pq.push(e);
        }
    }

    if(!pq.empty()){
        int k = pq.top();
        pq.pop();
        dfs(k);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,m){
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    return 0;
}
