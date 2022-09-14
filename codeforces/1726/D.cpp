
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


/*** begin #define flags ***/
#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/

const int maxn = 2e5 + 5;

int n,m ;


vector<pair<int, int>> g[maxn];

pair<int, int> edges[maxn];
bitset<maxn> is_edge_used = 0;


int parent_edge_index[maxn];
int d[maxn];
bitset<maxn> vis = 0;

void dfs(int c, int p = -1, int p_edge_index = -1, int current_depth=0) {

    vis[c] = 1;

    parent_edge_index[c] = p_edge_index;

    d[c] = current_depth;
    for(const auto& e : g[c]) {
        if(!vis[e.first] && e.first != p) {
            is_edge_used[e.second] = 1;
            dfs(e.first, c, e.second, current_depth + 1);
        }
    }
}

void clear_testcase() {
    for(int i = 0; i < m; i++) {
        is_edge_used[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        g[i] = vector<pair<int, int>>();

        vis[i] = 0;
    }
}


void solve(int t) {



    cin >> n >> m;

    rep(i, m) {
        int u, v; cin >> u >> v;
        g[u].eb(v, i); g[v].eb(u, i);

        edges[i] = {u, v};
    }

    dfs(1);


        

    set<int> nodes_from_bad_edges;

    int arbitrary_unused_edge = -1;
    rep(i, m) {
        if(!is_edge_used[i]) {
            nodes_from_bad_edges.insert(edges[i].first);
            nodes_from_bad_edges.insert(edges[i].second);
            arbitrary_unused_edge = i;
        }
    }

    if(nodes_from_bad_edges.size() == 3) {
        int u = edges[arbitrary_unused_edge].first;
        int v = edges[arbitrary_unused_edge].second;

        if(d[u] < d[v]) {
            swap(u, v);
        }

        // u's depth is bigger
        is_edge_used[arbitrary_unused_edge] = true; 
        is_edge_used[parent_edge_index[u]] = false;

    }
        

    rep(i, m) {
        cout << is_edge_used[i];
    }

    cout << '\n';



    clear_testcase();
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

    //init();
    int count = 1;
    while(t--)
    {
        // cout << "Case #" << count << ":";
        solve(count);
        count += 1;
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/

/****************************** end /main.cpp ******************************/





