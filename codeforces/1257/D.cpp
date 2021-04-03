/*
                            . .  ,  ,
                            |` \/ \/ \,',
                            ;          ` \/\,.
                           :               ` \,/
                           |                  /
                           ;                 :
                          :                  ;
                          |      ,---.      /
                         :     ,'     `,-._ \
                         ;    (   o    \   `'
                       _:      .      ,'  o ;
                      /,.`      `.__,'`-.__,
                      \_  _               \
                     ,'  / `,          `.,'
               ___,'`-._ \_/     `,._        ;
            __;_,'      `-.`-'./ `--.____)
         ,-'           _,--\^-'
       ,:_____      ,-'     \
      (,'     `--.  \;-._    ;
      :    Y      `-/    `,  :
      :    :       :     /_;'
      :    :       |    :
       \    \      :    :
        `-._ `-.__, \    `.
           \   \  `. \     `.
         ,-;    \---)_\ ,','/
         \_ `---'--'" ,'^-;'
         (_`     ---'" ,-')
         / `--.__,. ,-'    \
-hrr-    )-.__,-- ||___,--' `-.
        /._______,|__________,'\
        `--.____,'|_________,-'

                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including

using namespace __gnu_pbds;
using namespace std;


typedef long long int ll;
//typedef __int128_t bigint;
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
typedef tree<
pl,
null_type,
less<pl>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


typedef long double ld;
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm

const int INFI = 1e9 + 5;
const ll INFL = 1e17 + 5;



template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}





#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

const int maxn = 2e5 + 5;
const int maxm = 2e5 + 5;
const int maxh = 18;
int n; int m;

int a[maxn];
int dp[maxn];
struct rmq {
    int f[maxh][maxn];
    vi lg;
    void init() {
        lg.clear();
        lg.pb(0); lg.pb(0);
        for(int i = 2; i <= n; ++i) {
            lg.pb(lg[i/2]+1);
        }
        rep(i, n) {
            f[0][i] = a[i];
        }
        for(int h = 1; h < maxh; ++h) {
            int s = 1 << h;
            for(int i = 0; i + s - 1 < n; ++i) {
                f[h][i] = max(f[h-1][i], f[h-1][i+s/2]);
            }    
        }
    }
    int query(int l, int r) {
        int mlg = lg[r-l+1];
        int sz = 1<<mlg;
        return max(f[mlg][l], f[mlg][r-sz+1]);
    }
} ds;

void clean_testcase() {
    ds.lg.clear();
    for(int i = 1;  i <= n; ++i) {
        dp[i] = 0;
    }
    rep(i, n) {
        ds.f[0][i] = 0; a[i] = 0;
    }
    n=m=0;
}
void solve() {
    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    ds.init();
    cin >> m;
    rep(i, m){
        int s, p; cin >> p >> s;
        dp[s] = max(dp[s], p);
    }
    for(int i = n-1; i >= 1; --i) {
        dp[i] = max(dp[i], dp[i+1]);
    }
    int next = 0;
    int dcount = 0;
    while(next < n) {
        dcount++;
        int l = 1; int r = n - next; int best = -1;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(dp[mid] >= ds.query(next, next+mid-1)) {
                best = mid; l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(best == -1) {
            cout << -1 << '\n';
            clean_testcase();
            return;
        }
        next += best;
    }
    cout << dcount << '\n';
    clean_testcase();
}




signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
    #endif
    //GOGOGO
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











