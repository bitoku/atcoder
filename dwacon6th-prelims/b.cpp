#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

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
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        mod_fact(n);
    }
    ll result = 0;
    ll psum = 0;
    for (int i = 1; i < n; ++i) {
        ll diff = x[i] - x[i-1];
        psum += mod_fact(n - 1) * mod_pow((ll)i, mod - 2) % mod;
        psum %= mod;
        result += diff * psum % mod;
        result %= mod;
    }
    cout << result << endl;
}