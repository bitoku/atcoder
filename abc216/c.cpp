#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    while (n > 0) {
        if (n % 2 == 0) {
            s.push_back('B');
            n /= 2;
        }
        else {
            s.push_back('A');
            n -= 1;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}