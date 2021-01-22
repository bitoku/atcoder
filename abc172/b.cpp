#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) cnt++;
    }
    cout << cnt << endl;
}
