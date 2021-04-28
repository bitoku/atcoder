#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<ll> x(26);
    for (int i = 0; i < s.size(); ++i) {
        if (x[s[i] - 'a']) {
            cout << "no" << endl;
            return 0;
        }
        x[s[i] - 'a']++;
    }
    cout << "yes" << endl;
}