#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

ld fact[100001];

int main() {
    ll n, m;
    cin >> n >> m;
    fact[0] = 0;
    for (int i = 1; i <= n; ++i) {
        fact[i] = log10(i) + fact[i-1];
    }
    ld logp = fact[n];
    for (int i = 0; i < m; ++i) {
        ll r;
        cin >> r;
        logp -= fact[r];
    }
    logp -= log10(m) * n;
    cout << ceil(-logp) << endl;
}
