#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll answer(const vector<vector<int>>& edges, const vector<int>& h, int current, int parent) {
    ll result = 0;
    for (const auto& to : edges[current]) {
        if (to == parent) continue;
        result += answer(edges, h, to, current);
    }
    if (parent == -1) {
        return result;
    }
    if (result == 0) {
        if (h[current] == 1) return 2;
        return 0;
    }
    return result + 2;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<vector<int>> edges(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    cout << answer(edges, h, x-1, -1) << endl;
}
