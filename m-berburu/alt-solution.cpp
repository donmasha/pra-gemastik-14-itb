#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define el '\n'
#define MOD 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cost[n+1],arr[n+1];
    bool hist[n+1];
    ll ans=0;

    for (int i=1;i<=n;i++){
        cin >> cost[i];
        hist[i]=0;
    }

    for (int i=1;i<=n;i++){
        cin >> arr[i];
        if (arr[i]==i){
            ans+=cost[i];
            hist[i]=1;
        }
    }

    for (int i=1;i<=n;i++){
        if (hist[i])
            continue;

        map<int,bool> udah;
        int now=i;

        while (!hist[now]){
            hist[now]=1;
            udah[now]=1;
            now=arr[now];
        }

        if (udah[now]==1){
            int st=arr[now];
            int cmin=cost[now];

            while (st!=now){
                cmin=min(cmin,cost[st]);
                st=arr[st];
            }

            ans+=cmin;
        }

    }

    cout << ans << el;
}