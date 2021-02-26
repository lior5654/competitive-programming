/*
                            . .  ,  ,
                            |` \/ \/ \,',
                            ;          ` \/\,.
                           :               ` \,/
                           |                  /
                           ;                 :
                          :                  ;
                          |      ,---.      /
                         :     ,'     `,-._ \
                         ;    (   o    \   `'
                       _:      .      ,'  o ;
                      /,.`      `.__,'`-.__,
                      \_  _               \
                     ,'  / `,          `.,'
               ___,'`-._ \_/     `,._        ;
            __;_,'      `-.`-'./ `--.____)
         ,-'           _,--\^-'
       ,:_____      ,-'     \
      (,'     `--.  \;-._    ;
      :    Y      `-/    `,  :
      :    :       :     /_;'
      :    :       |    :
       \    \      :    :
        `-._ `-.__, \    `.
           \   \  `. \     `.
         ,-;    \---)_\ ,','/
         \_ `---'--'" ,'^-;'
         (_`     ---'" ,-')
         / `--.__,. ,-'    \
-hrr-    )-.__,-- ||___,--' `-.
        /._______,|__________,'\
        `--.____,'|_________,-'
 
                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'
 
*/
 
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
 
 
typedef long double ld;
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
const ll INFL = 1e17 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}




















// #define BRUH_WHY_TESTCASES
// #define PREC 6
//#define USACO "sleepy"

const int maxn = 1e5 + 5;
const ll maxa = 2e5 + 5;
const int root = 1;
struct Line {
    ll m, b;
    Line() : m(0), b(INFL) {}
    Line(ll _m, ll _b) : m(_m), b(_b) {}
    ll operator() (ll x) const { return m*x + b; }
};

struct lichao {
    ll tl; ll tr; ll tm; Line val; lichao* l; lichao* r;
    lichao(ll _tl, ll _tr) {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2LL; l=r=nullptr;
    }
    void add(Line u) {
        if(u(tm) < val(tm)) swap(u, val);
        if(u(tl) < val(tl)) {
            if(l==nullptr) l = new lichao(tl, tm);
            l->add(u);
        } 
        if(u(tr) < val(tr)) {
            if(r==nullptr) r = new lichao(tm+1, tr);
            r->add(u);
        }
    }
    ll query(ll x) {
        assert(abs(x) < maxa);
        ll res = val(x);
        if(x <= tm) {
            if(l!=nullptr) res = min(res, l->query(x));
        } else {
            if(r!=nullptr) res = min(res, r->query(x));
        }
        return res;
    }
};

struct ds {
    vector<Line> added;
    lichao* manager;
    ll a; ll b;
} mine[maxn];

ll dp[maxn]; int n;
vi g[maxn];

void dfs(int c, int p=0) {
    mine[c].manager = new lichao(-maxa, maxa);
    bool is_leaf = true;
    for(auto e : g[c]) {
        if(e!=p) {
            is_leaf=false;
            dfs(e,c);
            if(mine[e].added.size() > mine[c].added.size()) {
                swap(mine[c].added, mine[e].added);
                swap(mine[c].manager, mine[e].manager);
            }
            for(const auto line : mine[e].added) {
                mine[c].manager->add(line);
                mine[c].added.pb(line);
            }
        }
    }
    if(is_leaf) {
        dp[c] = 0;
    } else {
        dp[c] = mine[c].manager->query(mine[c].a);
    }
    Line my_line = Line(mine[c].b, dp[c]);
    mine[c].added.pb(my_line);
    mine[c].manager->add(my_line);
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> mine[i].a;
    } for(int i = 1; i <= n; ++i) {
        cin >> mine[i].b;
    }
    rep(i, n-1) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
}

 
 



























































 
signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
    #endif
    GOGOGO
    #ifdef PREC
      cout << fixed << setprecision(PREC);
    #endif
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
            cin >> t;
    #endif
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
