#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') x++;
        else x--;
        mx = max(mx, x);
    }
    cout << mx << endl;
}
