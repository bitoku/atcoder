#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; i += 2) {
        cin >> a[i];
        a[i+1] = a[i];
    }
    ll sum = 0;
    for (int i = 1; i < 2 * n - 1; i += 2) {
        sum += abs(a[i+1] - a[i]);
    }
    for (int i = 0; i < q; ++i) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--; r--;
        if (l > 0) {
            sum -= abs(a[2 * l] - a[2 * l - 1]);
        }
        if (r < n - 1) {
            sum -= abs(a[2 * r + 2] - a[2 * r + 1]);
        }
        a[2 * l] += v;
        a[2 * r + 1] += v;
        if (l > 0) {
            sum += abs(a[2 * l] - a[2 * l - 1]);
        }
        if (r < n - 1) {
            sum += abs(a[2 * r + 2] - a[2 * r + 1]);
        }
        cout << sum << endl;
    }
}