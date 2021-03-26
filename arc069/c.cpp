#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    if (n * 2 > m) {
        cout << m / 2 << endl;
        return 0;
    }
    m -= 2 * n;
    cout << n + m / 4 << endl;
}
