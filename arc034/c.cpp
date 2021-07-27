#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

map<ll, ll> factorize(ll n) {
    map<ll, ll> ret;
    while (n % 2 == 0) {
        n /= 2;
        ret[2]++;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ret[i]++;
        }
    }
    if (n > 1) ret[n]++;
    return ret;
}

int main() {
    ll a, b;
    cin >> a >> b;
    map<ll, ll> mp;
    for (ll i = b + 1; i <= a; ++i) {
        map<ll, ll> m = factorize(i);
        for (auto [k, v]: m) {
            mp[k] += v;
        }
    }
    ll result = 1;
    for (auto [k, v]: mp) {
        result *= v + 1;
        result %= mod;
    }
    cout << result << endl;
}