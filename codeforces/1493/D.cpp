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
//#define PREC 10
//#define USACO "sleepy"

const int maxn = 2e5 +5;
const ll mod = 1e9 + 7;
int a[maxn];
int sieve[maxn];
map<ll, ll> a_exps[maxn];

multiset<ll> exponent_counts[maxn];
int zero_counts[maxn]; // for each prime i, how many exponents are 0
int n, q;



ll bexp(ll b, ll p) { // calculate b^p modulo mod
    ll curr = b; ll res = 1;
    while(p) {
        if(p%2) {
            res *= curr; res %= mod;
        }
        curr *= curr; curr %= mod; p/=2;
    }
    // curr = b, b^2, b^4, b^8, ...
    // we iterate over the bits of the exponent...

    return res;
}





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
    init_sieve();
    cin >> n >> q;
    aread(a, n);
    for(int i = 1; i < maxn; ++i) {
        zero_counts[i] = n;
    }
    rep(i, n) {
        vpl factors = factor(a[i]);
        for(auto f : factors) {  // {p, a} (p^a)
            exponent_counts[f.first].insert(f.second);
            zero_counts[f.first]--;
            a_exps[i][f.first] = f.second;
        }
    }
    ll ans = 1;
    for(int i = 1; i < maxn; ++i) {
        if(zero_counts[i] == 0) {
            ans *= bexp(i, *exponent_counts[i].begin()); ans %= mod;
        }
    }


    rep(_, q) {
        int i; ll x; cin >> i >> x; --i; 
        vpl factors = factor(x);
        for(auto f : factors) {
            if(!a_exps[i].count(f.first)) { // I did not find
                a_exps[i][f.first] = f.second;
                exponent_counts[f.first].insert(f.second);
                zero_counts[f.first]--;
                if(zero_counts[f.first] == 0) {
                    ans *= bexp(f.first, *exponent_counts[f.first].begin()); ans %= mod;
                }
            } else { // I did find
                ll old_min = *exponent_counts[f.first].begin();
                exponent_counts[f.first].erase(exponent_counts[f.first].find(a_exps[i][f.first]));
                a_exps[i][f.first] += f.second;
                exponent_counts[f.first].insert(a_exps[i][f.first]);
                ll new_min = *exponent_counts[f.first].begin();
                if(zero_counts[f.first] == 0) {
                    ans *= bexp(f.first, new_min - old_min); ans %= mod;
                }
            }


        }
        cout << ans << '\n';
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
 
 
 
 
 
 
 
 
 
 
 
 