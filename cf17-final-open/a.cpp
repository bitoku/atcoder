#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t = "AKIHABARA";
    int idx = 0;
    for (char c : t) {
        if (c == s[idx]) {
            idx++;
        } else if (c == 'A') {
            continue;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (idx == s.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
