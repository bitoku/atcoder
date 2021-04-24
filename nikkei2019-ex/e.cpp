#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        if (i % 2 == 0) s.push_back('a');
        if (i % 3 == 0) s.push_back('b');
        if (i % 4 == 0) s.push_back('c');
        if (i % 5 == 0) s.push_back('d');
        if (i % 6 == 0) s.push_back('e');
        if (s.empty()) cout << i << endl;
        else cout << s << endl;
    }
}
