#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b;
    cin >> a >> b;
    if (a <= b && b <= 6 * a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}