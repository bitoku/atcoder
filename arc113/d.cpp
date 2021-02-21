#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

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
    ll n, m, k;
    cin >> n >> m >> k;
    ll result = 0;
    ll num_a_sum = 0;
    if (n == 1 && m == 1) {
        cout << k << endl;
        return 0;
    }
    if (n == 1 || m == 1) {
        if (m == 1) swap(n, m);
        for (int i = 1; i <= k; ++i) {
            result += (mod + mod_pow((ll)i, m, mod) - mod_pow((ll)(i-1), m, mod)) % mod;
            result %= mod;
        }
        cout << result << endl;
        return 0;
    }
    for (int i = 1; i <= k; ++i) {
        ll num_a = (mod + mod_pow((ll)i, n, mod) - num_a_sum) % mod;
        result += num_a * mod_pow(k - i + 1, m, mod) % mod;
        result %= mod;
        num_a_sum += num_a;
        num_a_sum %= mod;
    }
    cout << result << endl;
}
