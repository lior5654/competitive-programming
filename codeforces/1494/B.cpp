#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
typedef vector<vpl> vvpl;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
#define eb emplace_back
#define all(c) (c.begin()) (c.end())
#define fi first
#define se second





























// APPLES ARE TASTY YUM YUM YUM YUM

void solve() {
    ll n, u, r, d, l; cin >> n >> u >> r >> d >> l;
    for(int lmask = 0; lmask < 4; ++lmask) {
        for(int rmask = 0; rmask < 4; ++rmask) {
            int lcount = __builtin_popcount(lmask);
            int rcount = __builtin_popcount(rmask);
            int ucount = (lmask&1) + (rmask&1);
            int dcount = lmask/2 + rmask/2;
            if(ucount > u || n-2 + ucount < u) continue;
            if(dcount > d || n-2 + dcount < d) continue;
            if(lcount > l || n-2 + lcount < l) continue;
            if(rcount > r || n-2 + rcount < r) continue;
            cout << "YES" << '\n'; return;
            
        }
    }
    cout << "NO" << '\n'; return;
    
}








































signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    rep(i, t) {
        solve();
    }
    return 0;
}