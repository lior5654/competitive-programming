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




const int maxn = 1e6 + 5;

int n; ll r1, r2, r3; ll d; ll a[maxn]; ll dp[3][maxn];
#define REGULAR 0
#define ALLFREE 1
#define IAMFREE 2 

inline ll f(int i) {
    return min(r3, r1) * a[i] + r3;
}

inline ll g(int i) {
    //return min({r2, min(r1, r3)*a[i] + min(r1, r2)}) + min(r1,r2,r3);
    return min(r2, min(r1, r3)*a[i] + r1) + min({r1,r2,r3});
}

inline ll b(int i) {
    return min(g(i), f(i));
}

void solve() {
    cin >> n >> r1 >> r2 >> r3 >> d;
    rep(i, n) {
        cin >> a[i];
    }
    dp[REGULAR][n-2] = min({g(n-2) + d + g(n-1) + d + d, 
                     g(n-2) + d + f(n-1) + d, 
                     f(n-2) + d + g(n-1) + d + d,
                     f(n-2) + d + f(n-1)});

    dp[ALLFREE][n-2] = b(n-2) + min(f(n-1), g(n-1) + 2*d);
    dp[IAMFREE][n-2] = b(n-2) + min(d + f(n-1), d + g(n-1) + d + d);

    for(int i = n - 3; i >= 0; --i) {
        dp[REGULAR][i] = min({
            f(i) + d + dp[REGULAR][i+1],
            g(i) + (n-1LL-i) * d * 2LL + dp[ALLFREE][i+1],
            g(i) + 3*d + dp[IAMFREE][i+1]
        });
        dp[ALLFREE][i] = b(i) + dp[ALLFREE][i+1];
        dp[IAMFREE][i] = b(i) + d + dp[REGULAR][i+1];
    }
    cout << dp[REGULAR][0] << '\n';

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





