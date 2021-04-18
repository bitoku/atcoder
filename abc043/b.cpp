#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            t.push_back('0');
        } else if (s[i] == '1') {
            t.push_back('1');
        } else {
            if (!t.empty()) {
                t.pop_back();
            }
        }
    }
    cout << t << endl;
}
