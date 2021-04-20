#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

map<ll, ll> factorize(ll n) {
    map<ll, ll> m;
    ll lim = (ll)sqrt(n) + 10;
    while (n % 2 == 0) {
        n >>= 1;
        m[2]++;
    }
    for (int i = 3; i < lim; i += 2) {
        while (n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    if (n > 1) m[n]++;
    return m;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        map<ll, ll> m = factorize(a[i]);
        ll d = 0;
        for (const auto [x, y]: m) {
            d += y;
        }
        a[i] = d;
        result ^= a[i];
    }
    if (result == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
