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
    ll n, p;
    cin >> n >> p;
    map<ll, ll> f = factorize(p);
    ll result = 1;
    for (const auto [k, v]: f) {
        for (int i = 0; i < v / n; ++i) {
            result *= k;
        }
    }
    cout << result << endl;
}
