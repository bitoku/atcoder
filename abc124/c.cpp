#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll cnt1 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] == '0') cnt1++;
        if (i % 2 != 0 && s[i] == '1') cnt1++;
    }
    ll cnt2 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] == '1') cnt2++;
        if (i % 2 != 0 && s[i] == '0') cnt2++;
    }
    cout << min(cnt1, cnt2) << endl;
}
