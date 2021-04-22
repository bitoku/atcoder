#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c - a - b < 0) {
        cout << "No" << endl;
        return 0;
    }
    if (4 * a * b < (c - a - b) * (c - a - b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
