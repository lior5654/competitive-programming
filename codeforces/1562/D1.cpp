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


const int maxn = 3e5 + 5;

int a[maxn]; int n; int q;

vpi queries[maxn];
int output[maxn];
int pre[maxn];

const int maxv = 3e6 + 5;
const int voff = 7e5;
int lst[maxv];

void solve() {
    cin >> n >> q;
    rep(i, n) {
        char c; cin >> c;
        if(c == '+') {
            a[i+1] = 1;
        } else {
            assert(c=='-');
            a[i+1] = -1;
        }
    }
    rep(i, q) {
        int l, r; cin >> l >> r;
        queries[l].pb({r, i});
    }
    pre[n] = a[n];
    int coeff = -1;
    for(int i = n-1; i >= 1; --i) {
        pre[i] = coeff * a[i] + pre[i+1];
        coeff *= -1;
    }
    for(int i = max(0, voff-3*n); i <= min(maxv-1, voff+3*n); ++i) {
        lst[i] = 2*n;
    }
    coeff = 1;
    for(int i = n; i >= 1; --i) {
       // cout << "yay"<< i << ' ' << (coeff)*(-a[i]) -2*pre[i+1] << '\n';
        lst[(coeff)*(-a[i]) -2*pre[i+1]+voff] = i;
        for(auto que : queries[i]) {
            int qidx = que.se; int l = i; int r = que.fi;
            //cout << qidx << ' ' << l << ' ' << r << '\n';

            if(l == n) {
                output[qidx] = 1;
            } else if (l == n-1) {
                if(r == n-1) {
                    output[qidx] = 1;
                } else {

                    assert(r == n);
                    if(a[l] == a[r]) {
                        output[qidx] = 0;
                    } else {
                        output[qidx] = 2;
                    }
                }
            } else {
                if(pre[l] - pre[r+1] == 0) {
                    output[qidx] = 0;
                } else {
                    int curr = pre[l] - pre[r+1];
                    //cout << 'c' << pre[l] << ' ' << pre[r+1] << ' ' << curr << '\n';
                    //cout << 'l' << lst[curr-2*pre[r+1]+voff] << '\n';
                    if(lst[-curr-2*pre[r+1]+voff] <= r) {
                        output[qidx] = 1;
                    } else {
                        output[qidx] = 2;
                    }
                }
            }
        }
        coeff *= -1;
    }
    rep(i, q) {
        cout << output[i] << '\n';
    }
    for(int i = 0; i <= n; ++i) {
        queries[i] = vpi(); pre[i] = 0;
    }
    for(int i = 0; i < q; ++i) {
        output[i] = 0;
    }


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





