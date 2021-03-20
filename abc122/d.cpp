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
    ll n;
    cin >> n;
    vector<ll> s[4][4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                s[i][j][k].resize(n+1);
                s[i][j][k][3] = 1;
            }
        }
    }
    s[0][2][1][3] = 0;
    s[2][0][1][3] = 0;
    s[0][1][2][3] = 0;
    for (int i = 3; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    s[k][l][0][i+1] = (s[k][l][0][i+1] + s[j][k][l][i]) % mod;
                    if (!((j == 0 && l == 2) || (j == 0 && k == 2) || (k == 0 && l == 2) || (k == 2 && l == 0))) {
                        s[k][l][1][i+1] = (s[k][l][1][i+1] + s[j][k][l][i]) % mod;
                    }
                    if (!(k == 0 && l == 1)) {
                        s[k][l][2][i+1] = (s[k][l][2][i+1] + s[j][k][l][i]) % mod;
                    }
                    s[k][l][3][i+1] = (s[k][l][3][i+1] + s[j][k][l][i]) % mod;
                }
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                result += s[i][j][k][n];
            }
        }
    }
    cout << result % mod << endl;
}
