#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll cnt = 0;
    char before = 'x';
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == before) continue;
        cnt++;
        before = s[i];
    }
    cout << cnt - 1 << endl;
}
