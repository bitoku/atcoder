#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 4/25 AC

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> g(n);
    vector<ll> gr(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    g[0] = a[0];
    for (int i = 1; i < n; ++i) {
        g[i] = gcd(g[i-1], a[i]);
    }
    gr[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        gr[i] = gcd(gr[i+1], a[i]);
    }
    ll m = max(gr[1], g[n - 2]);
    for (int i = 1; i < n - 1; ++i) {
        m = max(m, gcd(g[i - 1], gr[i + 1]));
    }
    cout << m << endl;

}