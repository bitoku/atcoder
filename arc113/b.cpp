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
    ll a, b, c;
    cin >> a >> b >> c;
    vector<vector<int>> loop = {
            {0},
            {1},
            {2, 4, 8, 6},
            {3, 9, 7, 1},
            {4, 6},
            {5},
            {6},
            {7, 9, 3, 1},
            {8, 4, 2, 6},
            {9, 1},
            };
    int one = a % 10;
    ll r = mod_pow(b, c, (ll)loop[one].size());
    cout << loop[one][(loop[one].size() + r - 1) % loop[one].size()] << endl;
}
