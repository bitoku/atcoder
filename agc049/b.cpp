#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll cnt = 0;
    deque<int> diff;
    if (s[0] != t[0]) {
        diff.push_back(0);
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1' && !diff.empty()) {
            s[i] = '0';
            cnt += i - diff.front();
            diff.pop_front();
        }
        if (s[i] != t[i]) {
            diff.push_back(i);
        }
    }
    if (diff.empty()) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}
