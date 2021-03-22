#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll p;
    if (n >= b-1) {
        p = b - 1;
    } else {
        p = n;
    }
    cout << (a / b) * p + p * (a % b) / b << endl;
}
