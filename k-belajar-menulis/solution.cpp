#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    char c[3]={'A','B','C'};
    
    int cnt=1,ans=0;
    char bef='0';
    for (int i=0;i<n-1;i++){
        if (s[i]==bef){
            for (auto ch : c){
                if (bef!=ch && s[i+1]!=ch){
                    s[i]=ch;
                    ans++;
                    break;
                }
            }
        }
        bef=s[i];
    }
    if (s[n-1]==s[n-2]){
        for(auto ch : c){
            if (ch!=s[n-2]){
                s[n-1]=ch;
                ans++;
                break;
            }
        }
    }
    
    cout << ans << endl;
    // cout << s << endl;
}