#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << setprecision(12) << W * H / 2.0 << ' ';
    if (2 * x == W && 2 * y == H) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
