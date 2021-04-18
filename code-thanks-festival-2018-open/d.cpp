#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        char head = s[i];
        ++i;
        for (;s[i] > head; ++i) {}
        --i;
        cnt++;
    }
    cout << cnt << endl;
}
