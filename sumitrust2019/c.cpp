#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x;
    cin >> x;
    ll k = x / 100;
    if (0 <= x % 100 && x % 100 <= 5 * k) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
