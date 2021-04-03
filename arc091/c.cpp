#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll result = 0;
    // corner = 0
    if (n == 1 && m == 1) {
        result++;
    } else if (n == 1 || m == 1) {
        if (m == 1) swap(n, m);
        result += m - 2;
    } else {
        result += max(n - 2, 0ll) * max(m - 2, 0ll);
    }
    cout << result << endl;
}
