#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    map<tuple<int, ll, ll>, ll> m;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        int sign = 1;
        if (a == 0 && b != 0) {
            m[make_tuple(0, 0, 1)]++;
            continue;
        }
        if (b == 0 && a != 0) {
            m[make_tuple(0, 1, 0)]++;
            continue;
        }
        if (a == 0 && b == 0) {
            m[make_tuple(0, 0, 0)]++;
            continue;
        }
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) sign = -1;
        a = abs(a);
        b = abs(b);
        ll g = gcd(a, b);
        m[make_tuple(sign, a / g, b / g)]++;
    }
    ll result = 1;
    set<tuple<int, ll, ll>> s;
    for (auto [t, x]: m) {
        auto [sign, a, b] = t;
        if (a == 0 && b == 0) continue;
        auto tt = make_tuple(-sign, b, a);
        if (s.find(tt) != s.end()) continue;
        s.insert(t);
        result *= (mod_pow(2ll, m[t], mod) + mod_pow(2ll, m[tt], mod) - 1 + mod) % mod;
        result %= mod;
    }
    result--;
    result += m[make_tuple(0, 0, 0)];
    result += mod;
    result %= mod;
    cout << result << endl;
}
