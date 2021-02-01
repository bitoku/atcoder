#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = 0;
    for (int i = 0; i < 1 << (s.size() - 1); ++i) {
        bitset<9> bit(i);
        int left = 0;
        for (int j = 0; j < s.size() - 1; ++j) {
            if (bit[j]) {
                result += stoll(s.substr(left, j - left +1));
                left = j+1;
            }
        }
        result += stoll(s.substr(left, s.size() - left));
    }
    cout << result << endl;
}
