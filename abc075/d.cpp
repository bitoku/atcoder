#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll h = points[j].first - points[i].first;
            vector<ll> ys;
            for (int l = i; l <= j; ++l) {
                ys.push_back(points[l].second);
            }
            sort(ys.begin(), ys.end());
            for (int l = 0; l <= (int)ys.size() - k; ++l) {
                result = min(result, h * (ys[l + k - 1] - ys[l]));
            }
        }
    }
    cout << result << endl;
}
