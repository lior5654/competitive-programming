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


#define YES "YES"
#define NO "NO"

const int maxn = 1e5 + 5;

string a[maxn]; int n;

void solve(int t) {
    cin >> n;
    bool length_one_string = false;
    rep(i, n) {
        cin >> a[i];
        if(a[i].size() == 1) {
            length_one_string = true;
        }
    }
    if (length_one_string) {
        cout << YES << '\n'; return;
    }

    set<string> reversed_strings;
    for(int i = 0; i < n; i++) {
        string ri = a[i];
        reverse(all(ri));
        reversed_strings.insert(ri);
    }
    for(int i = 0; i < n; i++) {
        if (reversed_strings.find(a[i]) != reversed_strings.end()) {
            cout << YES << '\n'; return;
        }
    }
    

    vector<vector<bool>> saw(26, vector<bool>(26, false));
    for(int i = n - 1; i >= 0; i--) {
        if(a[i].size() == 2) {
            if (saw[a[i][0]-'a'][a[i][1]-'a']) { // yx
                cout << YES << '\n'; return;
            }
        } else {
            assert(a[i].size() == 3);
            saw[a[i][2]-'a'][a[i][1]-'a'] = true;  // zxy
        }
    }


     vector<vector<bool>> saw2(26, vector<bool>(26, false));
    for(int i = 0; i < n; i++) {
        if(a[i].size() == 2) {
            if (saw2[a[i][0]-'a'][a[i][1]-'a']) {
                cout << YES << '\n'; return;
            }
        } else {
            assert(a[i].size() == 3);
            saw2[a[i][1]-'a'][a[i][0]-'a'] = true;
        }
    }
    cout << NO << '\n'; return;
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





