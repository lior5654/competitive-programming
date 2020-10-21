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
const int maxn = 2e5;
const int maxh = 18;

struct DS
{
    ll a[maxh][maxn]; int rf[maxn]; int lf[maxn]; int n; int sz;
    map<int, int> ub;
    int qc = 0;
    inline void input()
    {
        cin >> n;
        aread(a[0], n);
    }
    void buildROQ() // range or query
    {
        sz = log2(n) + 1;
        for(int p = 1; p < sz; ++p)
            for(int i = 0; i  < n + 1 - (1 << p); ++i)
                a[p][i] = a[p-1][i] | a[p-1][i+(1<<(p-1))];

    }
    ll roq(int l, int r)
    {
        assert(l <= r);
        int qi = log2(r - l + 1);
        return a[qi][l] | a[qi][r-(1<<qi)+1]; 
    }
    void buildMIQ() // maximum interval query
    {
        // monotonic stack bruh
        auto buildR = [&]() {
            stack<int> s;
            rf[0] = 0;
            s.push(0);
            for(int i = 1; i < n; ++i) {
                while(!s.empty() && a[0][s.top()] <= a[0][i]) s.pop();
                if(s.empty()) rf[i] = 0;
                else rf[i] = s.top() + 1; 
                s.push(i);
            }
        };
        auto buildL = [&]() { 
            stack<int> s;
            lf[n-1] = n-1;
            s.push(n-1);
            for(int i = n-2; i >= 0; --i) {
                while(!s.empty() && a[0][s.top()] <= a[0][i]) s.pop();
                if(s.empty()) lf[i] = n-1;
                else lf[i] = s.top() - 1; 
                s.push(i);
            }  
        };
        buildR(); buildL();
    }
    pi miq(int i)
    {
        return {max(ub[a[0][i]], rf[i]), lf[i]};
    }
    void build()
    {
        input();
        buildROQ();
        buildMIQ();
    }
    void update(int i)
    {
        ub[a[0][i]] = i+1;
    }
} ds;
void solve()
{
    ds.build();
    ll res = 0;
    for(int i = 0; i < ds.n; ++i)
    {
        pi range = ds.miq(i);
        ds.update(i);
        if(range.fi == range.se) {
            continue;
        }
        // [range.fi, i-1], [i+1, range.se]
        pi mc = {-1, -1};
        if(range.fi < i && (ds.roq(range.fi, i-1) & (~ds.a[0][i]))) { // we can pick something in l
            // use bs
            int l = range.fi; int r = i - 1;
            int best = -1;
            while(l <= r)
            {
                int m = l + (r - l) / 2;
                if((ds.roq(m, i-1) & (~ds.a[0][i])))
                {
                    best = m;
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
                
            }
            mc.fi = best;
        }
        if(range.se > i && (ds.roq(i+1, range.se) & (~ds.a[0][i]))) { // we can pick something in r
            // use bs
            int l = i+1; int r = range.se;
            int best = -1;
            while(l <= r)
            {
                int m = l + (r - l) / 2;
                if((ds.roq(i+1, m) & (~ds.a[0][i])))
                {
                    best = m;
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
                
            }
            mc.se = best;
        }
        ll delta = 0;
        if(mc.fi == -1 && mc.se == -1) continue;
        delta += ((mc.se == -1 ) ? 0LL : (ll)(range.se - mc.se + 1)) * (i - range.fi + 1) + ((mc.fi == -1 ) ? 0LL : (ll)(mc.fi - range.fi + 1)) * (range.se - i + 1);
        if(mc.se != -1 && mc.fi != -1)
        {
            delta -= (range.se - mc.se + 1) * ((ll)(mc.fi - range.fi + 1));
        }
        res += delta;
    }
    cout << res << endl;
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