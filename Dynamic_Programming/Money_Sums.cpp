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
    int n; cin >> n;
    vi a(n); f(a);
    int sum = accumulate(a.begin(), a.end(), 0);
    vi dp(sum + 1, false);
    dp[0] = true;
    vi ans;
    rep(i, 0, n) {
        int coin = a[i];
        for (int j = sum; j >= coin; j--) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }
    rep(i, 1, sum + 1) if (dp[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for (auto& x:ans) cout << x << " ";
    cout << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}