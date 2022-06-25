
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

const int maxn = 2e5 + 5;

int n, k;
ll m;
ll a[maxn];
ll b[maxn];
stack<pair<ll,ll>> s;

void push_s(const pl& p) {
    if(p.second == 0) return;
    ll value = p.first;
    ll count = p.second;
    while(!(value % m)) {
        count *= m;
        value /= m;
    }
    if(!s.empty() && s.top().first == value) {
        auto p2 = s.top(); s.pop();
        s.push({value, p2.second + count});
    } else {
        s.push({value, count});
    }
}

void solve(int t) {
    cin >> n>> m;
    assert(m > 1);
    rep(i, n) {
        cin >> a[i];
    }
    cin >> k;
    rep(i, k) {
        cin >> b[i];
    }
    s = stack<pair<ll,ll>>();


    for(int i = n-1; i >= 0; i--) {

        push_s({a[i], 1});
    }
    ll next_b = 0;

    while(!s.empty()) {

        if(next_b == k) {
            cout << "NO" << '\n'; return;
        }
        auto p = s.top();
        //cout << next_b << ' ' << p.first << ' ' << p.second << '\n';
        s.pop();
        if(b[next_b] == p.first) {
            p.second--;
            push_s(p);
            next_b++;
        } else if(b[next_b] < p.first) {
            cout << "NO" << '\n'; return;
        } else {
            bool found = false;
            while(p.second >= m) {
                //cout << p.first << ' ' << p.second << endl;
                if(b[next_b] < p.first) {
                    cout << "NO" << '\n'; return;
                } else if(b[next_b] == p.first) {
                    p.second--;
                    push_s(p);
                    next_b++;
                    found = true; break;
                } else {
                    push_s({p.first, p.second % m});
                    p.first *= m;
                    p.second /= m;
                }
            }
            if(found) {
                continue;
            }
            //cout << p.first << ' ' << p.second << endl;
            if(b[next_b] == p.first) {
                p.second--;
                push_s(p);
                next_b++;
            } else {
                cout << "NO" << '\n'; return;
            }
        }
    }

    if(next_b != k) {
        cout << "NO" << '\n'; return;
    }
    cout << "YES" << '\n'; return;
    

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

    //init();
    int count = 1;
    while(t--)
    {
        // cout << "Case #" << count << ":";
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





