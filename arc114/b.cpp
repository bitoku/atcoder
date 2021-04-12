#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        f[i]--;
    }
    vector<int> cycle(n);
    int cnt = 1;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (cycle[i] > 0) continue;
        int k = i;
        while (cycle[k] == 0) {
            cycle[k] = cnt;
            k = f[k];
        }
        if (cycle[k] == cnt) {
            result++;
        }
        cnt++;
    }
    cout << (mod_pow(2ll, result, mod) - 1 + mod) % mod << endl;
}
