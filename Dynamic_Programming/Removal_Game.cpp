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
    ll n; cin >> n;
    vll a(n); f(a);
    vector<vll> dp(n, vll (n, -1));
    function<ll(ll, ll)> help = [&] (ll i, ll j) -> ll {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = max(a[i] - help(i + 1, j), a[j] - help(i, j - 1));
        return dp[i][j];
    };
    help(0, n - 1);
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    cout << (tot + dp[0][n - 1]) / 2 << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}