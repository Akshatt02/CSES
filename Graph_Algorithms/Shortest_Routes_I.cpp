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
    vector<vector<pair<int, ll>>> g(n + 1);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        g[u].push_back({v, w});
    }
    vll dist(n + 1, 1e15);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pair<ll, int> node = pq.top();
        pq.pop();
        ll d = node.first;
        int u = node.second;
        if (d >= dist[u]) continue;
        dist[u] = d;
        for (auto& neigh:g[u]) {
            if (dist[u] + neigh.second < dist[neigh.first]) {
                pq.push({dist[u] + neigh.second, neigh.first});
            }
        }
    }
    rep(i, 1, n + 1) cout << dist[i] << " ";
    cout << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}