#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        p[a][b] = 1;
        p[b][a] = 1;
    }
    ll result = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bitset<12> bit(i);
        bool perf = true;
        for (int j = 0; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (!bit[j] || !bit[k]) continue;
                if (!p[j][k]) {
                    perf = false;
                    break;
                }
            }
            if (!perf) break;
        }
        if (perf) {
            result = max(result, (ll)bit.count());
        }
    }
    cout << result << endl;
}
