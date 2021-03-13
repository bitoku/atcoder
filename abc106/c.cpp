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

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        if (s[i] != '1') {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
