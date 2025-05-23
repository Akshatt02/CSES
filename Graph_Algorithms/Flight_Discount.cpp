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

// A generic djikstra implementation using class
class Djikstra {
    // Accepts pre-defined graph
    // Returns the shortest path from source node(s) to all other nodes

    public:

    // Graph
    vector<vector<pair<int, long long>>> adj;
    int n; // Number of nodes

    // Constructor
    Djikstra(vector<vector<pair<int, long long>>> adj) {
        this->adj = adj;
        this->n = adj.size();
    }

    // Djikstra with vector of sources    
    vector<long long> solve(vector<int> sources) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int source : sources) {
            pq.push({0, source});
        }
        while (!pq.empty()) {
            pair<long long, int> top = pq.top();
            pq.pop();
            long long d = top.first;
            int u = top.second;
            if (d >= dist[u]) continue;
            dist[u] = d;
            for (pair<int, long long> &v : adj[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    pq.push({dist[u] + v.second, v.first});
                }
            }
        }
        return dist;
    }
};

// Global Variable Declaration


void solve(int testcase) {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> edges;
    vector<vector<pair<int, ll>>> g(n + 1);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        g[u].push_back({v, w});
        edges.push_back({u, v, w});
    }
    Djikstra dj(g);
    vll distS = dj.solve({1});
    vector<vector<pair<int, ll>>> gr(n + 1);
    for (auto& [u, v, w] : edges) {
        gr[v].push_back({u, w});
    }
    Djikstra djRev(gr);
    vll distD = djRev.solve({n});
    ll ans = LLONG_MAX;
    for (auto& [u, v, w] : edges) {
        if (distS[u] == LLONG_MAX or distD[v] == LLONG_MAX) continue;
        ans = min(ans, distS[u] + w / 2 + distD[v]);
    }
    cout << ans << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}