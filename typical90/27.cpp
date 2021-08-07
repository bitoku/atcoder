#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    unordered_set<string> user;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (user.find(s) == user.end()) {
            user.insert(s);
            cout << i + 1 << endl;
        }
    }
}