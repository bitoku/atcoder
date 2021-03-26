#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x;
    cin >> x;
    ll result = x / 11;
    if (x % 11 == 0) cout << result * 2 << endl;
    else if (x % 11 <= 6) cout << result * 2 + 1 << endl;
    else cout << result * 2 + 2 << endl;
}
