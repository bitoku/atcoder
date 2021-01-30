#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = 0;
    ll acnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            acnt++;
        } else if (s[i] == 'B' && (i+1 < s.size() && s[i+1] == 'C')) {
            result += acnt;
            i++;
        } else {
            acnt = 0;
        }
    }
    cout << result << endl;
}
