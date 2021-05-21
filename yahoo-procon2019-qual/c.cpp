#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll result = 0;
    ll rest = k + 1 - a;
    result = rest / 2 * (b - a) + a;
    result += rest % 2;
    cout << max(k+1, result) << endl;
}