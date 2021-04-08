#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    ll result = 0;
    for (ll cd = 2; cd <= 2 * n; ++cd) {
        ll ab = k + cd;
        if (ab < 2 || ab > 2 * n) continue;
        result += min(ab - 1, 2 * n + 1 - ab) * min(cd - 1, 2 * n + 1 - cd);
    }
    cout << result << endl;
}
