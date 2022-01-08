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
// #define INPUT_FILE "maze2.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/

const int maxn = 5e3 + 5;
const ll mod = 998244353;


string s;
int n, k;
ll fact[maxn];
ll ifact[maxn];

ll pow(ll b, ll p) {
    ll curr = b; ll res = 1;
    while(p) {
        if (p % 2) {
            res *= curr; res %= mod;
        }
        curr *= curr; curr %= mod;
        p /= 2;
    }
    return res;
}

ll inv(ll x) {
    return pow(x, mod-2);
}

void init_comb() {
    fact[0] = 1; fact[1] = 1;
    for(ll i = 2; i < maxn; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    ifact[maxn-1] = inv(fact[maxn-1]);
    for (ll i = maxn-2; i >= 0; i--) {
        ifact[i] = (ifact[i+1] * (i+1)) % mod;
    }
}

ll choose(ll x, ll y) { // (x choose y)
    if (y > x) {
        return 0;
    }
    return ((((fact[x] * ifact[y])) % mod) * ifact[x-y]) % mod;
}

void solve(int t) {
    init_comb();

    cin >> n >> k;
    cin >> s;

    if (k == 0) {
        cout << 1 << endl; return;
    }
    vi idx;
    idx.pb(-1);
    rep(i, n) {
        if (s[i] == '1') {
            idx.pb(i);
        }
    }
    idx.pb(n);
    if (idx.size() < k+2) {
        cout << 1 << '\n'; return;
    }
    auto available_size = [&](int whoami) -> int {
        return idx[whoami+1] - idx[whoami-k] - 1;
    };
    ll res = choose(available_size(k), k);
    for(int whoami = k + 1; whoami < csz(idx) - 1; ++whoami) {
        res += choose(available_size(whoami), k) - choose(idx[whoami] - idx[whoami-k] - 1, k-1);
        res += mod;
        res %= mod;
    }
    cout << res << '\n';

    
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
    for(int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/

/****************************** end /main.cpp ******************************/





