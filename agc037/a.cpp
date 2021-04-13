#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string before = s.substr(0, 1);
    ll cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (before == s.substr(i, 1)) {
            if (i == s.size() - 1) {
                break;
            }
            before = s.substr(i, 2);
            i++;
        } else {
            before = s.substr(i, 1);
        }
        cnt++;
    }
    cnt++;
    cout << cnt << endl;
}
