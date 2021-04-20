#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << min({a * b, b * c, c * a}) << endl;
}
