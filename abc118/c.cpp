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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll g = a[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, a[i]);
    }
    cout << g << endl;
}
