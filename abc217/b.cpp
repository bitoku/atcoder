#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    vector<string> v = {"ABC", "ARC", "AGC", "AHC"};
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        v.erase(find(v.begin(), v.end(), s));
    }
    cout << v[0] << endl;
}