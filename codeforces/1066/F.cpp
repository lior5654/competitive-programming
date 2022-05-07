
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
pl pts[maxn]; int n;
vvpl levels;

void input() {
    cin >> n;
    rep(i, n) {
        cin >> pts[i].fi >> pts[i].se;
    }
}

ll level(const pl& a) {
    return max(a.fi, a.se);
}

ll distance(const pl& a, const pl& b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

ll rcost(int lvl, int idx) { // finish at r
    const pl& p = levels[lvl][idx];
    return 2ll * distance(p, levels[lvl][0]) + distance(p, levels[lvl][csz(levels[lvl])-1]);
}

ll lcost(int lvl, int idx) { // finish at l
    const pl& p = levels[lvl][idx];
    return 2ll * distance(p, levels[lvl][csz(levels[lvl])-1]) + distance(p, levels[lvl][0]);
}

void prepare_levels() {
    sort(pts, pts+n, [&](const pl& a, const pl& b){
        if(level(a) == level(b)) {
            ll lvl = level(a);
            if(a.se == lvl && b.se != lvl) {
                return true;
            }
            if(b.se == lvl && a.se != lvl) {
                return false;
            }
            if(a.se == lvl && b.se == lvl) {
                return a.fi < b.fi;
            }
            return a.se > b.se;
        }
        return level(a) > level(b);
    });
    pts[n] = {0,0};
    n++;
    int i = 0;
    while(i < n) {
        int curr = levels.size();
        levels.pb(vpl());
        int lvl = level(pts[i]);
        while(i < n && level(pts[i]) == lvl) {
            levels[curr].pb(pts[i]); i++;
        }
    }
}
void solve(int t) {
    input();
    prepare_levels();

    ll bl = 0; ll br = 0;

    int level_count = levels.size();

    for(int i = 1; i < level_count; i++) {
        ll nbl = INFL; ll nbr = INFL;
        for(int j = 0; j < csz(levels[i-1]); j++) {
            nbl = min(nbl, distance(levels[i][0], levels[i-1][j]) + min(lcost(i-1, j) + bl, rcost(i-1, j) + br));
            nbr = min(nbr, distance(levels[i][csz(levels[i])-1], levels[i-1][j]) + min(lcost(i-1, j) + bl, rcost(i-1, j) + br));
        }
        bl = nbl; br = nbr;
    }

    cout << bl << endl;


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





