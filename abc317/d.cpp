#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> giseki(n);
    vector<ll> cost(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        giseki[i] = z;
        sum += z;
        if (x > y) cost[i] = 0;
        else cost[i] = (y - x) / 2 + 1;
    }
    vector<ll> result(sum+1);
    for(int i = 1; i <= sum; i++) {
        result[i] = LONG_LONG_MAX;
    }
    for (int i = 0; i < n; ++i) {
        for (ll j = sum; j >= giseki[i]; --j) {
            if (result[j - giseki[i]] == LONG_LONG_MAX) continue;
            result[j] = min(result[j], result[j - giseki[i]] + cost[i]);
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = sum / 2 + 1; i <= sum; ++i) {
        ans = min(ans, result[i]);
    }
    cout << ans << endl;
}