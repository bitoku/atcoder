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
    int h, w;
    cin >> h >> w;
    vector<string> s(h + 2);
    vector<vector<ll>> cross(h + 2, vector<ll>(w+2));
    s[0] = string(w + 2, '#');
    s[h+1] = string(w + 2, '#');
    for (int i = 1; i <= h; ++i) {
        cin >> s[i];
        s[i] = '#' + s[i] + '#';
    }
    ll l = 0;
    for (int i = 1; i <= h; ++i) {
        ll temp = 0;
        for (int j = 0; j <= w; ++j) {
            if (s[i][j] == '.') {
                cross[i][j] += temp - 1;
                l++;
                continue;
            }
            temp = 0;
            for (int k = j + 1; k <= w; ++k) {
                if (s[i][k] == '.') temp++;
                else break;
            }
        }
    }
    for (int j = 1; j <= w; ++j) {
        ll temp = 0;
        for (int i = 0; i <= h; ++i) {
            if (s[i][j] == '.') {
                cross[i][j] += temp;
                continue;
            }
            temp = 0;
            for (int k = i + 1; k <= h; ++k) {
                if (s[k][j] == '.') temp++;
                else break;
            }
        }
    }
    ll result = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            result += (mod_pow(2ll, cross[i][j], mod) - 1) * (mod_pow(2ll, l - cross[i][j], mod)) % mod;
            result %= mod;
        }
    }
    cout << result << endl;
}
