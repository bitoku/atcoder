#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0) {
        if (abs(a) < abs(b)) cout << '<' << endl;
        else if (abs(a) > abs(b)) cout << '>' << endl;
        else cout << '=' << endl;
        return 0;
    }
    if (a >= 0 && b >= 0) {
        if (abs(a) < abs(b)) cout << '<' << endl;
        else if (abs(a) > abs(b)) cout << '>' << endl;
        else cout << '=' << endl;
    }
    else if (a < 0 && b < 0) {
        if (abs(a) < abs(b)) cout << '>' << endl;
        else if (abs(a) > abs(b)) cout << '<' << endl;
        else cout << '=' << endl;
    }
    else if (a >= 0 && b < 0) {
        cout << '>' << endl;
    }
    else {
        cout << '<' << endl;
    }
}