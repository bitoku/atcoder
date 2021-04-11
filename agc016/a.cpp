#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < 26; ++i) {
        string tt = s;
        ll cnt = 0;
        while (!all_of(tt.begin(), tt.end(), [i](char c) {return c == 'a' + i;}) && tt.size() > 1) {
            string t;
            for (int j = 0; j < tt.size() - 1; ++j) {
                if (tt[j] == 'a' + i || tt[j+1] == 'a' + i) {
                    t.push_back('a' + i);
                } else {
                    t.push_back(tt[j]);
                }
            }
            tt = t;
            cnt++;
        }
        result = min(result, cnt);
    }
    cout << result << endl;
}
