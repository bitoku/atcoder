#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int n;

ll longest(int x, vector<vector<ll>>& c, vector<bool> done) {
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (done[i]) continue;
        if (x == i) continue;
        if (c[x][i] == 0) continue;
        done[i] = true;
        result = max(result, c[x][i] + longest(i, c, done));
        done[i] = false;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    int m;
    cin >> m;
    vector<vector<ll>> c(n, vector<ll>(n));
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int t;
        cin >> t;
        c[a][b] = t;
        c[b][a] = t;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> done(n);
        done[i] = true;
        result = max(result, longest(i, c, done));
        done[i] = false;
    }
    cout << result << endl;
}