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
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/

int k;

string num;

void solve() {
    cin >> k; //clrcin;
    cin >> num;
    rep(i, k) {
        if(num[i] == '1' || num[i] == '4'|| num[i] == '6' || num[i] == '8' || num[i] == '9') {
            cout << 1 << '\n';
            cout << num[i] << '\n';
            return;
        }
    }
    for(int i = 0; i < k; ++i) {
        assert(num[i] == '2' || num[i] == '3' || num[i] == '5' || num[i] == '7');
    }
    for(int i = 1; i < k; ++i) {
        if(num[i] == '5') {
            cout << 2 << '\n';
            cout << num[0] << num[i] << '\n';
            return;
        }
    }
    if(num[0] == '5') {
        for(int i = 1; i < k; ++i) {
            if(num[i] == '2' || num[i] == '7') {
                cout << 2 << '\n';
                cout << num[0] << num[i] << '\n';
                return;
            }
        }
        cout << 2 << '\n';
        cout << 33 << '\n';
        return;
    }
    for(int i = 0; i < k; ++i) {
        assert(num[i] == '2' || num[i] == '3' || num[i] == '7');
    }
    for(int i = 1; i < k; ++i) {
        if(num[i] == '2') {
            cout << 2 << '\n';
            cout << num[0] << num[i] << '\n';
            return;
        }
    }
    if(num[0] == '2') {
        for(int i = 1; i < k; ++i) {
            if(num[i] == '7') {
                cout << 2 << '\n';
                cout << num[0] << num[i] << '\n';
                return;
            }
        }
        cout << 2 << '\n';
        cout << 33 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < k; ++i) {
        if(num[i] == '7') {
            cnt++;
        }
    }
    if(cnt >= 2) {
        cout << 2 << '\n';
        cout << 77 << '\n';
        return;
    }
    cout << 2 << '\n';
    cout << 33 << '\n';
    /*
    for(int i = 0; i < k - 1; ++i) {
        if(num[i] == num[i+1]) {
            cout << 2 << '\n';
            cout << num[i] << num[i+1] << '\n';
            return;
        }
    }
    if(num[0] == '3') {
        assert(k >= 4 && num[1] == '7' && num[2] == '3' && num[3] == '7');
        cout << 3 << '\n';
        cout << 737 << '\n';
    } else {
        assert(k >= 3 && num[0] == '7' && num[1] == '3' && num[2] == '7');
        cout << 3 << '\n';
        cout << 737 << '\n';
    }
    */


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





