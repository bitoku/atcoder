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
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < mod_pow(c, b, LONG_LONG_MAX)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}