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
const ll INFL = 1e18 + 5;

template<class T> using func = function<T>;

/************************************ general.hpp begin ************************************/

namespace CompetitiveProgramming
{

using bigint = long long int;
using ll = long long int;
using ftype = long double;
using ld = long double;

namespace IO
{

template<class ElementType> inline void output_array(ElementType* array, uint32_t size)
{
    if(size)
    {
        cout << *array++;
        size--;
        while(size)
        {
            cout << ' ' << *array++;
            --size;
        }
    }
    cout << '\n';
}

template<class Iterator> inline void output_iterator_range(Iterator begin, const Iterator& end)
{
    if(begin != end)
    {
        cout << *begin++;
        while(begin != end)
        {
            cout << ' ' << *begin++;
        }
    }
    cout << '\n';
}

template<class Container> inline void output_container(const Container& container)
{
    output_iterator_range(container.begin(), container.end());
}

template<class ElementType> inline void read_array(ElementType* array, uint32_t size)
{
    while(size)
    {
        cin >> *array++;
        --size;
    }
}

template<class Iterator> inline void read_iterator_range(Iterator begin, const Iterator& end)
{
    while(begin != end)
    {
        cin >> *begin++;
    }
}
template<class Container> inline void read_container(Container& container)  // I dont think this will work for set etc, only std::array, std::vector etc
{
    read_iterator_range(container.begin(), container.end());
}

}

}


using namespace CompetitiveProgramming;
using namespace IO;

/************************************ general.hpp end ************************************/



//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

const int maxn= 400 + 5;
ll n, m;

ll bexp(ll b, ll p) {
    ll res = 1; ll curr = b;
    while(p) {
        if(p%2) {
            res *= curr; res %= m;
        }
        p /= 2;
        curr *= curr; curr %= m;
    }
    return res;
}

ll inv(ll x) {
    return bexp(x, m-2);
}
ll fact[maxn];
ll ifact[maxn];
void init_comb() {
    fact[0] = 1;
    fact[1] = 1;
    for(ll i = 2; i <= n; ++i) {
        fact[i] = i * fact[i-1];
        fact[i] %= m;
    }
    ifact[n] = inv(fact[n]) % m;
    for(ll i = n-1; i >= 0; --i) {
        ifact[i] = (i+1LL) * ifact[i+1];
        ifact[i] %= m;
    }
}


ll choose(ll x, ll y) {
    if(y > x) return 0;
    return (((fact[x] * ifact[y]) % m) * ifact[x-y]) % m;
}

//ll dp[2][2][maxn][maxn];
ll dp[maxn][maxn]; // array of size i and I want to place j things in total
ll kdp[maxn][maxn];

void calc_kdp() {
    for(int j = 1; j <= n; ++j) {
        for(int k = 1; k <= j; ++k) {
            for(int i = 1; i <= k; ++i) {
                kdp[j][k] += choose(j, k) * choose(k-1, i-1);
                kdp[j][k] %= m;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    init_comb();
    calc_kdp();
    dp[0][0] = 1;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= i; ++j) {
            dp[i][j] = 0;
            for(ll k = 1; k < j; ++k) {
                dp[i][j] += kdp[j][k] * dp[i-k-1][j-k];
                dp[i][j] %= m;
            }
            if(j == i) {
                dp[i][j] += kdp[j][j];
                dp[i][j] %= m;
            }

        }
    }
    ll res = 0;
    for(int b = 1; b <= n; ++b) {
        res += dp[n][b];
        res %= m;
    }
    cout << res << '\n';

    /*
    vector<int> v;
    set<int> lol;
    v.pb(0);
    v.pb(1);
    v.pb(2);
    v.pb(3);
    v.pb(4);
    v.pb(5);
    do  
    {
        vector<bool> vis(6, false);
        vector<int> yay;
        bool good = true;
        for(auto e : v) {
            if(e!=0 && e!= 5 && vis[e-1] && vis[e+1]) {
                continue;
            }
            vis[e] = true;
            yay.pb(e);
        }
        while(yay.size() != 6) {
            yay.pb(6);
        }
        int po = 7*7*7*7*7*7;
        int rel = 0;
        rep(i, 6) {
            rel += po * yay[i]; po /= 7;
        }
        lol.insert(rel);
    } while (next_permutation(all(v)));
    cout << lol.size() << '\n';
    */
    /*
    int n, m; cin >> n >> m;

    for(int s = 1; s <= n; ++s) {
        for(int l = 1; l + s - 1 <= n; ++l) {
            int r = l + s - 1;
            // dp[x][y][l][r]
            
        }
    }*/

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











