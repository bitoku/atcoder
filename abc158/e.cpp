#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> amari(vector<int> m, int a, int p) {
    vector<int> mm(p);
    for (int i=0; i<mm.size(); i++) {
        mm[i] = 0;
    }
    for (int i=0; i<m.size(); i++) {
        if (m[i] == 0) {
            continue;
        }
        mm[(i * 10 + a) % p] += m[i];
    }
    mm[a%p] += 1;
    return mm;
}

int main(){
    int n, p;
    string s;
    cin >> n >> p;
    vector<int> m(p);
    vector<int> dp;
    dp.push_back(0);
    for (int i=0; i<m.size(); i++) {
        m[i] = 0;
    }
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        m = amari(m, s[i]-'0', p);
        dp.push_back(dp[i] + m[0]);
    }
    cout << dp.back() << endl;
}
