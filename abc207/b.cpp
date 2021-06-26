#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d * c - b <= 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << (a + (d * c - b - 1)) / (d * c - b) << endl;
}