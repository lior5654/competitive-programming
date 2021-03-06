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





#define BRUH_WHY_TESTCASES
//#define PREC 6
//#define USACO "sleepy"

const int maxn = 2e5 + 5;
vi g[maxn]; int n; ll dp[2][maxn];
ll ck;
// dp[0][i] - the actual problem on subtree i. dp[1][i] - max distance left to go after visiting all nodes in i's subtree and coming back to the root 
void dfs(int c, int p=0) {
    dp[0][c] = 0; dp[1][c] = 0;
    bool is_leaf = true;
    for(auto e : g[c]) {
        if(e!=p) {
            dfs(e, c);
            is_leaf = false;
        }
    }
    if(is_leaf) {
        dp[0][c] = 1;
        dp[1][c] = ck;
        return;
    }
    // dp[0]
    bool res = false;
    bool saw_must = 0;
    for(auto e : g[c]) {
        if(e != p) {
            if(dp[1][e] < 2) {
                if(saw_must) {
                    res = false; break;
                }
                res = dp[0][e]; saw_must = true;
            } else {
                if(!saw_must) {
                    res |= dp[0][e];
                }
            }
        }
    }
    dp[0][c] = res;
    ll mn = INFI;
    ll mx = -INFI;
    ll l1cnt = 0;
    for(auto e : g[c]) {
        if(e != p) {
            mx=max(mx,dp[1][e]);
            mn=min(mn,dp[1][e]);
            l1cnt += dp[1][e] <= 1;
        } 
    }
    if(mn < 1 || mn == 1 && l1cnt > 1) {
        dp[1][c]=-1;
    }
    else if(mn == 1) {
        dp[1][c] = 0;
    } else {
        dp[1][c] = mx - 1;
    }
}
void clean_testcase() {
    for(int i = 1;i <= n; ++i) {
        g[i].clear();
    }
}

void solve() {
    cin >> n; rep(i, n-1) {
        int s, t; cin >> s >> t;
        g[s].pb(t); g[t].pb(s);
    }
    dfs(1);
    int l = 1; ll r = n; ll ans = n;
    while(l <= r) {
        ll m = l + (r-l)/2;
        ck = m; dfs(1);
        if(dp[1][1]>=0) {
            ans = m; r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';


    clean_testcase();
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
