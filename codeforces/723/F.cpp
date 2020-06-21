//https://codeforces.com/contest/723/problem/F
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
using namespace std;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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


const int maxn = 2e5 + 5;

class UnionFind
{
public:
    int p[maxn] = { 0 }; int rank[maxn] = { 0 }; int _n;
    UnionFind(int __n)
    {
        this->_n = __n;
        for(int i = 1; i <= this->_n; ++i)
        {
            p[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool unify(int x, int y)
    {
        x = find(x); y = find(y); if (x == y) return false;
        if (rank[x] < rank[y])
        {
            x += y; y = x - y; x -= y;
        }
        if (rank[x] == rank[y]) rank[x]++;
        p[y] = x;
        this->_n--;
        return true;
    }
};

si g[maxn];
pi state[maxn] = { {0, 0} };
int n, m;
vpi out;
vpi inedges;
int main()
{
    GOGOGO
    cin >> n >> m;
    UnionFind uf(n);
    int sr, dst;
    rep(i, m)
    {
        cin >> sr >> dst;
        inedges.pb({sr, dst});
        g[sr].insert(dst);
        g[dst].insert(sr);

    }
    int s, t, ds, dt; cin >> s >> t >> ds >> dt;
    bool fs = false; bool ft = false;
    for(auto e : inedges)
    {
        if (e.fi != s && e.se != s && e.fi != t && e.se != t)
        {
            if (uf.unify(e.fi, e.se))
            {
                out.pb(e);
            }
        }
    }
    assert(uf._n != 1);
    for(auto e: g[s])
    {
        if (e == t) continue;
        int papa = uf.find(e);
        if (!state[papa].fi)
        {
            state[papa].fi = e;
            fs = true;
        }
    }
    for(auto e: g[t])
    {
        if (e == s) continue;
        int papa = uf.find(e);
        if (!state[papa].se)
        {
            state[papa].se = e;
            ft = true;
        }
    }
    int cs = 0; int ct = 0;
    bool yay = false;
    repk(i, 1, n+1)
    {
        if (state[i].fi && !state[i].se)
        {
            cs++;
            out.pb({s, state[i].fi });
        }
        else if (!state[i].fi && state[i].se)
        {
            ct++;
            out.pb({t, state[i].se });
        }
        else if (state[i].fi && state[i].se)
        {
            yay = true;
        }
        
    }
    if (cs > ds || ct > dt)
    {
        cout << "No" << endl;
        BYEBYE
    }
    if (!yay)
    {
        assert(g[s].find(t) != g[s].end());
        cs++;
        ct++;
        out.pb({s, t});
    }
    else
    {
        /*
        cerr << "DEBUG" << endl;
        for(auto e : out)
        {
            cout << e.fi << " " << e.se << endl;
        }
        cerr << "EDEBUG" << endl;*/
        // there exists a component such that s & t can be connected to it
        bool need = true;
        repk(i, 1, n+1)
        {
            if (state[i].fi && state[i].se)
            {
                if (need)
                {
                    out.pb({s, state[i].fi});
                    out.pb({t, state[i].se});
                    ++cs;
                    ++ct;
                    need = false;
                }
                else
                {
                    if (cs < ds)
                    {
                        out.pb({s, state[i].fi});
                        ++cs;
                    }
                    else
                    {
                        out.pb({t, state[i].se});
                        ++ct;

                    }
                    
                }
                
            }
        }
    }
    if (cs > ds || ct > dt || out.size() != n - 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for(auto e : out)
        {
            cout << e.fi << " " << e.se << endl;
        }
    }
    
    


    BYEBYE
}
