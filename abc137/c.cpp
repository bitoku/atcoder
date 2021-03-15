#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    ll cnt = 1;
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == s[i]) cnt++;
        else {
            result += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    result += cnt * (cnt - 1) / 2;
    cout << result << endl;
}
