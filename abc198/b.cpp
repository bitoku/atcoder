#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    while (s.back() == '0') {
        s.pop_back();
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[s.size() - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
