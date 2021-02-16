#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int better_count(const vector<int>& s, int k) {
    return distance(lower_bound(s.begin(), s.end(), k), upper_bound(s.begin(), s.end(), k));
}

int main() {
    int n;
    cin >> n;
    vector<int> r;
    vector<int> s;
    vector<int> p;
    vector<pair<int, int>> attendees;
    for (int i = 0; i < n; ++i) {
        int rate, hand;
        cin >> rate >> hand;
        if (hand == 1) {
            r.push_back(rate);
        } else if (hand == 2) {
            s.push_back(rate);
        } else if (hand == 3) {
            p.push_back(rate);
        }
        attendees.emplace_back(rate, hand);
    }
    sort(r.begin(), r.end());
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
        auto attendee = attendees[i];
        int rate = attendee.first;
        int hand = attendee.second;
        int draw = 0, lose = 0;
        lose += distance(upper_bound(r.begin(), r.end(), rate), r.end());
        lose += distance(upper_bound(s.begin(), s.end(), rate), s.end());
        lose += distance(upper_bound(p.begin(), p.end(), rate), p.end());
        if (hand == 1) {
            lose += better_count(p, rate);
            draw += better_count(r, rate) - 1;
        } else if (hand == 2) {
            lose += better_count(r, rate);
            draw += better_count(s, rate) - 1;
        } else if (hand == 3) {
            lose += better_count(s, rate);
            draw += better_count(p, rate) - 1;
        }
        printf("%d %d %d\n", n - lose - draw - 1, lose, draw);
    }
}
