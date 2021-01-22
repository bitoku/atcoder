#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> order(n+m);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        order[i] = make_pair(a, 1);
    }
    for (int i = n; i < n+m; ++i) {
        int b, c;
        cin >> b >> c;
        order[i] = make_pair(c, b);
    }
    sort(order.begin(), order.end(), greater<>());
    ll result = 0;
    int used = 0;
    for (int i = 0; i < n+m && used < n; ++i) {
        if (used + order[i].second > n) {
            result += order[i].first * (n - used);
            used = n;
        } else {
            result += order[i].first * order[i].second;
            used += order[i].second;
        }
    }
    cout << result << endl;
}
