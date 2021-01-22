#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> original(n);
    vector<string> tpl(m);
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> tpl[i];
    }
    bool is_included = true;
    for (int i = 0; i < n - m + 1; ++i) {
        for (int j = 0; j < n - m + 1; ++j) {
            is_included = true;
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (original[i + k][j + l] != tpl[k][l]) {
                        is_included = false;
                        break;
                    }
                }
                if (!is_included) break;
            }
            if (is_included) break;
        }
        if (is_included) break;
    }
    if (is_included) cout << "Yes" << endl;
    else cout << "No" << endl;
}

