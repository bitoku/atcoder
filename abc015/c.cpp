#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> t[i][j];
        }
    }
    ll limit = 1;
    for (int i = 0; i < n; ++i) {
        limit *= k;
    }
    for (int i = 0; i < limit; ++i) {
        ll offset = 1;
        ll temp = 0;
        for (int j = 0; j < n; ++j) {
            temp ^= t[j][i / offset % k];
            offset *= k;
        }
        if (temp == 0) {
            cout << "Found" << endl;
            return 0;
        }
    }
    cout << "Nothing" << endl;
}