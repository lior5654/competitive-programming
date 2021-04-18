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
template<class T> void aread(T* arr, int _n)
{
    rep(i, _n)
    {
        cin >> arr[i];
    }
}
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

/*
n nodes m edges

Theorem: the complement graph has atmost O(sqrt(m)) components, where there is a node connected to n - O(sqrt(m)) things.

Lemma:
in a graph, the minimal degree is <= O(sqrt(m)). proof:

let the minimal degree be d.
d * n <= sum of degrees = 2*m

d <= 2*m/n

m <= n(n-1)/2
-> n >= O(sqrt(n)) -> d <= O(sqrt(m))

this means that in the complement graph there is a node connected to n - O(sqrt(m)) nodes, which limits the number of components to O(sqrt(m))

so after we find that node and merge everything we can run an O(sqrt(m)^2) algorithm and we win.
*/

const int maxn = 1e5 + 5;

vpi edges;
vi og[maxn];
vector<vector<int>> g;
int deg[maxn]; int n, m;
int conv[maxn];
int gcnt = 0;
bitset<maxn> vis = 0;


void dfs(int c) {
    vis[c] = true;
    for(int i = 1; i <= gcnt; ++i) {
        if(g[c][i] && !vis[i]) {
            dfs(i);
        }
    }
}
void solve() {
    cin >> n >> m;
    rep(i, m) {
        int s, t; cin >> s >> t;
        edges.emplace_back(s, t); deg[t]++; deg[s]++;
        og[t].pb(s); og[s].pb(t);
    }
    int best = 1;
    for(int i = 2; i <= n; ++i) {
        if(deg[i] < deg[best]) best = i;
    }
    for(int i = 1; i <= n; ++i) {
        conv[i] = 0;
    }
    conv[best] = 0;
    gcnt = 1;
    for(auto e : og[best]) {
        conv[e] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(!conv[i]) {
            conv[i] = 1;
        } else {
            conv[i] = ++gcnt;
        }
    }
    g.resize(gcnt+1, vector<int>(gcnt+1, 1));
    for(int i = 1; i <= gcnt; ++i) {
        g[conv[best]][i] = n - (gcnt-1);
        g[i][conv[best]] = n - (gcnt-1);
    }
    for(const auto& e : edges) {
        g[conv[e.fi]][conv[e.se]]--;
        g[conv[e.se]][conv[e.fi]]--;
    }
    int res = 0;
    for(int i = 1; i <= gcnt; ++i) {
        if(!vis[i]) {
            res++;
            dfs(i);
        }
    }
    cout << res - 1 << '\n';
    // best - vertex with minimal degree

}


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
    #endif
    //GOGOGO
 
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