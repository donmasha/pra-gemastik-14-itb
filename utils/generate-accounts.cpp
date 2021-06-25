#include <bits/stdc++.h>

using namespace std;

const string ACCOUNTS = "accounts";
const string PASSWORD = "password"; // will change later on the DomJudge
const string TEAM = "team";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << ACCOUNTS << '\t' << 1 << '\n';
    for (string str, id, name; getline(cin, str); ) {
        stringstream ss(str);
        for (int i = 0; ss >> str; i++) {
            if (i == 0) {
                id = str;
                name = "";
            } else {
                name += (i > 1 ? " " : "") + str;
            }
        }
        string username = TEAM + id;
        vector<string> res = {
            TEAM,
            name,
            username,
            PASSWORD
        };
        int len = res.size();
        for (int i = 0; i < len; i++) {
            cout << res[i] << "\t\n"[i == len - 1];
        }
    }

    return 0;
}