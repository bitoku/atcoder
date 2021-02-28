#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll k;
    cin >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll cards[10];
    for (long long & card : cards) {
        card = k;
    }
    ll scards[10] = {0};
    for (int i = 0; i < s.size() - 1; ++i) {
        int x = s[i] - '0';
        scards[x]++;
        cards[x]--;
    }
    ll tcards[10] = {0};
    for (int i = 0; i < s.size() - 1; ++i) {
        int x = t[i] - '0';
        tcards[x]++;
        cards[x]--;
    }
    ll sum = 0;
    ll win = 0;
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            if ((i == j && cards[i] < 2) || cards[i] < 1 || cards[j] < 1) continue;
            ll pat;
            if (i == j) {
                pat = cards[i] * (cards[i] - 1);
            } else {
                pat = cards[i] * cards[j];
            }
            sum += pat;
            ll sscore = 0;
            scards[i]++;
            for (int l = 0; l < 10; ++l) {
                sscore += l * (ll)pow(10, scards[l]);
            }
            scards[i]--;
            ll tscore = 0;
            tcards[j]++;
            for (int l = 0; l < 10; ++l) {
                tscore += l * (ll)pow(10, tcards[l]);
            }
            tcards[j]--;
            if (sscore > tscore) {
                win += pat;
            }
        }
    }
    cout << setprecision(12) << (double)win / sum << endl;
}
