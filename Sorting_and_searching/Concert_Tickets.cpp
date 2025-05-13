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
 
 
void solve(int testcase) {
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    rep(i, 0, n) {
        int x; cin >> x;
        st.insert(x);
    }
    rep(i, 0, m) {
        int price; cin >> price;
        auto it = st.upper_bound(price);
        if (it == st.begin()) cout << -1 << "\n";
        else {
            it--;
            cout << *it << "\n";
            st.erase(it);
        }    
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}