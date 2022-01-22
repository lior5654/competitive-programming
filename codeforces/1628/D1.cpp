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
#define BRUH_WHY_TESTCASES
//#define PREC 7
// #define INPUT_FILE "maze2.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/


const ll mod = 1e9 + 7;
ll k;
const int maxn = 2e3 + 5;
const int maxm = 2e3 + 5;

ll n, m;
ll dp[maxn][maxm];
ld adp[maxn][maxm];
ll mpow(ll b, ll p) {
    ll res = 1; ll curr = b;
    while (p) {
        if(p % 2ll) {
            res *= curr; res %= mod;
        }
        curr *= curr; curr %= mod;
        p /= 2ll;
    }
    return res;
}

ll inv(ll x) {
    return mpow(x, mod-2);
}

void solve(int t) {
    cin >> n >> m >> k;


    ll tinv = inv(2);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= i; j++) {
            if (i == j) {
                adp[i][j] = k * i;
                dp[i][j] = (k * i) % mod;
            } else if (j == 0) {
                adp[i][j] = adp[i-1][j];
                dp[i][j] = dp[i-1][j];
            } else {
                // dp[i-1][j], dp[i-1][j-1]
                // dp[i-1][j-1] <- add <= dp[i-1][j] <- subtract

                // if alice selects x, bob will select min(dp[i-1][j-1]+x, dp[i-1][j] - x)

                // alice wants to maximize min(dp[i-1][j-1]+x, dp[i-1][j] - x) 
                // dp[i-1][j-1]+x == dp[i-1][j] - x
                // x = min(k, (dp[i-1][j] - dp[i-1][j-1]) / 2)

                ll x = ((dp[i-1][j] - dp[i-1][j-1] + mod) * tinv) % mod;

                dp[i][j] = (dp[i-1][j-1]+x) % mod;

                

            }
        
        }
    }
    cout << dp[n][m] << '\n';
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





