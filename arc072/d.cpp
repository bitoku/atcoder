#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/23

int main() {
    ll x, y;
    cin >> x >> y;
    if (abs(x - y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
}