#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    for (int i = 2; i <= n - 4; ++i) {
        for (int j = 1; i + 2 * j <= n - 2; ++j) {
            if (s.substr(i, j) == s.substr(i + j, j)) {
                for (int k = 1; k <= i - 1 && i + j * 2 + k <= n - 1; ++k) {
                    if (s.substr(i - k, k) == s.substr(n - k, k)) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}