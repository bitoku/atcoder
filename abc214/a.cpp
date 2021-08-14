#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    if (n <= 125) {
        cout << 4 << endl;
    } else if (n <= 211) {
        cout << 6 << endl;
    } else {
        cout << 8 << endl;
    }
}