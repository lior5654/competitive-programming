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

// LIORZ LIORZ LIORZ LIORZ LIORZ











































int n; const int maxn = 1e5 + 5; const int maxh = 17;
int q; const int maxq = 1e5 + 5;
vi g[maxn];
int p[maxh][maxn] = { { 0 } }; int sz[maxn] = { 0 }; int d[maxn] = { 0 };
//vi centd[maxn];
int pc[maxn] = { 0 };
bitset<maxn> vis = 0;
int bestv[maxn]; // inside subtree

void dfs(int c, int par=0, int dd=0)
{
    p[0][c] = par;
    d[c] = dd;
    //sz[c] = 1;
    for(auto e : g[c])
    {
        if(e!=par)
        {
            dfs(e, c, dd+1);
            //sz[c] += sz[e];
        }
    }
}
void init_lca()
{
    for(int h = 1; h < maxh; ++h)
    {
        for(int i = 1; i <= n; ++i)
        {
            p[h][i] = p[h-1][p[h-1][i]];
        }
    }
}
int lift(int b, int k)
{
    if(k <= 0) return b;
    int h = 0;
    while(k)
    {
        if(k%2)
        {
            b = p[h][b];
        }
        k/=2;
        ++h;
    }
    return b;
}
int lca(int a, int b)
{
    if(a==b) return a;
    if(d[a] > d[b]) swap(a, b);
    b = lift(b, d[b] - d[a]);
    if(a==b) return a;
    for(int h = maxh - 1; h >= 0; --h)
    {
        if(p[h][a] != p[h][b])
        {
            b = p[h][b]; a = p[h][a];
        }
    }
    assert(p[0][a] == p[0][b]);
    return p[0][a];
}
int dist(int a, int b)
{
    return d[a] + d[b] - 2*d[lca(a, b)];
}
int find_size(int c, int par = 0)
{
    if(vis[c]) return 0;
    sz[c] = 1;
    for(auto e : g[c])
    {
        if(e != par)
        {
            sz[c] += find_size(e, c);
        }
    }
    return sz[c];
}
int find_centroid(int c, int ssz, int par = 0)
{
    for(auto e : g[c])
    {
        if(e != par && !vis[e] && sz[e] > ssz / 2)
        {
            return find_centroid(e, ssz, c);
        }
    }
    return c;
}
void cent_decompose(int c, int par = 0)
{
    find_size(c);
    int cent = find_centroid(c, sz[c]);
    //cout << cent << " " << par << endl;
    pc[cent] = par;
    vis[cent] = 1;
    for(auto e : g[cent])
    {
        if(!vis[e])
        {
            cent_decompose(e, cent);
        }
    }
}






void init()
{
    dfs(1);
    init_lca();
    cent_decompose(1);
    for(int i = 1; i <= n; ++i)
    {
        bestv[i] = INFI;
    }

}

void update(int c)
{
    int u = c;
    while(u)
    {
        bestv[u] = min(bestv[u], dist(c, u));
        u = pc[u];
    }
}
int query(int c)
{
    int res = INFI;
    int u = c;
    while(u)
    {
        res = min(res, bestv[u] + dist(u, c));
        u = pc[u];

    }
    return res;
}
void solve()
{
    cin >> n >> q;
    rep(i, n - 1)
    {
        int s, t; cin >> s>> t;
        g[s].pb(t); g[t].pb(s);
    }
    init();
    update(1);
    for(int i = 0; i < q; ++i)
    {
        int t, v; cin >> t >> v;
        if(t == 1)
        {
            update(v);
        }
        else
        {
            cout << query(v) << endl;
        }
        
    }
}






































signed main()
{
    GOGOGO
    cout << fixed << setprecision(9);
    int t=1;
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