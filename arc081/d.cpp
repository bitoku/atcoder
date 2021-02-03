#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    ll result;
    int i = 0;
    int before;
    if (s[0][i] == s[1][i]) {
        result = 3;
        i++;
        before = 1;
    } else {
        result = 6;
        i += 2;
        before = 2;
    }
    for (; i < n; ++i) {
        if (s[0][i] == s[1][i]) {
            if (before == 1) {
                result = (result * 2) % mod;
            }
            before = 1;
        } else {
            if (before == 1) {
                result = (result * 2) % mod;
            } else {
                result = (result * 3) % mod;
            }
            before = 2;
            i++;
        }
    }
    cout << result << endl;
}
