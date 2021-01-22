#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string bigsmall;
    cin >> bigsmall;
    vector<int> bigger_than_before(bigsmall.size()+1);
    vector<int> bigger_than_after(bigsmall.size()+1);
    for (int i = 0; i < bigsmall.size(); ++i) {
        if (bigsmall[i] == '<') {
            bigger_than_before[i+1] = bigger_than_before[i] + 1;
        } else {
            bigger_than_before[i+1] = 0;
        }
    }
    for (int i = (int)bigsmall.size()-1; i >= 0; --i) {
        if (bigsmall[i] == '>') {
            bigger_than_after[i] = bigger_than_after[i+1] + 1;
        } else {
            bigger_than_after[i] = 0;
        }
    }
    ll result = 0;
    for (int i = 0; i < bigsmall.size() + 1; ++i) {
        result += max(bigger_than_before[i], bigger_than_after[i]);
    }
    cout << result << endl;
}
