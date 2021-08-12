#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(6));
    ll s = 1;
    for (int i = 0; i < n; ++i) {
        ll temp = 0;
        for (int j = 0; j < 6; ++j) {
            cin >> a[i][j];
            temp += a[i][j];
        }
        s *= temp;
        s %= mod;
    }
    cout << s << endl;
}