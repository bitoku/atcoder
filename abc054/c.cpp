#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> pattern(n - 1);
    iota(pattern.begin(), pattern.end(), 1);
    int cnt = 0;
    do {
        vector<bool> done(n);
        int before = 0;
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if (find(edges[before].begin(), edges[before].end(), pattern[i]) == edges[before].end()) {
                ok = false;
                break;
            }
            before = pattern[i];
        }
        if (ok) {
            cnt++;
        }
    } while (next_permutation(pattern.begin(), pattern.end()));
    cout << cnt << endl;
}
