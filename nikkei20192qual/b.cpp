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
    int n;
    cin >> n;
    vector<ll> depth(n);
    vector<int> d(n);
    int deepest = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        depth[d[i]]++;
        deepest = max(deepest, d[i]);
    }
    if (d[0] != 0 || depth[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i <= deepest; ++i) {
        if (depth[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll result = 1;
    for (int i = 1; i <= deepest; ++i) {
        result = (result * mod_pow(depth[i-1], depth[i], mod)) % mod;
    }
    cout << result << endl;
}
