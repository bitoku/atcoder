#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    char a = s[0];
    char b = s[1];
    if (a == b) {
        printf("%d %d\n", 1, 2);
        return 0;
    }
    for (int i = 2; i < s.size(); ++i) {
        char c = s[i];
        if (a == c) {
            printf("%d %d\n", i-1, i+1);
            return 0;
        }
        if (b == c) {
            printf("%d %d\n", i, i+1);
            return 0;
        }
        a = b;
        b = c;
    }
    cout << "-1 -1" << endl;
}
