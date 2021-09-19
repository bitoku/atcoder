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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        map<ll, ll> mp = factorize(a[i]);
        for (auto [g, h]: mp) {
            x[g] = max(x[g], x[h]);
        }
    }
    vector<ll> v;
    for (int i = 1; i <= m; ++i) {
        map<ll, ll> mp = factorize(i);
        if (any_of(mp.begin(), mp.end(), [&](pair<ll, ll> p){
            return x.find(p.first) != x.end();
        })) {
            continue;
        }
        v.push_back(i);
    }
    cout << v.size() << endl;
    for (auto y: v) {
        cout << y << endl;
    }
}