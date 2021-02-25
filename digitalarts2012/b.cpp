#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll hash = 0;
    for (char & c : s) {
        hash += c - 'a' + 1;
    }
    string ss;
    while (hash > 0) {
        if (hash >= 26) {
            ss.push_back('z');
            hash -= 26;
        } else {
            ss.push_back(hash - 1 + 'a');
            hash = 0;
        }
    }
    if (ss != s) {
        cout << ss << endl;
        return 0;
    }
    if (ss.size() == 20) {
        if (ss[ss.size()-1] == 'z') {
            cout << "NO" << endl;
            return 0;
        }
        ss[ss.size()-2]--;
        ss[ss.size()-1]++;
    } else if (ss.size() == 1) {
        if (ss[0] == 'a') {
            cout << "NO" << endl;
            return 0;
        }
        ss[0]--;
        ss.push_back('a');
    } else if (ss[ss.size()-1] != 'a') {
        ss[ss.size()-1]--;
        ss.push_back('a');
    } else {
        ss[ss.size()-2]--;
        ss.push_back('a');
    }
    cout << ss << endl;
}
