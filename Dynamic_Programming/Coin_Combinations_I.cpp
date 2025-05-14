#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
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
const int MOD = 1e9 + 7;
vi dp;

int help(int amount, int n, vi& a) {
    if (amount < 0) return 0;
    if (amount == 0) return 1;
    if (dp[amount] != -1) return dp[amount];
    dp[amount] = 0;
    rep(i, 0, n) {
        dp[amount] = (dp[amount] + help(amount - a[i], n, a)) % MOD;
    }
    return dp[amount];
}

void solve(int testcase) {
    int n, amount; cin >> n >> amount;
    vi a(n); f(a);
    dp.assign(amount + 1, -1);
    help(amount, n, a);
    cout << dp[amount] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}