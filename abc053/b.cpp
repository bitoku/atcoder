#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll a;
    ll z;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            a = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'Z') {
            z = i;
            break;
        }
    }
    cout << z - a + 1 << endl;
}