#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        if (n % 200 == 0) n /= 200;
        else n = n * 1000 + 200;
    }
    cout << n << endl;
}