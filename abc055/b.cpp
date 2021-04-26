#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % mod;
    }
    cout << result << endl;
}