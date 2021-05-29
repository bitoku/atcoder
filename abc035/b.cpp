#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll t;
    cin >> t;
    ll x = 0, y = 0;
    ll hatena = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (s[i] == '?') hatena++;
    }
    if (t == 1) {
        cout << abs(y) + abs(x) + hatena << endl;
    } else {
        if (abs(x) + abs(y) > hatena) {
            cout << abs(x) + abs(y) - hatena << endl;
        } else if ((hatena - abs(x) - abs(y)) % 2 == 0) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}