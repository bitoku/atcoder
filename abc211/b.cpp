#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s[4];
    for (int i = 0; i < 4; ++i) {
        cin >> s[i];
    }
    int hit[4] = {};
    for (int i = 0; i < 4; ++i) {
        if (s[i] == "H") hit[0] = 1;
        if (s[i] == "2B") hit[1] = 1;
        if (s[i] == "3B") hit[2] = 1;
        if (s[i] == "HR") hit[3] = 1;
    }
    if (hit[0] && hit[1] && hit[2] && hit[3]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}