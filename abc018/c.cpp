#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll r, c, k;
    cin >> r >> c >> k;
    vector<string> s(r + 2);
    s[0] = string(c + 2, 'x');
    s[r+1] = string(c + 2, 'x');
    for (int i = 1; i <= r; ++i) {
        cin >> s[i];
        s[i] = "x" + s[i] + "x";
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= r; ++j) {
            for (int l = 1; l <= c; ++l) {
                if (s[j][l] == 'o' && (s[j+1][l] == 'x' || s[j-1][l] == 'x' || s[j][l-1] == 'x' || s[j][l+1] == 'x')) {
                    s[j][l] = '*';
                }
            }
        }
        for (int j = 1; j <= r; ++j) {
            for (int l = 1; l <= c; ++l) {
                if (s[j][l] == '*') {
                    s[j][l] = 'x';
                }
            }
        }
    }
    ll result = 0;
    for (int j = 1; j <= r; ++j) {
        for (int l = 1; l <= c; ++l) {
            if (s[j][l] == 'o') result++;
        }
    }
    cout << result << endl;
}