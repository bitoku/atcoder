#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c - b == b - a || c - a == a - b || b - c == c - a || b - a == a - c || a - c == c - b || a - b == b - c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}