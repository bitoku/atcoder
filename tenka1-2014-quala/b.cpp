#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll kaburin = 5;
    ll combo = 0;
    int cool = 0;
    ll result = 0;
    priority_queue<ll, vector<ll>, greater<>> kab;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> dmg;
    ll t = 0;
    for (auto cmd: s) {
        t++;
        while (!kab.empty() && kab.top() <= t) {
            kaburin++; kab.pop();
//            cout << "come back" << ' ' << kaburin << endl;
        }
        while (!dmg.empty() && dmg.top().first <= t) {
            ll x = dmg.top().second; dmg.pop();
//            cout << "damage" << ' ' << x << endl;
            result += x;
            combo++;
        }
        if (cool > 0) {
            cool--;
            continue;
        }

        if (cmd == '-') {
            continue;
        }
        if (cmd == 'N') {
//            cout << t << ' ' << kaburin << endl;
            if (kaburin < 1) continue;
//            cout << t << ' ' << "throw" << endl;
            kaburin--;
            dmg.push(make_pair(t + 2, 10 + combo / 10));
            kab.push(t + 7);
        }
        if (cmd == 'C') {
//            cout << t << ' ' << kaburin << endl;
            if (kaburin < 3) continue;
//            cout << t << ' ' << "tame throw" << endl;
            kaburin -= 3;
            cool = 2;
            dmg.push(make_pair(t + 4, 50 + combo / 10 * 5));
            kab.push(t + 9);
            kab.push(t + 9);
            kab.push(t + 9);
        }
    }
    while (!dmg.empty()) {
        ll x = dmg.top().second; dmg.pop();
        result += x;
    }
    cout << result << endl;
}