#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    bool readable = true;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && 'A' <= s[i] && s[i] <= 'Z') {
            readable = false;
            break;
        }
        if (i % 2 == 1 && 'a' <= s[i] && s[i] <= 'z') {
            readable = false;
            break;
        }
    }
    if (readable) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;

    }
}
