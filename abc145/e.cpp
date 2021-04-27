#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, t;
    cin >> n >> t;
    vector<vector<ll>> dp1(n+1, vector<ll>(t+1));
    vector<vector<ll>> dp2(n+1, vector<ll>(t+1));
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = t; j >= 0; --j) {
            dp1[i+1][j] = dp1[i][j];
            if (j >= a[i]) {
                dp1[i+1][j] = max(dp1[i+1][j], dp1[i][j-a[i]] + b[i]);
            }
        }
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = t; j >= 0; --j) {
            dp2[i][j] = dp2[i+1][j];
            if (j >= a[i]) {
                dp2[i][j] = max(dp2[i][j], dp2[i+1][j-a[i]] + b[i]);
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            result = max(result, dp1[i][j] + dp2[i+1][t - j - 1] + b[i]);
        }
    }
    cout << result << endl;
}