
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










































int n; const int maxn = 1e5 + 5;
int cent = 0;
vi g[maxn];
int pa[maxn];
int sz[maxn];
int rlabel[maxn];
int label[maxn];
int ___dt = 0;

void init_sz(int c, int p=-1)
{
    pa[c] = p;
    sz[c] = 1;
    for(auto e : g[c])
    {
        if(e!=p)
        {
            init_sz(e, c);
            sz[c] += sz[e];
        }
    }
}
int find_centroid(int c, int p=-1)
{
    for(auto e : g[c])
    {
        if(e!=p && sz[e]>n/2)
        {
            return find_centroid(e, c);
        }
    }
    return c;
}
void set_label(int c, int p=-1)
{
    label[c] = ___dt++;
    rlabel[label[c]] = c;
    for(auto e : g[c])
    {
        if(e!=p)
        {
            set_label(e, c);
        }
    }
}
void solve()
{
    cin >> n;
    rep(i, n-1)
    {
        int s, t; cin >> s >> t; g[s].pb(t); g[t].pb(s);
    }
    init_sz(1);
    cent = find_centroid(1);
    set_label(cent);
    ll o = 0;
    for(int i = 2; i <= n; ++i)
    {
        o += 2 * min(sz[i], n - sz[i]);
    }
    cout << o << endl;
    for(int i = 1; i <= n; ++i)
    {
        cout << rlabel[(label[i] + (n/2))%n] << " ";
    }
    cout << endl;

}






































int main()
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