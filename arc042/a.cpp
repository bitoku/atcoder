#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<bool> b(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = m - 1; i >= 0; --i) {
        if (b[a[i]]) continue;
        cout << a[i] << endl;
        b[a[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i]) continue;
        cout << i << endl;
    }
}