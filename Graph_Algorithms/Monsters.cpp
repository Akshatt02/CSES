#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using ii = pair<int, int>;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define f(a) for (auto& x:a) cin >> x;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(x...) 42
#endif

// Global Variable Declaration
vector<ii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(int testcase) {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    f(g);
    queue<ii> q;
    ii pos;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<vi> distM(n, vi (m, INT_MAX));
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (g[i][j] == 'A') pos = {i, j};
            if (g[i][j] == 'M') {
                q.push({i, j});
                distM[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        ii node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = node.first + dir[i].first;
            int y = node.second + dir[i].second;
            if (x >= 0 and x < n and y >= 0 and y < m) {
                if (!vis[x][y] and g[x][y] != '#') {
                    vis[x][y] = true;
                    distM[x][y] = distM[node.first][node.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    vector<vi> distP(n, vi (m, INT_MAX));
    vis.assign(n, vector<bool> (m, false));
    vector<vector<ii>> par(n, vector<ii> (m, {-1, -1}));
    q.push(pos);
    distP[pos.first][pos.second] = 0;
    vis[pos.first][pos.second] = true;
    while (!q.empty()) {
        ii node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = node.first + dir[i].first;
            int y = node.second + dir[i].second;
            if (x >= 0 and x < n and y >= 0 and y < m) {
                if (!vis[x][y] and g[x][y] != '#' and distP[node.first][node.second] + 1 < distM[x][y]) {
                    vis[x][y] = true;
                    distP[x][y] = distP[node.first][node.second] + 1;
                    par[x][y] = node;
                    q.push({x, y});
                }
            }
        }
    }
    ii end;
    bool f = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                if (distP[i][j] != INT_MAX) {
                    f = 1;
                    end = {i, j};
                } 
            }
        }
    }
    if (!f) cout << "NO\n";
    else {
        cout << "YES\n";
        string path = "";
        ii cur = end;
        while (cur != pos) {
            ii p = par[cur.first][cur.second];
            if (cur.first == p.first + 1) path += 'D';
            else if (cur.first == p.first - 1) path += 'U';
            else if (cur.second == p.second + 1) path += 'R';
            else if (cur.second == p.second - 1) path += 'L';
            cur = p;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}