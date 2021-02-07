#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    ll cnt = 0;
    if (d == 0) {
        cnt = n;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i - d > 0) cnt++;
            if (i + d <= n) cnt++;
        }
    }
    cout << setprecision(8) << cnt * (m - 1) / (double)n / n << endl;
}
