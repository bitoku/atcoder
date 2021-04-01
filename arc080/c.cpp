#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int four = 0;
    int two = 0;
    int rest = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a % 4 == 0) {
            four++;
        } else if (a % 4 == 2) {
            two++;
        } else {
            rest++;
        }
    }
    if (two == 0) {
        if (rest > four + 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    } else {
        if (rest > four) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
