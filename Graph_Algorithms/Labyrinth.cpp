#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using ii = pair<int, int>;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else  
#define dbg(x...) 42
#endif

// Global Variable Declaration
int n, m;
vector<string> a;
vector<vector<bool>> vis;
vector<vector<ii>> parent;

string directions = "LRUD";
vector<ii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool lim(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (auto& x:a) cin >> x;
    vis.resize(n, vector<bool>(m, 0));
    parent.resize(n, vector<ii>(m, {-1, -1}));
    ii start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                start = {i, j};
            }
            if (a[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    queue<ii> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    while (!q.empty()) {
        ii node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = node.first + dir[i].first;
            int y = node.second + dir[i].second;
            if (lim(x, y) && !vis[x][y] && a[x][y] != '#') {
                vis[x][y] = 1;
                parent[x][y] = node;
                q.push({x, y});
                if (x == end.first && y == end.second) {
                    vector<char> path;
                    ii curr = end;
                    while (curr != start) {
                        ii prev = parent[curr.first][curr.second];
                        int dx = curr.first - prev.first;
                        int dy = curr.second - prev.second;
                        if (dx == 0 && dy == -1) path.push_back('L');
                        if (dx == 0 && dy == 1) path.push_back('R');
                        if (dx == -1 && dy == 0) path.push_back('U');
                        if (dx == 1 && dy == 0) path.push_back('D');
                        curr = prev;
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n";
                    cout << path.size() << "\n";
                    for (char move : path) {
                        cout << move;
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    //int _t; cin >> _t; while(_t--)
    solve();
}