#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < 100000; ++i) {
        if (i * (i + 1) / 2 >= n) {
            cout << i << endl;
            return 0;
        }
    }
}