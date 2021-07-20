#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll r, c, d;
    cin >> r >> c >> d;
    vector<vector<ll>> a(r, vector<ll>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    ll result = 0;
    for (int i = 0; i <= min(d, r - 1); ++i) {
        for (int j = 0; j <= min(d - i, c - 1); ++j) {
            if ((i + j) % 2 != d % 2) continue;
            result = max(result, a[i][j]);
        }
    }
    cout << result << endl;
}