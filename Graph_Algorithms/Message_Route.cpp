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


void solve(int testcase) {
    int n, m; cin >> n >> m;
    vector<vi> g(n + 1);
    vector<bool> vis(n + 1, false);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi dist(n + 1, 1e9);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;
    vi parent(n + 1, -1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neigh:g[node]) {
            if (!vis[neigh]) {
                vis[neigh] = true;
                dist[neigh] = dist[node] + 1;
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }
    vi path;
    int curr = n;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    if (dist[n] == 1e9) cout << "IMPOSSIBLE\n";
    else {
        cout << path.size() << "\n";
        for(auto x:path) cout << x << " ";
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}