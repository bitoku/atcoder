#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(m+1);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > m) continue;
        x[a].push_back(b);
    }
    priority_queue<int> pq;
    ll result = 0;
    for (int i = 1; i <= m; ++i) {
        for (int & j : x[i]) {
            pq.push(j);
        }
        if (pq.empty()) continue;
        result += pq.top(); pq.pop();
    }
    cout << result << endl;
}
