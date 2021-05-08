#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    k--;
    vector<ll> v(4 * n - 3);
    for (ll i = n - 1; i < 2 * n - 1; ++i) {
        v[i] = i - n + 2;
    }
    for (ll i = 2 * n - 1; i < 4 * n - 3; ++i) {
        v[i] = max(n - (i - 2 * n) - 2 , 0ll);
    }
    ll x = 0;
    for (int i = 0; i < n; ++i) {
        x += v[i];
    }
    ll d = 0;
    for (int i = 3; i <= 3 * n; ++i) {
        if (x > k) {
            d = i;
            break;
        }
        k -= x;
        x -= v[i - 3];
        x += v[i + (n - 3)];
    }
    ll a = 1;
    for (int i = 0; i < n; ++i) {
        if (k < v[d - 4 + n - i]) {
            a = i + 1;
            break;
        }
        k -= v[d - 4 + n - i];
    }
    ll b = max(d - a - n, 1ll);
    for (; k > 0; --k) {
        ++b;
    }
    cout << a << ' ' << b << ' ' << d - a - b << endl;
}