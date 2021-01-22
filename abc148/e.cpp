#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    ll two = 0;
    ll five = 0;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll x = 2;
    while (n / x) {
        two += n / x;
        x *= 2;
    }
    while (n % 5 != 0) {
        n -= 2;
    }
    ll y = 10;
    while (n / y) {
        five += n / y;
        y *= 5;
    }
    cout << min(two, five) << endl;
}
