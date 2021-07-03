#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


ll dfs(vector<vector<int>>& v, int cur) {
    ll a=0, b=INT_MAX;
    for (auto x: v[cur]) {
        ll k = dfs(v, x);
        a = max(a, k);
        b = min(b, k);
    }
    if (b == INT_MAX) b = 0;
    return a + b + 1;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> b;
        b--;
        v[b].push_back(i);
    }
    cout << dfs(v, 0) << endl;
}