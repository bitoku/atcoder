#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s;
    cin >> s;
    s.push_back('.');
    for (ll i = a; i < c; ++i) {
        if (s[i] == '#' && s[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    bool vacant = false;
    for (ll i = b; i <= d; ++i) {
        if (s[i] == '#' && s[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
        if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
            vacant = true;
        }
    }
    if (c < d || vacant) cout << "Yes" << endl;
    else cout << "No" << endl;
}
