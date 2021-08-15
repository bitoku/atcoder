#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = 2 * b - a - c;
    if (x > 0) {
        cout << x << endl;
    } else {
        cout << (-x + 1) / 2 + (-x) % 2 << endl;
    }
}