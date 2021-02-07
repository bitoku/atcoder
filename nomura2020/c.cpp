#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> max_node(n+2);
    vector<int> a(n+1);
    max_node[0] = 1;
    for (int i = 0; i <= n; ++i) {
        if (max_node[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
        cin >> a[i];
        if (a[i] > max_node[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (max_node[i] - a[i] > LONG_LONG_MAX / 2) {
            max_node[i+1] = LONG_LONG_MAX;
        } else {
            max_node[i+1] = 2 * (max_node[i] - a[i]);
        }
    }
    ll result = 0;
    ll nodes = 0;
    for (int i = n; i >= 0; --i) {
        nodes = min(a[i] + nodes, max_node[i]);
        result += nodes;
    }
    cout << result << endl;
}
