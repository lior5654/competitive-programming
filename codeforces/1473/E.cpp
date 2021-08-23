/****************************** begin /template.h ******************************/

/***********************************************************************
 * [?] APIO 2021 Template
 * [+] Made By: Lior Yehezkely, FiveSixFiveFour
 * [~] Apples are ORZ
 * *********************************************************************/

/*** begin #define flags ***/
// #define USE_ORDERED_STATISTICS
// #define BIG_BIGINT
/*** end #define flags ***/

/*** begin includes ***/
#include <bits/stdc++.h>

#ifdef USE_ORDERED_STATISTICS
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
#endif

using namespace std;
/*** end includes ***/

/*** begin typedefs ***/
typedef long long int ll;
#ifdef BIG_BIGINT
    typedef __int128_t bigint;
#else
    typedef ll bigint;
#endif
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
template<class T> using func = function<T>;

#ifdef USE_ORDERED_STATISTICS
    typedef tree<
    pl,
    null_type,
    less<pl>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#endif

/*** end typedefs ***/

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
auto dist = uniform_int_distribution<int>(0, INFI); 
auto distll = uniform_int_distribution<ll>(0, INFL); 
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

/****************************** end /template.h ******************************/


/****************************** begin /main.cpp ******************************/


/*** begin #define flags ***/
//#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/

const int maxn = 2e5 + 5;
const int maxv = 4 * maxn;

struct edge {
    int u; int v; ll w;
};
vector<edge> edges;
vector<pair<int, ll>> g[maxv]; int n, m;
ll d[maxv];

void solve() {
    cin >> n >> m;
    rep(i, m) {
        edge e; cin >> e.u >> e.v >> e.w; --e.u; --e.v; edges.pb(e);
    }
    rep(k, 4) {
        for(const auto e : edges) {
            g[k*n + e.u].eb(k*n + e.v, e.w);
            g[k*n + e.v].eb(k*n + e.u, e.w);
        }
    }
    for(const auto e : edges) {
        g[e.u].eb(n + e.v, 0);
        g[e.v].eb(n + e.u, 0);   
    }
    for(const auto e : edges) {
        g[e.u].eb(2*n + e.v, 2LL*e.w);
        g[e.v].eb(2*n + e.u, 2LL*e.w);
    }
    for(const auto e : edges) {
        g[n+e.u].eb(3*n + e.v, 2LL*e.w);
        g[n+e.v].eb(3*n + e.u, 2LL*e.w);
    }
    for(const auto e : edges) {
        g[2*n+e.u].eb(3*n + e.v, 0);
        g[2*n+e.v].eb(3*n + e.u, 0);
    }
    for(const auto e : edges) {
        g[e.u].eb(3*n + e.v, e.w);
        g[e.v].eb(3*n + e.u, e.w);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    rep(i, 4*n) {
        d[i] = INFL;
    }
    d[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        int c = pq.top().se; ll ow = pq.top().fi; pq.pop();
        if(ow > d[c]) {
            continue;
        }
        for(auto e : g[c]) {
            if(d[c] + e.se < d[e.fi]) {
                d[e.fi] = d[c] + e.se;
                pq.push({d[e.fi], e.fi});
            }
        }
    }
    for(int i = 3*n + 1; i < 4*n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';

}











































signed main()
{
    #ifdef INPUT_FILE
        freopen(INPUT_FILE, "r", stdin);
    #endif
    #ifdef OUTPUT_FILE
        freopen(OUTPUT_FILE, "w", stdout);
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

/****************************** end /main.cpp ******************************/





