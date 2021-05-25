#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        if (n % 2 == 0 && n % 4 != 0) cout << "Same" << endl;
        else if (n % 2 != 0) cout << "Odd" << endl;
        else cout << "Even" << endl;
    }
}