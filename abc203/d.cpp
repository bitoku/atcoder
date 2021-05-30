#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    auto func = [&](ll x) {
        vector<vector<ll>> over(n+1, vector<ll>(n+1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] > x) over[i+1][j+1] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                over[i][j] += over[i][j-1];
            }
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                over[i][j] += over[i-1][j];
            }
        }
        for (int i = 0; i <= n-k; ++i) {
            for (int j = 0; j <= n-k; ++j) {
                ll o = over[i + k][j + k] - over[i + k][j] - over[i][j + k] + over[i][j];
                if (o <= k * k / 2) return false;
            }
        }
        return true;
    };
    cout << binsearch(1000000010, -1, func) + 1 << endl;
}