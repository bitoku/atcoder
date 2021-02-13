#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Node {
    int first;
    int second;
};

Node dfs(vector<vector<int>> &children, vector<int> &parents, int current) {
    if (children[current].empty()) {
        return {1, 0};
    }
    deque<Node> childnodes_odd;
    vector<Node> childnodes_even;

    for (const auto child : children[current]) {
        Node n = dfs(children, parents, child);
        if ((n.first + n.second) % 2 == 1) {
            childnodes_odd.push_back(n);
        } else {
            childnodes_even.push_back(n);
        }
    }
    sort(childnodes_odd.begin(), childnodes_odd.end(), [](const Node& n1, const Node& n2){
        return n1.first - n1.second < n2.first - n2.second;
    });
    sort(childnodes_even.begin(), childnodes_even.end(), [](const Node& n1, const Node& n2) {
        return n1.first - n1.second < n2.first - n2.second;
    });
    Node node = {0, 0};
    int i;
    for (i = 0; i < childnodes_even.size(); ++i) {
        Node n = childnodes_even[i];
        if (n.first - n.second > 0) break;
        node.first += n.first;
        node.second += n.second;
    }
    int j;
    for (j = 0; j < childnodes_odd.size(); ++j) {
        Node n = childnodes_odd[j];
        if (j % 2 == 0) {
            node.first += n.first;
            node.second += n.second;
        } else {
            node.first += n.second;
            node.second += n.first;
        }
    }
    for (; i < childnodes_even.size(); ++i) {
        Node n = childnodes_even[i];
        if (j % 2 == 0) {
            node.first += n.first;
            node.second += n.second;
        } else {
            node.first += n.second;
            node.second += n.first;
        }
    }
    node.first++;
    return node;
}

int main() {
    int n;
    cin >> n;
    vector<int> parents(n);
    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) {
        cin >> parents[i];
        parents[i]--;
        children[parents[i]].push_back(i);
    }
    Node node = dfs(children, parents, 0);
    cout << node.first << endl;
}
