#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t;
    for (int i = 0; i < n; ++i) {
        t.push_back(s[i]);
        if (t.size() >= 3 && t[t.size() - 3] == 'f' && t[t.size() - 2] == 'o' && t[t.size() - 1] == 'x') {
            t.pop_back();
            t.pop_back();
            t.pop_back();
        }
    }
    cout << t.size() << endl;
}
