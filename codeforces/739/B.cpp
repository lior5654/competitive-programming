//https://codeforces.com/contest/1388/problem/C
 
// solved in alt submitting in main
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
pl,
null_type,
less<pl>,
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
 
// LIORZ LIORZ LIORZ LIORZ LIORZ
 
const int maxn = 2e5 + 5;
const int maxh = 22;
ll a[maxn] = { 0 };
 
int p[maxn] = { 0 };
ll distanceToRoot[maxn] = { 0 };
ll w[maxn] = { 0 };  // w[i] - weight of edge to parent
int startTime[maxn] = { 0 };
int endTime[maxn] = { 0 };
ll cache[maxn] = { 0 };
ll values[maxn] = { 0 };
ll answer[maxn] = { 0 };
int dt = 0;
int n;
vi g[maxn];
int __t = 0;
int pp[maxh][maxn] = { { 0 } };
 
 
void dfs1(int c, int par=-1)
{
    distanceToRoot[c] = w[c] + distanceToRoot[p[c]];
    pp[0][c] = p[c];
    startTime[c] = ++dt;
    values[c] = distanceToRoot[c] - a[c];
    for(auto e : g[c])
    {
        if (e!=par)
            dfs1(e, c);
    }
    
    endTime[c] = dt;
}
void init()
{
    for(int h = 1; h < maxh; ++h)
    {
        for(int i = 1; i <= n; ++i)
        {
            pp[h][i] = pp[h-1][pp[h-1][i]];
        }
    }
}
void dfs2(int c)
{
    answer[c] = cache[c];
    for(auto e : g[c])
    {
        dfs2(e);
        answer[c] += answer[e];
    }
}
void solve()
{
   cin >> n;
   rep(i, n)
   {
       cin >> a[i+1];
   }
   rep(i, n-1)
   {
       cin >> p[i+2] >> w[i+2];
       g[p[i+2]].pb(i+2);
   }
   dfs1(1);
   init();
    for(int c = 2; c <= n; ++c)
    {
        ll value = distanceToRoot[c] - a[c];
        cache[p[c]] += 1;
        if(distanceToRoot[p[c]] < value)
        {
            cache[p[c]] -= 1;
        }
        else
        {
            int f = p[c];
            for(int h = maxh-1; h >= 0; --h)
            {
                if(pp[h][f] && distanceToRoot[pp[h][f]] >= value)
                {
                    f = pp[h][f];
                }
            }
            cache[p[f]] -= 1;
        }
        
    }
    dfs2(1);
    
   for(int i = 1; i <= n; ++i)
   {
       cout << answer[i] << " ";
   }
   cout << endl;
 
}
int main()
{
    GOGOGO
    int t;
    t=1;
    // cin >> t;
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