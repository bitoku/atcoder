#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < (k + 1) / 2; ++i) {
        cout << i + 1 << ' ' << (k + 1) / 2 * 2 - i << endl;
    }
    for (int i = 0; i < k / 2; ++i) {
        cout << (k + 1) / 2 * 2 + i + 1 << ' ' << (k + 1) / 2 * 2 + 1 + k / 2 * 2 - i << endl;
    }
}