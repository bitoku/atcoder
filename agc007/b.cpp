#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 09/21

int main() {
    ll n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i+1;
    }
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        a[i] = 30000 * (i + 1);
        b[i] = 600000000 + q[i] - 30000 * (i + 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
}