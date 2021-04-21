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





//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"


const int maxn = 1e2 + 5;
const int maxs = 100 * 2000 + 5;
bitset<maxs> bs = 0;

int sm; int n; int a[maxn]; int ta[maxn];
void solve() {


    
    cin >> n;
    rep(i, n) {
        cin >> a[i+1]; sm +=a[i+1]; ta[i+1] = a[i+1];
    }
    if(sm%2) {
        cout << 0 << '\n'; return;
    }
    bs[0] = 1;
    for(int i = 1; i <= n; ++i) {
        bitset<maxs> ts = bs << a[i];
        bs = bs | ts; 
    }
    if(!bs[sm/2]) {
        cout << 0 << '\n'; return;
    }
    while(true) {
        for(int i = 1; i <= n; ++i) {
            if(ta[i] % 2) {
                cout << 1 << '\n';
                cout << i << '\n';
                return;
            }
            ta[i] /= 2;
        }
    }
    /*
    cout << sm << '\n';
    for(int j = 0; j <= sm; ++j) {
        dp[j][1] = 0;
    }

    dp[a[1]][1] = INFI;
    if(2*a[1] <= sm) {
        dp[2*a[1]][1] = 1;
    }
    dp[0][1] = 1;
    // every element is qeighted 2 times
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= sm; ++j) {
            dp[j][i] = INFI;
            int v = 0;
            if(a[i] <= j) {
                dp[i][j] = min(dp[i][j], 1 + dp[j-a[i]][i-1]);
            }
            if(2*a[i] <= j) {
                v = max(v, dp[j-2*a[i]][i-1]);
            }
            
            v = max(v, dp[j][i-1]);
            dp[j][i] = min(dp[j][i], v);
        }
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= sm; ++j) {
            if(dp[j][i] >= INFI) {
                cout << -1 << ' ';
            } else {
                cout << dp[j][i] << ' ';
            }
        }
        cout << '\n';
    }
    cout << dp[sm][n] << '\n';
    */


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











