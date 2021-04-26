#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll w, a, b;
    cin >> w >> a >> b;
    if (a + w < b) {
        cout << b - a - w << endl;
    } else if (b + w < a) {
        cout << a - b - w << endl;
    } else {
        cout << 0 << endl;
    }
}