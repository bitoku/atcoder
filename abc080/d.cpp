#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, C;
    cin >> n >> C;
    vector<vector<ll>> channel(C, vector<ll>(100002));
    for (int i = 0; i < n; ++i) {
        ll s, t, c;
        cin >> s >> t >> c;
        c--;
        for (int j = s; j <= t; ++j) {
            channel[c][j] = 1;
        }
    }
    ll result = 0;
    for (int i = 0; i <= 100000; ++i) {
        for (int j = 1; j < C; ++j) {
            channel[j][i] += channel[j-1][i];
        }
        result = max(result, channel[C-1][i]);
    }
    cout << result << endl;
}
