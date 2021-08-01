#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ld>> v(n);
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            // i -> j
            ld x = atan2(p[j].second - p[i].second, p[j].first - p[i].first);
            v[i].push_back(x);
            v[i].push_back(x + 2 * M_PI);
        }
        sort(v[i].begin(), v[i].end());
    }
    ld result = 0;
    for (int i = 0; i < n; ++i) {
        ll l = 0, r;
        ld temp = 0;
        for (r = 0; r < 2 * n; ++r) {
            while (v[i][r] - v[i][l] > M_PI) {
                l++;
            }
            temp = max(temp, v[i][r] - v[i][l]);
        }
        result = max(result, temp);
    }
    cout << setprecision(12) << result / (2 * M_PI) * 360 << endl;
}