#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k % 2 == 0) {
        cout << a - b << endl;
    } else {
        cout << b - a << endl;
    }
}
