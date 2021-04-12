#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    set<char> ss;
    for (int i = 0; i < 26; ++i) {
        ss.insert(i + 'a');
    }
    for (int i = 0; i < s.size(); ++i) {
        ss.erase(s[i]);
    }
    if (!ss.empty()) {
        cout << s + *ss.begin() << endl;
        return 0;
    }
    string orig = s;
    ss.insert(s.back());
    s.pop_back();
    while (!s.empty()) {
        char temp = s.back();
        s.pop_back();
        for (auto c : ss) {
            if (orig < s + c) {
                cout << s + c << endl;
                return 0;
            }
        }
        ss.insert(temp);
    }
    cout << -1 << endl;
}
