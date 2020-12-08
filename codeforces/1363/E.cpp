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


/*
const ll mod = 998244353;
template<int maxf> struct combi
{
    ll fact[maxf];
    ll invfact[maxf];
    ll bexp(ll b, ll p) const
    {
        ll res = 1;
        ll curr = b;   
        while(p)
        {
            if(p % 2ll)    
            {
                res *= curr;
                res %= mod;
            }

            curr *= curr;
            curr %= mod;
            p /= 2;
        }
        return res;
    }
    ll invmod(ll i) const
    {
        return bexp(i, mod - 2ll);
    }
    combi()
    {
        fact[0] = 1;
        fact[1] = 1;
        invfact[0] = invmod(1);
        invfact[1] = invfact[0];
        for(ll i = 2; i < maxf; ++i)
        {
            fact[i] = i * fact[i-1];
            fact[i] %= mod;
            invfact[i] = invmod(i);
        }
    }
    ll choose(ll n, ll k) const
    {
        if(k > n) return 0;
        return (((fact[n] * invfact[n-k]) % mod) * invfact[k]) % mod;
    }
};*/

// LIORZ LIORZ LIORZ LIORZ LIORZ
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
const int maxn = 2e5 + 5;

int n;

ll a[maxn];
bitset<maxn> b = 0;
bitset<maxn> c = 0;

vi g[maxn];

ll dp[maxn];
ll aleft[maxn];
ll bleft[maxn];
void dfs(int u, int p = 1) {
    for(auto e : g[u]) {
        if(e != p) {
            a[e] = min(a[e], a[u]);
            dfs(e, u);
            dp[u] += dp[e];
            aleft[u] += aleft[e];
            bleft[u] += bleft[e];
        }
    }
    if(b[u] == 0 && c[u] == 1) {
        aleft[u]++;
    } else if (b[u] == 1 && c[u] == 0) {
        bleft[u]++;
    }
    ll use = min(aleft[u], bleft[u]);
    dp[u] += 2 * use * a[u];
    aleft[u] -= use; bleft[u] -= use;

}
void solve()
{
    cin >> n;
    for(int i = 1 ; i <= n; ++i) {
        cin >> a[i]; int b1, b2; cin >> b1 >> b2; b[i] = b1; c[i] = b2;
    }
    rep(i, n - 1) {
        int s, t; cin >> s >> t; g[s].pb(t); g[t].pb(s);
    }
    dfs(1);
    if(aleft[1] || bleft[1]) {
        cout << -1 << '\n';
    } else {
        cout << dp[1] << '\n';
    }
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
