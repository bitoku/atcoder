#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pref(n+1);
    vector<pair<int, int>> city(m);
    for (int i = 0; i < m; ++i) {
        int p, y;
        cin >> p >> y;
        city[i] = make_pair(p, y);
        pref[p].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        sort(pref[i].begin(), pref[i].end());
    }
    for (int i = 0; i < m; ++i) {
        int p = city[i].first;
        int y = city[i].second;
        int d = distance(pref[p].begin(), lower_bound(pref[p].begin(), pref[p].end(), y)) + 1;
        printf("%06d%06d\n", p, d);
    }
}
