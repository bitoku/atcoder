#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 07/29

vector<ll> get_primes(ll n) {
    vector<bool> b(n+1, true);
    b[0] = b[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (!b[i]) continue;
        for (int j = 2; i * j <= n; ++j) {
            b[i * j] = false;
        }
    }
    vector<ll> primes;
    for (int i = 2; i <= n; ++i) {
        if (!b[i]) continue;
        primes.push_back(i);
    }
    return primes;
}

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    ll m = a[0];
    ll g = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
        g = gcd(g, a[i]);
    }
    if (g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    vector<ll> primes = get_primes(m);
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        ll t = a[i];
        for (auto p: primes) {
            if (p * p > a[i]) break;
            if (t % p == 0) {
                mp[p]++;
            }
            while (t % p == 0) t /= p;
        }
        if (t > 1) {
            mp[t]++;
        }
    }
    for (auto [x, y]: mp) {
        if (y > 1) {
            cout << "setwise coprime" << endl;
            return 0;
        }
    }
    cout << "pairwise coprime" << endl;
}