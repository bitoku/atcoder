#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int color[8] = {0};
    int overcolor = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (1 <= a[i] && a[i] <= 399) color[0]++;
        else if (400 <= a[i] && a[i] <= 799) color[1]++;
        else if (800 <= a[i] && a[i] <= 1199) color[2]++;
        else if (1200 <= a[i] && a[i] <= 1599) color[3]++;
        else if (1600 <= a[i] && a[i] <= 1999) color[4]++;
        else if (2000 <= a[i] && a[i] <= 2399) color[5]++;
        else if (2400 <= a[i] && a[i] <= 2799) color[6]++;
        else if (2800 <= a[i] && a[i] <= 3199) color[7]++;
        else overcolor++;
    }
    int minc = 0;
    int before_color = -1;
    for (int i : color) {
        if (i > 0) {
            minc++;
        }
    }
    if (minc == 0) {
        printf("%d %d\n", 1, overcolor);
    } else {
        printf("%d %d\n", minc, minc + overcolor);
    }
}
