#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    deque<char> t;
    bool back = true;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            back = !back;
            continue;
        }
        if (back) {
            t.push_back(s[i]);
        } else {
            t.push_front(s[i]);
        }
    }
    string tt;
    if (back) {
        for (int i = 0; i < t.size(); ++i) {
            if (tt.back() == t[i]) {
                tt.pop_back();
                continue;
            }
            tt.push_back(t[i]);
        }
    } else {
        for (int i = t.size()-1; i >= 0; --i) {
            if (tt.back() == t[i]) {
                tt.pop_back();
                continue;
            }
            tt.push_back(t[i]);
        }
    }
    cout << tt << endl;
}