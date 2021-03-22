#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x;
    cin >> x;
    unordered_map<ll, ll> f;
    for (ll i = -1000; i <= 1000; ++i) {
        f[i] = i * i * i * i * i;
    }
    for (int i = -1000; i <= 1000; ++i) {
        for (int j = -1000; j <= 1000; ++j) {
            if (f[i] - f[j] == x) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
}
