#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = 0;
    for (int i = 0; i < s.size(); ++i) {
        ll x;
        if (s[i] == 'U') x = s.size() - i - 1;
        else x = i;
        result += x;
        result += 2 * (s.size() - 1 - x);
    }
    cout << result << endl;
}