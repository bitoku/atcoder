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
    ll n, p, k;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    auto func = [&](ll x) {
        vector<vector<ll>> b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j] == -1) b[i][j] = x;
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (b[i][j] > b[i][k] + b[k][j]) {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
        ll result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (b[i][j] <= p) result++;
            }
        }
        return result < k;
    };
    auto func2 = [&](ll x) {
        vector<vector<ll>> b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j] == -1) b[i][j] = x;
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (b[i][j] > b[i][k] + b[k][j]) {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
        ll result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (b[i][j] <= p) result++;
            }
        }
        return result <= k;
    };
    ll high = binsearch(0, LONG_LONG_MAX / 100, func);
    ll low = binsearch(0, LONG_LONG_MAX / 100, func2);
    if (high == LONG_LONG_MAX / 100) {
        if (low == LONG_LONG_MAX / 100) cout << 0 << endl;
        else cout << "Infinity" << endl;
    }
    else cout << high - low << endl;
}