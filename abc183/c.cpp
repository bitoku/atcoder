#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    ll c, d;
    cin >> a >> b;
    cin >> c >> d;
    if (a == c && b == d) {
        cout << 0 << endl;
        return 0;
    }
    if (a + b == c + d || a - b == c - d || abs(a-c) + abs(b-d) <= 3) {
        cout << 1 << endl;
        return 0;
    }
    if (
        (a + b) % 2 == (c + d) % 2 ||
        (a + b + 1) == c + d ||
        (a + b + 2) == c + d ||
        (a + b + 3) == c + d ||
        (a + b - 1) == c + d ||
        (a + b - 2) == c + d ||
        (a + b - 3) == c + d ||
        (a - b + 1) == c - d ||
        (a - b + 2) == c - d ||
        (a - b + 3) == c - d ||
        (a - b - 1) == c - d ||
        (a - b - 2) == c - d ||
        (a - b - 3) == c - d
        ) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
}
