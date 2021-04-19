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
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}
