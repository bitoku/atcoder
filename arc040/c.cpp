#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        int c = -1;
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                c = j;
            }
        }
        if (c >= 0) {
            cnt++;
            if (i == n-1) continue;
            for (int j = c; j < n; ++j) {
                s[i+1][j] = 'o';
            }
        }
    }
    cout << cnt << endl;
}
