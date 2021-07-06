#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    ll t = 0;
    int ai = 0, bi = 0;
    ll result = 0;
    while (true) {
        while (ai < a.size()) {
            if (t <= a[ai]) break;
            ai++;
        }
        if (ai >= a.size()) break;
        t = a[ai] + x;
        while (bi < b.size()) {
            if (t <= b[bi]) break;
            bi++;
        }
        if (bi >= b.size()) break;
        t = b[bi] + y;
        result++;
    }
    cout << result << endl;
}