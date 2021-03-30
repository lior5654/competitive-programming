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

typedef __int128_t bigint;
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

ll tmd(ll x, ll md) {
    return ((x%md)+md)%md;
}
ll tmd(bigint x, bigint md) {
    return ((x%md)+md)%md;
}

pl egcd(ll b, ll s) {
    if(s > b) {
        pl nres =  egcd(s, b);
        return {nres.se, nres.fi};
    }
    if(s == 0) return {1, 0};
    ll q = b/s;
    ll r = b-q*s;
    pl nres = egcd(s, r);
    return {nres.se, nres.fi-q*nres.se};
}

void solve() {
    ll a1, b1, a2, b2, l, r; cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    ll g = gcd(a1,a2);
    if(tmd(b1,g) != tmd(b2,g)) {
        cout << 0 << '\n';
        return;
    }
    ll c1 = a1/g; ll c2 = a2/g;
    // find v1, v2 such that v1c1 + v2c2 = 1
    /*
     * WLOG c2 >= c1
     * c2 = q*c1 + r
     * suppose c1*x + r*y = 1
     * => c1*x + (c2-qc1)y = 1
     * (x-qy)*c1 + y*c2 = 1
     * f(c1, r) = (x, y) =>
     * f(c2, c1) = (y, x-qy)
     */
    pl res = egcd(c1, c2);
    ll v1 = res.fi; ll v2 = res.se;
    assert(v1*a1 + v2*a2 == g);
    ll md = a1*a2/g; //lcm
    ll sol = tmd(tmd((v1*a1)/g,md)*((bigint)tmd(b2,md)),(bigint)md);
    sol += tmd(tmd((v2*a2)/g,md)*((bigint)tmd(b1,md)),(bigint)md);
    sol = tmd(sol,md);
    assert(sol%a2 == tmd(b2,a2));
    ll mink  = max((ll)ceil(((ld)b1-sol)/((ld)md)), (ll)ceil((((ld)b2-sol)/((ld)md))));
    l = max({l, md*mink + sol});
    if(l > r) {
        cout << 0 << '\n'; return;
    }
    // sol + k*md >= l
    // k >= ceil(l-sol)/md)
    // sol + k*md <= r
    // k <= floor((r-sol)/md)
    //cout << ((int)(floor(((ld)r-sol)/md))) << ' ' << ((int)(ceil(((ld)l-sol)/md))) << '\n';
    cout << ((ll)(floor(((ld)r-sol)/((ld)md)))) -  ((ll)(ceil(((ld)l-sol)/((ld)md)))) + 1ll << '\n'; return;




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











