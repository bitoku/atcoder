#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n), b(n), c(n), d(n);
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        a[i] = x[i] + y[i];
        b[i] = x[i] - y[i];
        c[i] = - x[i] + y[i];
        d[i] = - x[i] - y[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        q--;
        cout << max({
            a.back() - x[q] - y[q],
            b.back() - x[q] + y[q],
            c.back() + x[q] - y[q],
            d.back() + x[q] + y[q],
        }) << endl;
    }
}