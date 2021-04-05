#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n, q;
    cin >> n;
    ll s = 0;
    ll mn = LONG_LONG_MAX / 2;
    ll mx = LONG_LONG_MIN / 2;
    for (int i = 0; i < n; ++i) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            s += a;
            mn += a;
            mx += a;
        } else if (t == 2) {
            mx = max(mx, a);
            mn = max(mn, a);
        } else if (t == 3) {
            mn = min(mn, a);
            mx = min(mx, a);
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        cout << max(mx, min(mn, x + s)) << endl;
    }
}
