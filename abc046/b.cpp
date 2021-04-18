#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    ll result = k;
    for (int i = 0; i < n - 1; ++i) {
        result *= k - 1;
    }
    cout << result << endl;
}
