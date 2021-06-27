#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 06/28

void solve(string s) {
    if (s > "atcoder") {
        cout << 0 << endl;
        return;
    }
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] > 't') {
            cout << max(0, j - 1) << endl;
            return;
        } else if (s[j] > 'a') {
            cout << j << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        solve(s);
    }
}