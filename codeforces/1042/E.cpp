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
// #define PREC 6
//#define USACO "sleepy"

/*

add elements smallest to biggest

when adding aij:

1/count(previous probabilities sum +  sum (xcoord^2 + ycoord^2 for all previos seen) + count * (my_xcoord^2 + my_ycoord^2) -2(sum(xcoord)) * my_xcor)

*/
const ll mod = 998244353;
inline ll bexp(ll b, ll p) {
    ll res = 1; ll curr = b;
    while(p) {
        if(p%2LL) {
            res *= curr; res %= mod;
        }
        curr *= curr; curr %= mod;
        p /= 2LL;
    }
    return res;
}
inline ll inv(ll x) {
    return bexp(x, mod-2LL);
}

const int maxn = 1e3 + 5;
int n, m; int a[maxn][maxn];
ll expec[maxn][maxn];
vpi order;
void solve() {
    cin >> n >> m;
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
            order.emplace_back(i, j);
        }
    }
    sort(all(order), [&](const pi& x, const pi& y) {
        return a[x.fi][x.se] < a[y.fi][y.se];
    });
    struct mem_t {
        stack<pi> prev; ll cnt; ll expec_sum; ll b; ll mi; ll mj;
        mem_t() {
            cnt=0; expec_sum=0; b=0; mi=0; mj=0;
        }
        void add(ll i, ll j) {
            cnt++; expec_sum += expec[i][j]; expec_sum %= mod;
            b += (i*i) + (j*j); b %= mod; mi += -2LL * i + mod; mi %= mod; mj += -2LL * j + mod; mj %= mod;   
        }
        ll calc(ll i, ll j) {
            if(cnt == 0) return 0;
            return (inv(cnt) * ((expec_sum + (b + (mi*i + (mj*j + (((i*i)%mod)*cnt + ((j*j)%mod)*cnt) % mod) % mod) % mod) % mod) % mod)) % mod;
        }
    } mem;
    for(auto c : order) {
        ll i = c.fi;
        ll j = c.se;
        while(!mem.prev.empty() && a[mem.prev.top().fi][mem.prev.top().se] < a[i][j]) {
            mem.add(mem.prev.top().fi, mem.prev.top().se);
            mem.prev.pop();
        }
        expec[i][j] = mem.calc(i, j);
    
        mem.prev.push({i, j});
    }
    int r, c; cin >> r >> c;
    cout << expec[r-1][c-1] << '\n';


}

 
 
/*

f(2^k-1) == (2^(k-1)) * 2 + 3 * f(2^(k-1)-1)

f(0) = 1
f(1) = 3
f(3) = 



0 1 2 7 8 15 24 37 38 49 62 81 98 121 146 175 176 195 216 247 272 

f(2^k-1) == 2^(2k-2) + 3 * f(2^(k-1)-1)

f(0) = 0
f(1) = 1
f(3) = 3 + 4 = 7
f(7) = 7*3 + 16 = 37
....

*/


























































 
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
