#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll result = h[k - 1] - h[0];
    for (int i = 1; i <= n - k; ++i) {
        result = min(result, h[i + k - 1] - h[i]);
    }
    cout << result << endl;
}
