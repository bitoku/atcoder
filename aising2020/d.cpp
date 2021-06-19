#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVE

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') a++;
    }
    vector<ll> plus(n);
    plus[0] = 1;
    for (int i = 1; i < n; ++i) {
        plus[i] = (plus[i-1] << 1) % (a + 1);
    }
    ll plusx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') plusx = (plusx + plus[i]) % (a + 1);
    }

    vector<ll> minus(n);
    ll minusx = 0;
    minus[0] = 1;
    if (a > 1) {
        for (int i = 1; i < n; ++i) {
            minus[i] = (minus[i - 1] << 1) % (a - 1);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') minusx = (minusx + minus[i]) % (a - 1);
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == '0') {
            ll result = 1;
            ll x = (plusx + plus[i]) % (a + 1);
            while (x > 0) {
                x %= __builtin_popcount(x);
                result++;
            }
            cout << result << endl;
        } else {
            if (a == 1) {
                cout << 0 << endl;
                continue;
            }
            ll result = 1;
            ll x = (minusx - minus[i] + a - 1) % (a - 1);
            while (x > 0) {
                x %= __builtin_popcount(x);
                result++;
            }
            cout << result << endl;
        }
    }
}