#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<bool> done;
vector<int> result;

void dfs(vector<vector<int>>& v, int cur) {
    result.push_back(cur + 1);
    done[cur] = true;
    for (auto x: v[cur]) {
        if (done[x]) continue;
        dfs(v, x);
        result.push_back(cur + 1);
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    done.resize(n, false);
    dfs(v, 0);
    cout << result[0];
    for (int i = 1; i < result.size(); ++i) {
        cout << ' ' << result[i];
    }
    cout << endl;
}