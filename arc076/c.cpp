#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll fact(ll n) {
    if (n == 0) return 1;
    return n * fact(n - 1) % mod;
}

int main() {
    ll n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    if (n - m > 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == m) {
        cout << 2 * fact(n) * fact(m) % mod << endl;
    } else {
        cout << fact(n) * fact(m) % mod << endl;
    }
}
