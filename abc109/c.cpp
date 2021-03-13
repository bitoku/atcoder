#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n, X;
    cin >> n >> X;
    vector<ll> x(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    x[n] = X;
    sort(x.begin(), x.end());
    ll g = x[1] - x[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, x[i+1] - x[i]);
    }
    cout << g << endl;
}
