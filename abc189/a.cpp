#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }
}
