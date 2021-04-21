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


const int maxn = 2e5 + 5;
const int maxh = 18;
int sieve[maxn];

int a[maxn];
int n;
int last_seen[maxn];
int fr[maxh][maxn];
int q;
void init_sieve() {
    for(int i = 2; i < maxn; ++i) {
        // n*log(n)
        if(sieve[i] == 0) {
            // i is prime
            for(int j = i; j < maxn; j += i) { // iterate over all multiples of i
                
                sieve[j] = i;
            }
        }
    }
}
vpl factor(int x) {
    vpl res;
    while(x != 1) {
        int cnt = 0;
        int removing_now = sieve[x];
        while(sieve[x] == removing_now) {
            cnt++;
            x /= removing_now;
        }
        res.push_back({(ll)removing_now, (ll)cnt});
    }
    return res;
} 
 
void solve() {
    cin >> n >> q;
    init_sieve();
    rep(i, n) {
        cin >> a[i];
    }
    for(int i = 1; i < maxn; ++i) {
        last_seen[i] = n;
    }
    for(int i = n-1; i >= 0; --i) {
        vpl f = factor(a[i]);
        int best = n;
        for(const auto& e : f) {
            best = min(best, last_seen[e.fi]);
            last_seen[e.fi] = i;
        }
        fr[0][i] = best;
    }
    fr[0][n] = n;
    for(int i = n-2; i >= 0; --i) {
        fr[0][i] = min(fr[0][i], fr[0][i+1]);
    }
    for(int h = 1; h < maxh; ++h) {
        for(int i = 0; i <= n; ++i) {
            fr[h][i] = fr[h-1][fr[h-1][i]];
        }
    }
    rep(_, q) {
        int l, r; cin >> l >> r; l--; r--;
        // we want to pass r completely? adjust +- 1
        int res = 0;
        for(int h = maxh -1 ; h >= 0; --h) {
            if(fr[h][l] <= r) {
                l = fr[h][l]; res += 1<<h;
            }
        }
        res++;
        cout << res << '\n';
    }
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











