#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/23

int main() {
    ll n;
    cin >> n;
    ll a = LONG_LONG_MAX, b = LONG_LONG_MIN, c = 0;
    for (int i = 0; i < n; ++i) {
        ll s, t;
        cin >> s >> t;
        if (t == 1) {
            c += s;
        } else if (t == 2) {
            b = max(b, s - c);
        } else {
            b = min(b, s - c);
            a = min(a, s - c);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        cout << max(min(x, a), b) + c << endl;
    }
}