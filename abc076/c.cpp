#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int pos = -1;
    for (int i = s.size() - 1; i >= 0; --i) {
        bool fit = true;
        for (int j = 0; j < t.size() ; ++j) {
            int last_idx = (int)t.size() - 1;
            if(s[i - j] != '?' && t[last_idx - j] != s[i - j]) {
                fit = false;
                break;
            }
        }
        if (fit) {
            pos = i - (int)t.size() + 1;
            break;
        }
    }
    if (pos == -1) {
        cout << "UNRESTORABLE" << endl;
    } else {
        for (int i = 0; i < s.size(); ++i) {
            if (pos <= i && i < pos + t.size()) {
                cout << t[i-pos];
            } else if (s[i] == '?') {
                cout << 'a';
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
}
