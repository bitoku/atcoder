#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll k = 0;
    ll m = 1;
    while (m <= n) {
        m <<= 1;
        k++;
    }
    cout << k - 1 << endl;
}