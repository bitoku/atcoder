#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    if (m < 0 || m > n - 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << ' ' << 100000000 << endl;
    for (int i = 1; i <= m + 1; ++i) {
        cout << 2 * i << ' ' << 2 * i + 1 << endl;
    }
    for (int i = 1; i <= n - m - 2; ++i) {
        cout << 100000000 + 2 * i << ' ' << 100000000 + 2 * i + 1 << endl;
    }
}
