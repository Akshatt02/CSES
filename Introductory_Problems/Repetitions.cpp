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


void solve(int testcase){
    string s; cin >> s;
    long long curr = 1, ans = 1;
    char ch = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (ch == s[i]) curr++;
        else {
            ch = s[i];
            ans = max(ans, curr);
            curr = 1;
        }
        dbg(ans);
    }
    cout << max(ans, curr) << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}