#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    string t;
    cin >> s >> t;
    char s2t[26] = {0};
    char t2s[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        int sc = s[i] - 'a';
        int tc = t[i] - 'a';
        if ((s2t[sc] > 0 && s2t[sc] != t[i]) || (t2s[tc] > 0 && t2s[tc] != s[i])) {
            cout << "No" << endl;
            return 0;
        } else {
            s2t[sc] = t[i];
            t2s[tc] = s[i];
        }
    }
    for (int i = 0; i < 26; ++i) {

    }
    cout << "Yes" << endl;
}
