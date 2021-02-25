#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string a;
    cin >> a;
    vector<ll> v(a.size());
    v[0] = 1;
    int alpha[26] = {0};
    alpha[a[0]-'a']++;
    for (int i = 1; i < a.size(); ++i) {
        v[i] = v[i - 1] + i - alpha[a[i] - 'a'];
        alpha[a[i] - 'a']++;
    }
    cout << v[a.size()-1] << endl;
}
