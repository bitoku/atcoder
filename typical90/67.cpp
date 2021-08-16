#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ll n = 0;
        for (int j = 0; j < s.size(); ++j) {
            n *= 8;
            n += s[j] - '0';
        }
        string t;
        if (n == 0) {
            t = "0";
        } else while (n > 0) {
            t.push_back('0' + n % 9);
            n /= 9;
        }
        for (char & c : t) {
            if (c == '8') c = '5';
        }
        reverse(t.begin(), t.end());
        s = t;
    }
    cout << s << endl;
}