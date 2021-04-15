#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0) {
        cout << (b - a) / 2 << endl;
        return 0;
    }
    cout << min(n - b, a - 1) + 1 + (b - a - 1) / 2 << endl;
}
