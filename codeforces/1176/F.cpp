#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
using namespace std;


typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm

const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ
















#define int int64_t

const ll maxn = 2e5 + 5;
const ll smod = 10;
const ll maxc = 3;
const ll maxa = 4;
ll dp[smod][maxn] = { { 0 } };
ll best[maxa][maxn] = { { 0 } };
ll sbest[maxa][maxn] = { { 0 } };
ll dmg[maxc][maxn];
ll sz[maxc] = { 0 };



void solve()
{
    ll n; cin >> n;
    rep(i, n)
    {
        ll k; cin >> k;
        rep(j, maxc) 
        {
            sz[j] = 0;
        }
        rep(j, maxa)
        {
            best[j][i] = -1;
            sbest[j][i] = -1;
        }
        rep(j, k)
        {
            ll c, d; cin >> c >> d;
            dmg[c-1][sz[c-1]++] = d;
        }
        rep(j, maxc) sort(dmg[j], dmg[j] + sz[j], [](int a, int b){return a > b;});
        if(sz[0] > 2) 
        {
            best[3][i] = dmg[0][0] + dmg[0][1] + dmg[0][2];
            sbest[3][i] = dmg[0][0] + dmg[0][1] + dmg[0][2] + max({dmg[0][0], dmg[0][1], dmg[0][2]});
        }
        if(sz[0] && sz[1]) 
        {
            best[2][i] = max(best[2][i], dmg[0][0] + dmg[1][0]);
            sbest[2][i] = max(sbest[2][i], dmg[0][0] + dmg[1][0] + max(dmg[0][0], dmg[1][0]));
        }
        if(sz[0] > 1) 
        {
            best[2][i] = max(best[2][i], dmg[0][0] + dmg[0][1]);
            sbest[2][i] = max(sbest[2][i], dmg[0][0] + dmg[0][1] + max(dmg[0][0], dmg[0][1]));
        }
        rep(j, maxc)
        {
            if(sz[j]) 
            {
                best[1][i] = max(best[1][i], dmg[j][0]);
                sbest[1][i] = max(sbest[1][i], 2*dmg[j][0]);
            }
        }
        best[0][i] = 0;
        sbest[0][i] = 0;
    }
    rep(i, maxa)
    {
        dp[i][0] = best[i][0];
    }
    for(int i = maxa; i < smod; ++i)
    {
        dp[i][0] = -1;
    }
    for(int i = 1; i < n; ++i)
    {
        for(int m = 0; m < smod; ++m)
        {
            dp[m][i] = -1;
            for(int dl = 0; dl < maxa; ++dl)
            {
                if(best[dl][i] != -1 && dp[(m-dl+smod)%smod][i-1] != -1)
                {
                    if(m-dl<0)
                    {
                        dp[m][i] = max(dp[m][i], sbest[dl][i] + dp[(m-dl+smod)%smod][i-1]);
                    }
                    else
                    {
                        dp[m][i] = max(dp[m][i], best[dl][i] + dp[(m-dl+smod)%smod][i-1]);
                    }
                }
            }
        }
    }
    ll res = 0;
    rep(i, smod)
    {
        res = max(res, dp[i][n-1]);
    }
    cout << res << endl;
}





































signed main()
{
    GOGOGO
    int t;
    t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/