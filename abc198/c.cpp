#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll r, x, y;
    cin >> r >> x >> y;
    ll dist = 0;
    ll cnt = 0;
    ll goal = x * x + y * y;
    if (r * r > goal) {
        cout << 2 << endl;
        return 0;
    }
    while (dist * dist < goal) {
        dist += r;
        cnt++;
    }
    cout << cnt << endl;
}
