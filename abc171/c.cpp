#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string s;
    while ( n > 0 ) {
        s = (char) ('a' + (n - 1) % 26) + s;
        n -= (n - 1) % 26;
        n /= 26;
    }
    cout << s << endl;
}