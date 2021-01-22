#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lowest_number(int n) {
    return n % 10;
}
int highest_number(int n) {
    int temp = n;
    while (temp >= 10) temp /= 10;
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<set<int>> m(100);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int lowest = lowest_number(i);
        int highest = highest_number(i);
        ll temp = 0;
        if (lowest != 0) {
            temp += m[lowest*10 + highest].size();
            m[highest*10 + lowest].insert(i);
            temp += m[lowest*10 + highest].size();
        }
//        cout << lowest << ' ' << highest << ' ' << temp << endl;
        ans += temp;
    }
    cout << ans << endl;
}
