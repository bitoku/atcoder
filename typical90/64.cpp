#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll sum = 0;
    vector<ll> b(n-1);
    for (int i = 0; i < n-1; ++i) {
        b[i] = a[i+1] - a[i];
        sum += abs(b[i]);
    }
    for (int i = 0; i < q; ++i) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--; r--;
        if (l > 0) {
            sum -= abs(b[l-1]);
            b[l-1] += v;
            sum += abs(b[l-1]);
        }
        if (r < n - 1) {
            sum -= abs(b[r]);
            b[r] -= v;
            sum += abs(b[r]);
        }
        cout << sum << endl;
    }
}