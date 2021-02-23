#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<bool> honest(n+1);
    string s;
    cin >> s;
    bool pattern[4][2] = {
            {true, true},
            {true, false},
            {false, true},
            {false, false}
    };
    for (auto & pat : pattern) {
        honest[0] = pat[0];
        honest[1] = pat[1];
        for (int i = 1; i < n; ++i) {
            if ((honest[i] && s[i] == 'o') || (!honest[i] && s[i] == 'x')) {
                honest[i+1] = honest[i-1];
            } else {
                honest[i+1] = !honest[i-1];
            }
        }
        if (honest[0] == honest[n]) {
            if (
                    (honest[0] && ((s[0] == 'o') == (honest[n - 1] == honest[1]))) ||
                    (!honest[0] && ((s[0] == 'o') == (honest[n - 1] != honest[1])))
                    ) {
                for (int i = 0; i < n; ++i) {
                    if (honest[i]) cout << 'S';
                    else cout << 'W';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
