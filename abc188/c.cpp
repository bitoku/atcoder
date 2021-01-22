#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct athlete {
    int id;
    int strength;
};

int main() {
    vector<athlete> athletes;
    int n;
    cin >> n;
    int num_ath = (1 << n);
    athlete first_champ = {-1, 0};
    athlete second_champ = {-1, 0};
    for (int i = 0; i < num_ath / 2; ++i) {
        int a;
        cin >> a;
        if (a > first_champ.strength) {
            first_champ = athlete{i, a};
        }
    }
    for (int i = num_ath / 2; i < num_ath; ++i) {
        int a;
        cin >> a;
        if (a > second_champ.strength) {
            second_champ = athlete{i, a};
        }
    }
    if (first_champ.strength > second_champ.strength) {
        cout << second_champ.id + 1 << endl;
    } else {
        cout << first_champ.id + 1 << endl;
    }
}
