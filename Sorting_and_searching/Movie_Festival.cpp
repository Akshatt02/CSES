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


bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

void solve(int testcase) {
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [u, v]:a) cin >> u >> v;
    sort(a.begin(), a.end(), comp);
    ll time = 0;
    ll ans = 0;
    rep(i, 0, n) {
        if (a[i].first >= time) {
            time = a[i].second;
            ans++;
        }
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