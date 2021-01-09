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
pi,
null_type,
less<pi>,
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
const ll INFL = 1e18 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}

 
 
 
 
 























 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
const int maxn = 1e2 + 5;
const unsigned long long maxk = 1e12 + 5;
const int maxa = 26;


unsigned long long dp[maxn][maxn][maxa+1];  
void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    for(int j = 1; j <= n; ++j) {
        for(int c = 0; c < 26; ++c) {
            dp[1][j][c] = (dp[1][j-1][c] > 0 || s[j-1] == 'a' + c) ? 1 : 0;
            dp[1][j][26] += dp[1][j][c];
        }
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int c = 0; c < 26; ++c) {
                dp[i][j][c] = dp[i][j-1][c];
                if(s[j-1] == 'a' + c) {
                    dp[i][j][c] += dp[i-1][j-1][26] - dp[i][j-1][c];
                }
                dp[i][j][c] = min(dp[i][j][c], (unsigned long long)INFL);
                dp[i][j][26] +=dp[i][j][c];
                dp[i][j][26] = min(dp[i][j][26], (unsigned long long)INFL);
            }
        }
    }
    dp[0][n][26] = 1;
    ll cnt = 0;
    ll cost = 0;
    int i = n;
    while(i >= 0 && cnt < k) {
        if(dp[i][n][26] >= INFL || cnt + dp[i][n][26] >= k) {
            cost += (n - i) * (k - cnt);
            cnt = k;
            break;
        } else {
            cost += (n - i) * dp[i][n][26];
            cnt += dp[i][n][26];
        }
        i--;
    }
    if(i == -1) cout << -1 << '\n';
    else cout << cost << '\n';

}
 
 
 



























































 
signed main()
{
    GOGOGO
    //cout << fixed << setprecision(6);
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
