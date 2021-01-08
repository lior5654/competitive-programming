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
               ___,'`-._ \_/ `,._        ;
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
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

template<class T> using func = function<T>;

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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ

























#define int int64_t








const int maxn = 3e5 + 5;
int a[maxn] = { 0 };
int pre[maxn] = { 0 };
//int suf[maxn];
int help[maxn] = { 0 };
int n;
#define BRUH_WHY_TESTCASES


bool is_good(int a, int b, int c) {
    return (a > b && b < c) || (a < b && b > c); 
}
void solve()
{
    cin >> n;
    rep(i, n) {
        cin >> a[i+1];
    }
    pre[0] = 0;
    pre[1] = 0;
    pre[2] = 0;
    help[1] = 0;
    help[n] = 0;
    help[n+1] = 0;
    for(int i = 3; i <= n; ++i) {
        pre[i] = pre[i-1] + is_good(a[i-2], a[i-1], a[i]);
        help[i-1] = is_good(a[i-2], a[i-1], a[i]) ? 1 : 0;
    }
    int ans = pre[n];
    for(int i = 1; i <= n; ++i) {
        vector<int> tests;
        for(int u : vector<int>({i-2, i-1, i, i+1, i+2}))
        {
            if(u >= 1 && u <= n) {
                tests.pb(a[u]-1);
                tests.pb(a[u]+1);
                tests.pb(a[u]);
            }
        }
        tests.pb(-1);
        tests.pb(INFI + 1e8);
        for(auto t : tests) {
            int old = a[i];
            a[i] = t;
            int v = pre[n] - help[i] - help[i-1] - help[i+1];
            for(auto u : {i-1, i, i+1}) {
                if(u-1>=1 && u+1 <=n && is_good(a[u-1], a[u], a[u+1])) v++;
            }
            a[i] = old;
            ans = min(ans, v);
        }
    }
    cout << max(ans, 0LL) << '\n';


}










































signed main()
{
    GOGOGO
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