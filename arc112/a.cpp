#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int l, r;
        ll result = 0;
        cin >> l >> r;
//        for (int a = 2 * l; a <= r; ++a) {
//            result += (a - l) - l + 1;
//        }
        result = (ll)(2 * l + r) * max(0, (r - 2 * l + 1)) / 2 - (ll)(2 * l - 1) * max(0, (r - 2 * l + 1));
        cout << result << endl;
    }
}
