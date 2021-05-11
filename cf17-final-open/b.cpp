#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') a++;
        if (s[i] == 'b') b++;
        if (s[i] == 'c') c++;
    }
    if (max({abs(a - b), abs(b - c), abs(c - a)}) > 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}