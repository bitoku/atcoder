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
    ll a, b;
    cin >> a >> b;
    for (int i = b / 2; i >= 1; --i) {
        ll x = (a + i - 1) / i * i;
        ll y = x + i;
        if (x <= b && y <= b) {
            cout << i << endl;
            return 0;
        }
    }
}