#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (auto x: v[i]) {
            if (x < i) cnt++;
        }
        if (cnt == 1) result++;
    }
    cout << result << endl;
}