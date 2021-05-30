#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << endl;
    } else if (b == c) {
        cout << a << endl;
    } else if (a == c) {
        cout << b << endl;
    } else {
        cout << 0 << endl;
    }
}