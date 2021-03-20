#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<ll> hh(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        hh[a] = max(hh[a], h[b]);
        hh[b] = max(hh[b], h[a]);
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] > hh[i]) cnt++;
    }
    cout << cnt << endl;
}
