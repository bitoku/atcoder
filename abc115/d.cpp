#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll burger(ll n) {
    return 4 * mod_pow(2ll, n, LONG_LONG_MAX) - 3;
}

ll patty(ll n) {
    if (n == 0) {
        return 1;
    }
    return 2 * patty(n - 1) + 1;
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll result = 0;
    while (x > 0) {
        bool bite = false;
        for (int i = n; i >= 0; --i) {
            ll pile = burger(i) + n - i;
            if (pile > x) continue;
            bite = true;
            result += patty(i);
            x -= pile;
            n = i;
            break;
        }
        if (!bite) break;
        if (x > 0) {
            x--;
            result++;
        }
    }
    cout << result << endl;
}
