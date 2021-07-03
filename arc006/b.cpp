#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, l;
    cin >> n >> l;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    for (int i = 0; i <= l; ++i) {
        string line;
        getline(cin, line);
        for (int j = 1; j < line.size(); j += 2) {
            if (line[j] != '-') continue;
            int k = j / 2;
            swap(v[k], v[k+1]);
        }
    }
    string goal;
    getline(cin, goal);
    int g = 0;
    for (int i = 0; i < goal.size(); i += 2) {
        if (goal[i] == 'o') g = i / 2;
    }
    cout << v[g] << endl;
}