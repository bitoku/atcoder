#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                cout << "Takahashi" << endl;
            } else {
                cout << "Aoki" << endl;
            }
            return 0;
        }
    }
}