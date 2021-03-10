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

#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
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


template<typename T> using func = function<T>;
template<typename T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}





//#define BRUH_WHY_TESTCASES
//#define PREC 6
//#define USACO "sleepy"

const int maxn = 5e5 + 5;

struct persistent_dsu_t {
    int dt; int p[maxn]; int sz[maxn]; int time[maxn]; int n;
    void init(int _n) {
        n = _n;
        dt = 0;
        for (int i = 1; i <= n; ++i) {

            p[i] = i; sz[i] = 1; time[i] = INFI;
        }

    }
    int find(int x, int t) {
        while (time[x] <= t) x = p[x];
        return x;
    }
    bool unify(int x, int y)
    {
        ++dt;
        x = find(x, dt); y = find(y, dt);  if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        time[y] = dt;
        return true;
    }
};

struct edge {
    int s; int t; int w;
} edges[maxn];
int id[maxn];
int wtime[maxn];
vi g[maxn];
vpi g2[maxn];
int qw[maxn]; int qwc = 0;
int n; int m; persistent_dsu_t pers;
bitset<maxn> vis = 0;


bool dfs(int c, int p, int eid) {
    vis[c] = 1;
    bool res = false;
    for (auto e : g2[c]) {
        if (res) return res;
        if (e.fi == c) return true;
        if (e.fi == p) {
            if (e.se != eid) return true;
        }
        else if (vis[e.fi]) return true;
        else {
            res = dfs(e.fi, c, e.se);
        }
    }
    return res;
}

void query() {
    int k; cin >> k;
    rep(i, k) {
        int cid; cin >> cid;
        if (g[edges[cid].w].empty()) {
            qw[qwc++] = edges[cid].w;
        }
        g[edges[cid].w].pb(cid);
    }
    bool res = true;
    rep(i, qwc) {
        if (res == false) break;
        int cw = qw[i]; int ct = wtime[cw];
        vector<int> nodes;
        int bruh = 1;
        for (auto e : g[cw]) {
            int ps = pers.find(edges[e].s, ct); int pt = pers.find(edges[e].t, ct);
            g2[pt].emplace_back(ps, bruh);
            g2[ps].emplace_back(pt, bruh);
            bruh++;
            nodes.pb(pt); nodes.pb(ps);
        }

        for (auto node : nodes) {
            if (!res) break;
            if (!vis[node]) {
                res &= !dfs(node, 0, 0);
            }
        }
        for (auto node : nodes) {
            vis[node] = false; g2[node].clear();
        }
   


    }
    for (int j = 0; j < qwc; ++j) {
        g[qw[j]].clear();
    }
    qwc = 0;
    cout << (res ? "YES" : "NO") << '\n';
}

void solve() {
    n; cin >> n; pers.init(n);
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].s >> edges[i].t >> edges[i].w;
        id[i] = i;
    }
    sort(id + 1, id + 1 + m, [&](int x, int y) {
        return edges[x].w < edges[y].w;
        });
    int last = 0;
    for (int i = 1; i <= m; ++i) {
        if (last != edges[id[i]].w) {
            wtime[edges[id[i]].w] = i - 1;
            last = edges[id[i]].w;
        }
        pers.unify(edges[id[i]].s, edges[id[i]].t);
    }
    int q; cin >> q; rep(_, q) {
        query();
    }

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
    int t = 1;
#ifdef BRUH_WHY_TESTCASES
    cin >> t;
#endif
    while (t--)
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
