
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

const int maxn = 2e3 + 5;
#define WINNING 'G'
#define LOSING 'M'
#define TIE 'D'

inline pair<int, int> rotate45(const pi& pos, int size) {
    //return {(i-1) + (j-1) + 1, (i-1) - (j-1) + n - 1 + 1}

    return {pos.fi - pos.se + size + 1, pos.fi + pos.se - 1 + 1};
}

struct Rectangle {
    pi bottom_left; 
    pi top_right;
    
    bool contains(const pi& pos) {
        return bottom_left.fi <= pos.fi && pos.fi <= top_right.fi  &&
               bottom_left.se <= pos.se && pos.se <= top_right.se;
    }
    Rectangle intersect(const Rectangle& other) {
        Rectangle res;
        res.bottom_left.fi = max(bottom_left.fi, other.bottom_left.fi);
        res.bottom_left.se = max(bottom_left.se, other.bottom_left.se);
        res.top_right.fi = min(top_right.fi, other.top_right.fi);
        res.top_right.se = min(top_right.se, other.top_right.se);
        return res;
    } 
};

Rectangle get_banned_area(const pi& pos, int size, int banned_distance) {
    return Rectangle{.bottom_left=rotate45({pos.fi-banned_distance, pos.se}, size),
                     .top_right=rotate45({pos.fi+banned_distance, pos.se}, size)};
}

int distance(const pi& a, const pi& b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}


int n, k;

char result[maxn][maxn];

pi positions_of_values[maxn * maxn];

void input_and_setup() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int v; cin >> v;
            positions_of_values[v] = {i,j};
        }
    }
}

void perform_algorithm() {
    Rectangle losing_area = Rectangle{.bottom_left = {1, 1}, .top_right = {2*n, 2*n}};
    for(int v = n * n; v >= 1; v--) {
        const auto& pos = positions_of_values[v];
        const auto& t_pos = rotate45(pos, n);
        if (losing_area.contains(t_pos)) {
            result[pos.fi][pos.se] = LOSING;
            const auto& banned_area = get_banned_area(pos, n, k);
            losing_area = losing_area.intersect(banned_area);
        } else {
            result[pos.fi][pos.se] = WINNING;
        }
        
    }
}

void output_result() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << result[i][j];
        }
        cout << '\n';
    }
}

void solve() {
    input_and_setup();
    perform_algorithm();
    output_result();

    

}


void sanity_check() {
    char m[4][4] = {{'\0', '\0','\0','\0'},
                    {'\0', '1', '2', '3'},
                    {'\0', '4', '5', '6'},
                    {'\0', '7', '8', '9'}};
    char conv[8][8] = { { '\0' } };
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            conv[i][j] = 'X';
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            pi t = rotate45({i, j}, 3);
            conv[t.fi][t.se] = m[i][j];
        }
    }
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            cout << conv[i][j];
        }
        cout << '\n';
    }
    auto banned_area = get_banned_area({2,2}, 3, 1);    
    cout << "banned_area:\n\t" << "{" << banned_area.bottom_left.fi << ", " << banned_area.bottom_left.se << "}" << "\n\t" << "{" << banned_area.top_right.fi << ", " << banned_area.top_right.se << "}" << '\n' << '\n';

}


/*
explanation of rotate45:

The idea: diamonds -> rectangles
XXXYXXX
XXYYYXX
XYYYYYX
YYYYYYY
XYYYYYX
XXYYYXX
XXXYXXX

789ABCD
6789ABC
56789AB
456789A
3456789
2345678
1234567


T: (i, j) ~~~~~> (i+j, -(i+j) + 2*i + n - 1)
=>

T: (i, j) ~~~~~> (i+j, i - j + n - 1)

xxxxxxDxxxxxx
xxxxxCxCxxxxx
xxxxBxBxBxxxx
xxxAxAxAxAxxx
xx9x9x9x9x9xx
x8x8x8x8x8x8x
7x7x7x7x7x7x7
x6x6x6x6x6x6x
xx5x5x5x5x5xx
xxx4x4x4x4xxx
xxxx3x3x3xxxx
xxxxx2x2xxxxx
xxxxxx1xxxxxx
*/










































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





