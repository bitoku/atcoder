#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t;
    for (const auto c : s) {
        if (!t.empty() && t.back() != c) {
            t.pop_back();
        } else {
            t.push_back(c);
        }
    }
    cout << s.size() - t.size() << endl;
}
