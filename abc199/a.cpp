#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a * a + b * b < c * c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}