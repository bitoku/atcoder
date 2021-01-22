#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string keyence = "keyence";
    bool success = true;
    success = true;
    int k_idx = 0;
    for (int i = 0; i < keyence.size(); ++i) {
        k_idx = i;
        if (s[i] != keyence[i]) {
            success = false;
            break;
        }
    }
    if (success) {
        cout << "YES" << endl;
        return 0;
    }
    success = true;
    for (int i = k_idx; i < keyence.size(); ++i) {
        if (s[s.size() - keyence.size() + i] != keyence[i]) {
            success = false;
            break;
        }
    }
    if (success) cout << "YES" << endl;
    else cout << "NO" << endl;
}
