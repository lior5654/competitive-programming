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







int n;
int t;

struct song {
    int g; int t;
};

const int maxn = 15;
const ll mod = 1e9 + 7;

song songs[maxn+1];
ll dp[3][maxn+1][maxn+1][maxn+1];

void init_dp() {
    dp[0][1][0][0] = 1;
    dp[1][0][1][0] = 1;
    dp[2][0][0][1] = 1;

    for(ll sum = 2; sum <= maxn; ++sum) {
        for(ll g2 = 0; g2 <= sum; ++g2) {
            for(ll g3 = 0; g3 <= sum - g2; ++g3) {
                ll g1 = sum - g2 - g3;
                if (g1 < 0) {
                    continue;
                }
                if (g1) dp[0][g1][g2][g3] = g1 * (dp[1][g1-1][g2][g3] + dp[2][g1-1][g2][g3]);
                if (g2) dp[1][g1][g2][g3] = g2 * (dp[0][g1][g2-1][g3] + dp[2][g1][g2-1][g3]);
                if (g3) dp[2][g1][g2][g3] = g3 * (dp[1][g1][g2][g3-1] + dp[0][g1][g2][g3-1]);

                dp[0][g1][g2][g3] %= mod;
                dp[1][g1][g2][g3] %= mod;
                dp[2][g1][g2][g3] %= mod;


            }
        }
    }
}

void solve(int t) {
    init_dp();
    cin >> n >> t;
    rep(i, n) {
        cin >> songs[i].t >> songs[i].g; songs[i].g--;
    }
    ll res = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int curr_sum = 0;
        array<int, 3> genres = {0, 0, 0};
        for(int i = 0; i < n; i++) {
            if(mask&(1<<i)) {
                curr_sum += songs[i].t;
                genres[songs[i].g]++;
            }
        }
        if (curr_sum == t) {
            res += dp[0][genres[0]][genres[1]][genres[2]] + 
                   dp[1][genres[0]][genres[1]][genres[2]] + 
                   dp[2][genres[0]][genres[1]][genres[2]];
            res %= mod;
        }
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





