#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x, y;
    cin >> x >> y;
    ll result = LONG_LONG_MAX;
    if (x <= y) {
        result = min(result, y - x);
    }
    if (-x <= -y) {
        result = min(result, -y + x + 2);
    }
    if (-x <= y) {
        result = min(result, y + x + 1);
    }
    if (x <= -y) {
        result = min(result, -y - x + 1);
    }
    cout << result << endl;
}
