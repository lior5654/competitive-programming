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
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

const ll mod = 998244353;
const int maxn = 5e3 + 5;
const int maxk = 5e3 + 5;
int n; ll k;
vi g[maxn];
vi gd[maxn];
int odeg[maxn];
pi dp[maxk][maxn];
int mprod(int l, int r) {
    return (((ll)l)*((ll)r))%mod;
}
int madd(int a, int b) {
    return (((a+b)%mod)+mod)%mod;
}
void meadd(int& a, int b) {
    a += b; a%=mod; a += mod; a %= mod;
}
void dfs(int c, int p = 0) {
    for(auto e : g[c]) {
        if(e!=p) {
            dfs(e, c); odeg[c]++;
            gd[c].pb(e);
        }
    }
    for(int i = 0; i <= k; ++i) {
        dp[i][c].fi = 1; 
    }
    for(int cn = 1; cn <= odeg[c]; ++cn) {
        int right_atmost_k = dp[k][gd[c][cn-1]].fi;
        dp[0][c].se = mprod(right_atmost_k, dp[0][c].fi);
        for(int w = 1; w <= k; ++w) {
            dp[w][c].se = dp[w-1][c].se;
            int left_exact_w = madd(dp[w][c].fi, -dp[w-1][c].fi);
            meadd(dp[w][c].se, mprod(left_exact_w, right_atmost_k));
            if(k-w-1>=0) {
                int right_atmost_kwm1 = dp[min((ll)w-1,k-w-1)][gd[c][cn-1]].fi;
                meadd(dp[w][c].se, mprod(left_exact_w, right_atmost_kwm1));
            }
            if(k-w>=0 && w-1>=0) {
                int left_atmost_kmw = dp[min((ll)w,k-w)][c].fi;
                int right_exact_wm1 =  dp[w-1][gd[c][cn-1]].fi;
                if(w-2 >= 0)
                    meadd(right_exact_wm1, -dp[w-2][gd[c][cn-1]].fi);
                meadd(dp[w][c].se, mprod(left_atmost_kmw, right_exact_wm1));
            }
            if(w-1>=0&&k-w-1>=w-1&&k-w>=w) {
                int right_exact_wm1 =  dp[w-1][gd[c][cn-1]].fi;
                if(w-2 >= 0)
                    meadd(right_exact_wm1, -dp[w-2][gd[c][cn-1]].fi);
                meadd(dp[w][c].se, -mprod(right_exact_wm1, left_exact_w));
            }
        }
        for(int w = 0; w <= k; ++w) {
            dp[w][c].fi = dp[w][c].se;
        }
    }
}
void solve() {
    cin >> n >> k;
    rep(i, n-1) {
        int s, t; cin >> s >> t; g[s].pb(t); g[t].pb(s);
    }
    dfs(1);
    cout << dp[k][1].fi << '\n';
}
 
 
 
 
signed main()
{
    #ifdef USACO
        freopen(USACO ".in", "r", stdin);
        freopen(USACO ".out", "w", stdout);
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
 
 
 
 
 
 
 
 
 
 
 
 