#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll k = 0;
    if (s[0] == '2') k++;
    vector<ll> cnt;
    for (int i = 1; i < s.size(); ++i) {
        if (k > 0 && ((k % 2 == 1 && s[i] == '5') || (k % 2 == 0 && s[i] == '2'))) {
            k++;
        } else {
            cnt.push_back(k);
            if (s[i] == '2') k = 1;
            else k = 0;
        }
    }
    cnt.push_back(k);
    ll result = 0;
    for (int i = 0; i < cnt.size(); ++i) {
        result += cnt[i] / 2 * (1 + cnt[i] / 2) / 2;
    }
    cout << result << endl;
}