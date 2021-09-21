#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 09/21

int main() {
    ll n, m;
    cin >> n >> m;
    ll k = max(n, m);
    vector<ld> v(k+1);
    for (int i = 1; i <= k; ++i) {
        v[i] = log10(i);
    }
    vector<ld> sv(k+1);
    for (int i = 1; i <= k; ++i) {
        sv[i] = sv[i-1] + v[i];
    }
    ld x = 0;
    x += n * v[m];
    vector<int> r(m);
    for (int i = 0; i < m; ++i) {
        cin >> r[i];
        x += sv[r[i]];
    }
    x -= sv[n];
    cout << (int)x + 1 << endl;
}