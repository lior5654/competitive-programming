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
const ll INFL = 4e18 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}
 
 
// LIORZ LIORZ LIORZ LIORZ LIORZ
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES

const int maxn = 2e6 + 5;
const ll mod = 1e9 + 7;
ll dp[maxn];
void solve()
{
    int n, k; cin >> n >> k;
    vi lpos(k, 0);
    clrcin
    string s; cin >> s;
    int m = s.size();
    dp[0] = 1;
    for(int i = 1; i <= m; ++i)
    {
        dp[i] = 2 * dp[i-1];
        if(lpos[s[i-1]-'a'] > 0)
        {
            dp[i] -= dp[lpos[s[i-1]-'a']-1];
        }
        dp[i] = (dp[i] + mod) % mod;
        lpos[s[i-1]-'a'] = i;
    }
    priority_queue<pi, vpi, greater<pi>> pq;
    rep(i, k)
    {
        pq.push({lpos[i], i});
    }
    rep(i, n)
    {
        int c = pq.top().se; pq.pop();
        dp[i+m+1] = 2*dp[i+m];
        if(lpos[c] > 0)
        {
            dp[i+m+1] -= dp[lpos[c]-1];
        }
        lpos[c] = i+m+1;
        pq.push({lpos[c], c});
        dp[i+m+1] = (dp[i+m+1] + mod) % mod;
    }
    cout << dp[n+m] << '\n';


}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 /*



 # s.t bits are not all contained in the maximu. i.e there exists a bit b such that max[b] = 0 && exists l <= k <= r such that a[k][b] = 1
 
 do segment tree over or + bs
 */

 
 
 
 
 
 
 
 
signed main()
{
    GOGOGO
    cout << fixed << setprecision(6);
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