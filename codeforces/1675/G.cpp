
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


const int maxn = 250 + 5;
const int maxm = 250 + 5;

ll dp[2*maxm][maxm] = { 0 }; // I want to output i and my final value should be j
ll dp2[2*maxm][maxm] = { 0 }; // I want to output i and my final value should be <= j

ll a[maxn];
int n, m;


void update_dp2() {
    for(int i = -m; i <= m; i++) {
        dp2[i+m][0] = dp[i+m][0];
        for(int j = 1; j <= m; j++) {
            dp2[i+m][j] = min(dp2[i+m][j-1], dp[i+m][j]);
        }
    }
}


void init_dp() {
    for(int i = -m; i <= m; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i+m][j] = INFL;
        }
    }
    dp[0+m][0] = 0;
}


void construct_dp(int index) {
    for(int i = -m; i <= m; i++) {
        for(int j = 0; j <= m; j++) {
            int ni = j - (a[index] - i);
            if(ni < -m || ni > m) {
                dp[i+m][j] = INFL;
            } else {
                dp[i+m][j] = min(INFL, abs(i) + dp2[ni+m][j]); 
            }
        }
    }
}

void input() {
    cin >> n >> m;
    rep(i, n) {
        cin >> a[i];
    }
}
void solve(int t) {
    input();
    init_dp();
    update_dp2();

    for(int i = n - 1; i >= 0; --i) {
        construct_dp(i);
        update_dp2();
    }

    cout << dp2[0+m][m] << '\n';



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

    int count = 1;
    while(t--)
    {
        //cout << "Case #" << count << ":";
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





