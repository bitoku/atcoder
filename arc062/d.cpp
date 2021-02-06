#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int p = 0;
    for (char i : s) {
        if (i == 'p') p++;
    }
    cout << s.size() / 2 - p << endl;
}
