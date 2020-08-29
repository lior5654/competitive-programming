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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*
 
 
 
 
 
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
}*/
/*
const int maxn = 1e5 + 5;
 
class Segtree
{
public:
    int tl, tm, tr; ll val; Segtree* l; Segtree* r;
 
    Segtree(int _tl, int _tr)
    {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2;
        l=r=0; val=0;
    }
    void pull()
    {
        if(!l||!r) return;
        val=l->val + r->val;
    }
    void build(int a[])
    {
        if(tl==tr)
        {
            val = a[tl];
        }
        else
        {
            l=new Segtree(tl, tm); r=new Segtree(tm+1, tr);
            l->build(a); r->build(a); pull();
        }
    }
    void update(int xr, int pos)
    {
        if(tl==tr)
        {
            val ^= xr;
        }
        else
        {
            if(pos<=tm)
            {
                l->update(xr, pos);
            } else {
                r->update(xr, pos) ;
            } pull();
        }
        
    }
};*/
 
const ll maxn = 1e6 + 1;
ll ax = 0;
ll n, k;
ll b[maxn];
class Trie
{
public:
    const int lastBit = 31;
    vector<array<int, 2>> trie; int lastNodeId = 0;
    vector<array<int, 2>> edgeCount; // edgeCount[b][j] - how many edges I have to the bit b as the next bit in the number from my current node
    Trie()
    {
        trie.resize(1, array<int, 2>{0, 0});
        edgeCount.resize(1, array<int, 2>{0, 0});
    }
    void add(int a)
    {
        int curr = 0;
        for(int i = lastBit; i >= 0; --i)
        {
            int currBit = (a&(1<<i))>>i;
            edgeCount[curr][currBit]++;
            if(trie[curr][currBit])
            {
                curr = trie[curr][currBit];
            }
            else
            {
                if(i!=0)
                {
                    trie.pb(array<int, 2>{0, 0});
                    edgeCount.pb(array<int, 2>{0, 0});
                    trie[curr][currBit] = ++lastNodeId ; curr = trie[curr][currBit];
                }
            }
        }
    }
    ll query(int xr) // note that k is strictly bigger than 0
    {
        int curr = 0;
        int res = 0;
        for(int i = lastBit; i >= 0; --i)
        {
            int currKBit = (k&(1<<i))>>i;
            int currXorBit = (xr&(1<<i))>>i;
            if(!currKBit)
            {
                res += edgeCount[curr][(int)(!currXorBit)];
            }
            if(trie[curr][currKBit ^ currXorBit])
            {
                curr = trie[curr][currKBit ^ currXorBit];
            }
            else
            {
                break;
            }
            
        }
        return res;

    }

};
void solve()
{
    cin >> n >> k; k--; 
    rep(i, n) {cin >> b[i];} Trie t;
    //cout << "hi" << endl;
    int last = 0;
    int curr = 0;
    ll res= 0;
    for(int i = 0; i < n; ++i)
    {
        last = curr; t.add(last); 
        curr ^= b[i];
        res += t.query(curr);
        //cout << res << endl;
    }
    cout << res << endl;
}

/*
ll dp[3][3][701][701];
ll mtc[701];
const int mod = 1e9 + 7;
bool s[701];
void solve()
{
    string _s; cin >> _s;
    int n = _s.size();
    rep(i, n)
    {
        char c; c = _s[i];//cin >> c;
        s[i+1] = c == '(';
    }
    stack<int> o;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i])
        {
            /*dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
            dp[1][i] = dp[0][i-1] + dp[2][i-1];
            dp[2][i] = dp[0][i-1] + dp[1][i-1];
            for(int who = 0; who < 3; ++who)
            {
                dp[who][i] %= mod;
            }
            o.push(i);
            for(int ini = 0; ini < 3; ++ini)
            {
                dp[ini][i][i][ini] = 1;
                for(int neh = 0; neh < 3; ++neh)
                {
                    if(neh!=ini)
                    {
                        dp[ini][i][i][neh] = 0;
                    }
                }
                for(int j = i - 1; j >= 1; --j)
                {
                    for(int ed = 0; ed < 3; ++ed)
                    {
                        dp[ini][i][j][ed] = 0;
                        for(int neh = 0; neh < 3; ++neh)
                        {
                            if(neh == ini && ini) continue;
                            
                            dp[ini][i][j][ed] += dp[neh][i-1][j][ed];
                        }

                    }
                }
            }
            o.push(i);
        }
        else
        {
            int match = o.top(); o.pop();
            for(int ini = 0; ini < 3; ++ini)
            {
                dp[ini][i][i][ini] = 1;
                for(int neh = 0; neh < 3; ++neh)
                {
                    if(neh!=ini)
                    {
                        dp[ini][i][i][neh] = 0;
                    }
                }
                for(int j = i - 1; j >= 1; --j)
                {
                    if(j > match)
                    {
                        for(int ed = 0; ed < 3; ++ed)
                        {
                            dp[ini][i][j][ed] = 0;
                            for(int neh = 0; neh < 3; ++neh)
                            {
                                if(neh == ini && ini) continue;
                                
                                dp[ini][i][j][ed] += dp[neh][i-1][j][ed];
                            }
                        }

                    }
                    else if(j == match)
                    {
                        for(int ed = 0; ed < 3; ++ed)
                        {
                            dp[ini][i][j][ed] = 0;
                            if(ini && ed || !ini && !ed) continue;
                            for(int neh = 0; neh < 3; ++neh)
                            {

                                if(neh == ini && ini) continue;
                                
                                dp[ini][i][j][ed] += dp[neh][i-1][j][ed];
                            }
                        }
                    }
                    else
                    {
                        for(int ed = 0; ed < 3; ++ed)
                        {
                            dp[ini][i][j][ed] = 0;

                            for(int neh = 0; neh < 3; ++neh)
                            {

                                if(neh == ed && ed) continue;
                                
                                dp[ini][i][j][ed] += dp[neh][i-1][j][ed];
                            }
                        }
                    }
                    
                }
            }

        }
    }
    
}
*/
 /*
const int maxn = 2e5 + 5;
ll a[maxn];
void solve()
{
    
   int n; cin >> n;
   rep(i, n) cin >> a[i];
   sort(a, a +n);
   reverse(a, a+n);
   array<ll, 2> cnt = { 0, 0};
   array<vl, 2> chs;
   for(auto e : a)
   {
       if(abs(cnt[0] + e - cnt[1]) < abs(cnt[0] - e - cnt[1]))
       {
           cnt[0] += e;
           chs[0].pb(e);
       } else {
           cnt[1] += e;
           chs[1].pb(e);
       }
   }
   if(cnt[0] > cnt[1])
   {
       swap(cnt[0], cnt[1]);
       swap(chs[0], chs[1]);
   }
   // 0 smallest
   
   ll res = 0;
   array<int, 2> sz = {chs[0].size(), chs[1].size()};
   ll t = 0;
   for(int i = 0; i < sz[1]; ++i)
   {
       
   }
   //cout << cnt[1] + cnt[0] + cnt[1] - cnt[0]

 
}
*/
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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