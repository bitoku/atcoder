#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = 0;
    int alphabet[26] = {0};
    alphabet[s.back()-'a']++;
    for (int i = (int)s.size()-2; i >= 1; --i) {
        int alpha = s[i] - 'a';
        if (s[i+1] != s[i] && s[i] == s[i-1]) {
            result += s.size() - i - 1 - alphabet[alpha];
            for (int & a : alphabet) {
                a = 0;
            }
            alphabet[alpha] = (int)s.size() - i - 1;
        }
        alphabet[alpha]++;
    }
    cout << result << endl;
}
