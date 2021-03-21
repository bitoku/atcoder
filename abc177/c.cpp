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

int main() {
    int n;
    cin >> n;
    ll result = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        result = (result + sum * a % mod) % mod;
        sum = (sum + a) % mod;
    }
    cout << result << endl;

}
