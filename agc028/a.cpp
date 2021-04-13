#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = n * m / gcd(n, m);
    map<ll, char> x;
    for (int i = 0; i < n; ++i) {
        x[i * l / n] = s[i];
    }
    for (int i = 0; i < m; ++i) {
        auto it = x.find(i * l / m);
        if (it != x.end() && (*it).second != t[i]) {
            cout << -1 << endl;
            return 0;
        }
        x[i * l / m] = t[i];
    }
    cout << l << endl;
}
