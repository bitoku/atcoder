#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

template< typename T >
T euler(T n) {
    T result = n;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            result -= result / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, s, k;
        cin >> n >> s >> k;
        ll g = gcd(n, k);
        if (s % g != 0) {
            cout << -1 << endl;
            continue;
        }
        n /= g; s /= g; k /= g;
        vector<ll> divisors;
        ll e = euler(n);
        ll x = n - s;
        cout << x * mod_pow(k, e - 1, n) % n << endl;
    }
}
