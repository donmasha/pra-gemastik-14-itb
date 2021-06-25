#include <bits/stdc++.h>

using namespace std;

const string FILE_VERSION = "teams";
const string COMP = "pgm"; // pragemastik
const string INSTITUTION_N = "Institut Teknologi Bandung";
const string INSTITUTION_SN = "ITB";
const string COUNTRY = "IDN";
const string CATEGORY_ID = "3";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << FILE_VERSION << '\t' << 1 << '\n';
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
        vector<string> res = {
            id,
            COMP + id,
            CATEGORY_ID,
            name,
            INSTITUTION_N,
            INSTITUTION_SN,
            COUNTRY
        };
        int len = res.size();
        for (int i = 0; i < len; i++) {
            cout << res[i] << "\t\n"[i == len - 1];
        }
    }

    return 0;
}