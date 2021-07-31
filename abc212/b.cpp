#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
        cout << "Weak" << endl;
        return 0;
    }
    if ((s[0] - '0' + 1) % 10 == (s[1] - '0') % 10 &&
     (s[1] - '0' + 1) % 10 == (s[2] - '0') % 10 &&
    (s[2] - '0' + 1) % 10 == (s[3] - '0') % 10) {
        cout << "Weak" << endl;
        return 0;
    }
    cout << "Strong" << endl;
}