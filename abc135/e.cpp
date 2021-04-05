#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll k;
    cin >> k;
    ll x, y;
    cin >> x >> y;
    if (k % 2 == 0 && (x + y) % 2 == 1) {
        cout << -1 << endl;
    }

}
