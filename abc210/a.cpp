#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;
    cout << min(n, a) * x + max(n - a, 0ll) * y << endl;
}