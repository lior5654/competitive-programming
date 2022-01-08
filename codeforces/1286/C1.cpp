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


const int maxn = 1e2 + 5;

vector<vector<array<int, 26>>> query(int l, int r) {
    cout << "?" << " " << l << " " << r << endl;
    int n = r - l  + 1;
    vector<vector<array<int, 26>>> res(n+1);
    rep(i, n * (n+1) / 2) {
        string s; cin >> s;
        array<int, 26> curr = { 0 };
        int len = s.size();
        for(auto c : s) {
            curr[c-'a']++;
        }
        res[len].pb(curr);
    }
    return res;
}

bool are_equal(const array<int, 26>& a, const array<int, 26>& b) {
    for(int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void solve(int t) {
    int n; cin >> n;
    if(n == 1) {
        cout << "?" << " " << 1 << " " << 1 << endl;
        string s; cin >> s;
        cout << "!" << " " << s << endl;
        return;
    }
    auto everything = query(1, n);
    auto everything_except_first = query(2, n);
    everything_except_first.pb(vector<array<int, 26>>());
    
    /*
    for(auto a : everything_except_first) {
        for (auto b : a) {
            for(auto d : b) {
                cout << d << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << endl << endl;

    for(auto a : everything) {
        for (auto b : a) {
            for(auto d : b) {
                cout << d << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }*/
    
    
    vector<array<int, 26>> good;
    good.pb(array<int, 26>{0});

    for (int i = 1; i <= n; i++) {
        vector<bool> vis(n-i, false);
        for(auto e : everything[i]) {
            int who = 0;
            for(auto ne : everything_except_first[i]) {
                if(!vis[who] && are_equal(ne, e)) {
                    break;
                }
                who++;
            }
            if (who == n-i) {
                good.pb(e);
                break;
            }
            vis[who] = true;
        }
    }
    
    


    
    cout << "!" << " ";
    for(int i = 1; i <= n; i++) {
        for(int c = 0; c < 26; c++) {
            if (good[i][c] == good[i-1][c] + 1) {
                cout << (char)(c+'a');
            }
        }
    }
    cout << endl;
    
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





