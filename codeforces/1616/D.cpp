
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

const int maxn = 5e4 + 5;


ll a[maxn];
ll pre[maxn];
int nextf[maxn]; // the closest j > i such that j - i > 1 and f(i) > f(j) 
int last_available[maxn];
int dp[maxn]; // minimum possible number of elements not to select in the suffix i..n, given than i is selected and i-1 is not selected

struct array_stack {
    int s[maxn]; int ps;
    void reset() {
        ps = -1;
    }
    bool empty() {
        return ps == -1;
    }
    int top() {
        assert(!empty());
        return s[ps];
    }
    void pop() {
        if(!empty()) ps--;
    }
    void push(int val) {
        s[++ps] = val;
    }
};

// btw, if we needed k before and not 1 before, persistent stack is preferred instead of this trick

array_stack s1; // curr
array_stack s2; // 1 before

int n; ll x;

ll f(int i) {
    return pre[i] - (((ll)i)-1ll) * x;
}

void update_stack(array_stack& stack, int index) {
    while(!stack.empty() && f(index) <= f(stack.top())) {
        stack.pop();
    }
    stack.push(index);
}

void init() {
    s1.reset(); s2.reset();
}

void input() {
    cin >> n;
    rep(i, n) {
        cin >> a[i+1];
    }
    cin >> x;
}

void calc_pre() {
    for(int i = 1; i <= n; i++) {
        pre[i] = a[i] + pre[i-1];
    }
}

void calc_nextf() {
    nextf[n+1] = n+1;
    nextf[n] = n+1;
    nextf[n-1] = n+1;

    // let's just guess that doing something ugly like this is O(n) (probably bounded by 8n or some weird wizadry)
    update_stack(s2, n);
    update_stack(s1, n);
    update_stack(s1, n-1);

    for(int i = n - 2; i >= 0; i--) {
        // calculating nextf[i]
        nextf[i] = n + 1;

        // this is O(n) because it's guarranteed that these values will disappear within O(1) steps in the loop, so they are touched O(1) times
        for(int j = s2.ps; j >= 0; j--) {
            if(f(i) > f(s2.s[j])) {
                nextf[i] = s2.s[j]; break;
            }
        }
        update_stack(s2, i+1);
        update_stack(s1, i);
    }
}

void calc_last_available() {
    last_available[n]= n;
    for(int i = n-1; i >= 1; i--) {
        last_available[i] = min(last_available[i+1], nextf[i-1]-1);
    }
}

void calc_dp() {
    dp[n] = 0;
    dp[n+1] = 0;
    dp[n+2] = 0;
    dp[n+3] = 0;
    for(int i = n - 1; i >= 1; i--) {
        int last = last_available[i];
        // claim: either choose everything up to last-1, then choose last+1
        // or choose everything up to last, then choose last+2 or last+3
        dp[i] = ((last+1>n)?0:1) + min(dp[last+2], ((last+2>n)?0:1) + dp[last+3]);
        if(last > i) {
            dp[i] = min(dp[i], 1 + dp[last+1]);
        }
    }
}

void debug() {
    cout << "DEBUG" << endl << endl;
    cout << "a: ";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "p: ";
    for(int i = 0; i <= n; i++) {
        cout << pre[i] << ' ';
    }
    cout << endl;
    cout << "f: ";
    for(int i = 0; i <= n; i++) {
        cout << f(i) << ' ';
    }
    cout << endl;

    cout << "n: ";
    for(int i = 0; i <= n; i++) {
        cout << nextf[i] << ' ';
    }
    cout << endl;
    cout << "l: ";
    for(int i = 1; i <= n; i++) {
        cout << last_available[i] << ' ';
    }
    cout << endl;
    cout << "d: ";
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
    cout << endl;
    cout << endl;
}
void solve(int t) {
    init();
    input();
    if(n == 1) {
        cout << 1 << '\n'; return;
    }
    calc_pre();
    calc_nextf();
    calc_last_available();
    calc_dp();


    //debug();
    cout << n - min(dp[1], 1+dp[2]) << '\n'; // if 2 is not chosen, not choosing 1 is dumb, hence atleast one of them is chosen in the optimal solution






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





