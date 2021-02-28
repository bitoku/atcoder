#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int w, n, k;
    cin >> w >> n >> k;
    vector<vector<ll>> ss(w + 1, vector<ll>(k + 1));
    vector<pair<int, int>> sss(n);
    for (int i = 0; i < n; ++i) {
        cin >> sss[i].first >> sss[i].second;
    }
    for (auto [width, val] : sss) {
        for (int i = w; i >= width; --i) {
            for (int j = k; j >= 1; --j) {
                ss[i][j] = max(ss[i-width][j-1] + val, ss[i][j]);
            }
        }
    }
    cout << ss[w][k] << endl;
}
