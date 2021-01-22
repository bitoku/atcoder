//
// Created by 徳備彩人 on 2020/03/08.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    int q;
    set<int> pos[26];

    cin >> n;
    cin >> s;
    cin >> q;

    for (int i = 0;i < s.size(); i++) {
        pos[s[i]-'a'].insert(i+1);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int j;
            char c;
            cin >> j >> c;
            for (auto & po : pos) {
                if (po.find(j) != po.end()) {
                    po.erase(j);
                }
            }
            pos[c-'a'].insert(j);
        } else {
            int l, r;
            cin >> l >> r;
            int x = 0;
            for (auto & po : pos) {
                auto it = po.find(l);
                if (it != po.end()) {
                    x += 1;
                } else {
                    it = po.upper_bound(l);
                    if (it != po.end() && *it <= r) {
                        x += 1;
                    }
                }
            }
            cout << x << endl;
        }
    }
}