
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

#define what(x) cout << #x << " = " << x << '\n'
/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
auto dist = uniform_int_distribution<int>(0, INFI); 
auto distll = uniform_int_distribution<ll>(0, INFL); 
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

/****************************** end /template.h ******************************/



//#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define USACO "sleepy"


// orz orz orz orz orz orzo rzo


const int maxn = 2e5 +5;

template<class Number, int world_size> struct FenwickTree {
    Number fen[world_size+1];
    FenwickTree() {
        for(int i = 1; i <= world_size; ++i) fen[i] = 0;
    }
    void add(int pos, const Number& val) {
        for(int i = pos; i <= world_size; i += i & (-i)) {
            fen[i] += val;
        }
    }
    Number pquery(int l) {
        Number res = 0;
        for(int i = l; i > 0; i -= i & (-i)) {
            res += fen[i];
        }
        return res;
    }
    Number query(int l, int r) {
        if(l > r) return 0;
        return pquery(r) - pquery(l-1);
    }
};

int dp[maxn];

ll pre[maxn];
int n;
ll a[maxn];
bitset<maxn> vis = 0;
int res = 0;
void solve() {
    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        if(i>0) {
            pre[i] = pre[i-1];
        }
        if(a[i] >= 0) {
            res++;
            pre[i] += a[i];
            vis[i] = true;
        }
    }
    multiset<pl> ds;
    rep(i, n) {
        if(!vis[i]) {
            ds.insert({a[i], i});
        }
    }
    while(!ds.empty()) {
        auto c = *ds.rbegin(); ds.erase(ds.find(c));
        auto mn = *min_element(pre+c.se, pre+n);
        if(mn + c.fi >= 0) {
            res++;
            for(int i = c.se; i < n; ++i) {
                pre[i] += c.fi;
            }
        }
    }
    cout << res << '\n';





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