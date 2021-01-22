#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    vector<pair<int, int>> order(m);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(-a);
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        order[i] = make_pair(c, b);
    }
    sort(order.begin(), order.end());
    for (auto & i : order) {
        int b, c;
        b = i.second;
        c = i.first;
        for (int j = 0; j < b; ++j) {
            int smallest = pq.top();
            if (smallest >= c) break;
            pq.pop();
            pq.push(-c);
        }

    }

    ll result = 0;
    while (!pq.empty()) {
        result += -pq.top(); pq.pop();
    }
    cout << result << endl;
}
