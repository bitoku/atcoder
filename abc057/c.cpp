#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int digits(ll n) {
    return to_string(n).size();
}

int main() {
    ll n;
    cin >> n;
    ll lim = (ll)sqrt(n);
    ll factor = 1;
    if (n % 2 == 0) factor = 2;
    for (ll i = 3; i <= lim; i+=2) {
        if (n % i == 0) factor = i;
    }
    cout << digits(n / factor) << endl;
}
