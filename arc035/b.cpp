#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

unordered_map<ll, ll> fact_memo;
ll mod_fact(ll x) {
    if (fact_memo.find(x) != fact_memo.end()) return fact_memo[x];
    if (x == 0) return 1;
    fact_memo[x] = x * mod_fact(x - 1) % mod;
    return fact_memo[x];
}

int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        m[t]++;
    }
    ll penalty = 0;
    ll patterns = 1;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        mod_fact(i);
    }
    for (auto [a, b]: m) {
        penalty += t * b + b * (a + a * b) / 2;
        t += a * b;
        patterns *= mod_fact(b);
        patterns %= mod;
    }
    cout << penalty << endl;
    cout << patterns << endl;
}