#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; ++i) {
        int k = pq.top(); pq.pop();
        pq.push(k / 2);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += pq.top(); pq.pop();
    }
    cout << ans << endl;
}
