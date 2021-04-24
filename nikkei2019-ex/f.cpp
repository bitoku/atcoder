#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

// TODO: solve without editorial

ll check(ll x, ll p) {
    if (p == 0) cout << x << endl;
    if (x >= 10000000000000000ll) return 0;
    if (x <= 1) return 0;
    if (x % 2 == 0) return check(x / 2, p-1) + 1;
    return check(3 * x + 1, p-1) + 1;
}

int main() {
    ll p;
    cin >> p;
    ll x = 1789997546303ll;
    check(x, 1000 - p);
}