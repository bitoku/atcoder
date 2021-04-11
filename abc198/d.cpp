#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    set<char> s;
    for (char & i : s1) {
        s.insert(i);
    }
    for (char & i : s2) {
        s.insert(i);
    }
    for (char & i : s3) {
        s.insert(i);
    }
    if (s.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    unordered_map<char, int> m;
    for (auto x : s) {
        m[x] = -1;
    }
    vector<int> perm(10);
    iota(perm.begin(), perm.end(), 0);

    do {
        int idx = 0;
        for (auto x : s) {
            m[x] = perm[idx];
            idx++;
        }
        if ((m[s1.back()] + m[s2.back()]) % 10 != m[s3.back()]) continue;
        ll n1 = 0;
        if (m[s1.front()] == 0) continue;
        for (auto c : s1) {
            n1 *= 10;
            n1 += m[c];
        }
        ll n2 = 0;
        if (m[s2.front()] == 0) continue;
        for (auto c : s2) {
            n2 *= 10;
            n2 += m[c];
        }
        ll n3 = 0;
        if (m[s3.front()] == 0) continue;
        for (auto c : s3) {
            n3 *= 10;
            n3 += m[c];
        }
        if (n1 + n2 == n3) {
            cout << n1 << endl;
            cout << n2 << endl;
            cout << n3 << endl;
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << "UNSOLVABLE" << endl;
}