#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x << endl;
    } else {
        if (x != 0 && y != 0) cout << 0 << endl;
        if (x != 1 && y != 1) cout << 1 << endl;
        if (x != 2 && y != 2) cout << 2 << endl;
    }
}