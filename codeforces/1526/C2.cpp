
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



struct Segtree {
    int tl; int tr; int tm; ll val; Segtree* l; Segtree* r; ll lazy;
    Segtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm = tl+(tr-tl)/2; l=r=nullptr; val=0; lazy = 0;
    }
    void pull() {
        val = min(l->val, r->val);
    }
    void push() {
        if(l == nullptr || r==nullptr) return;
        if(lazy) {
            l->val += lazy; r->val += lazy; l->lazy += lazy; r->lazy += lazy; lazy = 0; 
        }
    }
    void build() {  // NO INITIAL ARRAY
        if(tl == tr) {
            val = 0; 
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(); r->build();
            pull();
        }
    }
    void build(ll* x) {  // INITIAL ARRAY
        if(tl == tr) {
            val = x[tl]; 
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(x); r->build(x);
            pull();
        }
    }
    void update(int ql, int qr, ll v) {
        if(ql > qr || qr < tl || ql > tr) return;
        if(ql == tl && qr == tr) {
            val += v; lazy += v; return;
        } else {
            push();
            l->update(ql, min(tm, qr), v); r->update(max(ql,tm+1), qr, v);
            pull();
        }
    }
    ll query(int ql, int qr) {
        if(ql > qr || qr < tl || ql > tr) return INFL;
        if(ql == tl && qr == tr) return val;
        push();
        return min(l->query(ql, min(tm, qr)), r->query(max(ql,tm+1), qr));
    }
};



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
    Segtree st(0, n-1);
    st.build(pre);

    multiset<pl> ds;
    rep(i, n) {
        if(!vis[i]) {
            ds.insert({a[i], i});
        }
    }
    while(!ds.empty()) {
        auto c = *ds.rbegin(); ds.erase(ds.find(c));
        auto mn = st.query(c.se, n-1); 
        if(mn + c.fi >= 0) {
            res++;
            st.update(c.se, n-1, c.fi);
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