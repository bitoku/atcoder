#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    ll n;
    getline(cin, s);
    cin >> n;
    vector<string> filters(n);
    for (int i = 0; i < n; ++i) {
        cin >> filters[i];
    }
    string result;
    for (int i = 0; i < s.size(); ++i) {
        string t;
        while (i < s.size() && s[i] != ' ') {
            t.push_back(s[i]);
            ++i;
        }
        bool filtered = false;
        for (int j = 0; j < n; ++j) {
            bool match = true;
            match &= filters[j].size() == t.size();
            for (int k = 0; k < t.size(); ++k) {
                match &= filters[j][k] == '*' || filters[j][k] == t[k];
            }
            if (match) {
                filtered = true;
                break;
            }
        }
        if (filtered) {
            result += string(t.size(), '*');
        } else {
            result += t;
        }
        result.push_back(' ');
    }
    result.pop_back();
    cout << result << endl;
}