#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t;
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == '0') t.push_back('0');
        if (s[i] == '1') t.push_back('1');
        if (s[i] == '6') t.push_back('9');
        if (s[i] == '8') t.push_back('8');
        if (s[i] == '9') t.push_back('6');
    }
    cout << t << endl;
}