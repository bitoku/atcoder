#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

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

ll solve1(ll n) {
    vector<ll> zeronine(n+1);
    vector<ll> zero(n+1);
    vector<ll> nine(n+1);
    vector<ll> nothing(n+1);
    nothing[1] = 8;
    zero[1] = 1;
    nine[1] = 1;
    zeronine[1] = 0;
    for (int i = 1; i < n; ++i) {
        nothing[i+1] = (8 * nothing[i]) % mod;
        zero[i+1] = (nothing[i] + 9 * zero[i]) % mod;
        nine[i+1] = (nothing[i] + 9 * nine[i]) % mod;
        zeronine[i+1] = (zero[i] + nine[i] + 10 * zeronine[i]) % mod;
    }
    return zeronine[n];
}

ll solve2(ll n) {
    ll all = mod_pow(10ll, n, mod);
    ll zero_excluded = mod_pow(9ll, n, mod);
    ll nine_excluded = mod_pow(9ll, n, mod);
    ll zero_nine_excluded = mod_pow(8ll, n, mod);
    ll result = (all - zero_excluded + mod - nine_excluded + mod + zero_nine_excluded) % mod;
    return result;
}

int main() {
    ll n;
    cin >> n;
    cout << solve2(n) << endl;
}
