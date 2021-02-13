#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll b, c;
    cin >> b >> c;
    ll result = 0;
    if (c == 1) {
        if (b == 0) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return 0;
    }
    if (b > 0) {
        result = b + (c - 2) / 2 - max(1ll, b - c / 2) + 1;
        result += min(-1ll, - b + (c - 1) / 2) + b + (c - 1) / 2 + 1;
        if (b <= c / 2) {
            result++;
        }
    } else if (b < 0) {
        result = -b + (c - 1) / 2 - max(1ll, -b - (c - 1) / 2) + 1;
        result += min(-1ll, b + (c - 2) / 2) - b + c / 2 + 1;
        if (-b <= (c-1) / 2) {
            result++;
        }
    } else {
        result = (c - 1) / 2 + c / 2 + 1;
    }
    cout << result << endl;
}
