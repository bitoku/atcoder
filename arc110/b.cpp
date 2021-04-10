#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    if (t == "0") {
        cout << 10000000000 << endl;
        return 0;
    }
    if (t == "1") {
        cout << 20000000000 << endl;
        return 0;
    }
    if (t == "10") {
        cout << 10000000000 << endl;
        return 0;
    }
    if (t == "01") {
        cout << 9999999999 << endl;
        return 0;
    }
    if (t == "11") {
        cout << 10000000000 << endl;
        return 0;
    }
    ll zero = 0;
    if (t[0] == '0') {
        zero = 0;
    } else if (t[1] == '0') {
        zero = 1;
    } else if (t[2] == '0') {
        zero = 2;
    } else {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i % 3 == zero && t[i] == '0') continue;
        if (i % 3 != zero && t[i] == '1') continue;
        cout << 0 << endl;
        return 0;
    }
    ll m = (n + 2 - zero + 2) / 3;
    cout << 10000000000 - m + 1 << endl;
}
