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



#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<ll>(0, INFL);

ll grnd()
{
    return DIST(rng);
}

#define NO -1
const int maxn = 1e5 +5;

int n;
vi g[maxn];

int sdp[maxn] = { 0 };
pi sn[maxn];
int cdp[maxn] = { 0 };
int cn[maxn] = { 0 };
int par[maxn];
//vector<pi> cnc;
pi chain[maxn];
int tail = -1;
void dfs(int c, int p = 0) {
    int odeg = 0;
    par[c] = p;
    for(auto e : g[c]) {
        if(e!=p) {
            dfs(e, c);
            odeg++;
        }
    }
    if(odeg == 0) {
        sn[c] = {NO, NO}; cn[c] = NO; 
        if(c!= 1) {
            sdp[c] = 1;
        } else {
            sdp[c] = 0;
        }
        cdp[c] = 0; return;
    }

    // c - connected to papa
    int who = NO;
    int sm = 0;
    for(auto e : g[c]) {
        if(e!=p) {
            sm += sdp[e];
            if(who == NO || cdp[who] - sdp[who] > cdp[e] - sdp[e]) {
                who = e;
            }
        }
    }
    if(cdp[who] - sdp[who] < 0) {
         cdp[c] = sm - sdp[who] + cdp[who]; cn[c] = who;
    } else {
        cdp[c] = sm; cn[c] = NO;
    }
    // s - self 
    // we can connect up to 2 things
    vector<pi> val;
    for(auto e : g[c]) {
        if(e!=p) {
            val.emplace_back(e, cdp[e] - sdp[e]);
            
        }
    }
    sort(all(val), [&](const pi& x, const pi& y) {
        return x.se < y.se;
    });
    if(val.size() > 0 && val[0].se < 0) {
        
        if(val.size() > 1 && val[1].se < 0) {
            // both
            sdp[c] = 1 + sm + val[0].se + val[1].se;
            sn[c] = {val[0].fi, val[1].fi};
        } else {
            sdp[c] = 1 + sm + val[0].se;
            sn[c] = {val[0].fi, NO};
        }
    } else {
        sdp[c] = 1 + sm; sn[c] = {NO, NO};
    }

}

void dfs2(int c, bool st=false, int p = 0, int head=-1, bool zr = false) {
    
    if(st == false) {
        if(sn[c].fi == NO) {
            chain[c] = {c, c};
        } else if(sn[c].se == NO) {
            chain[c].se = c;
        }
        for(auto e : g[c]) {
            if(e != p) {
                if(e == sn[c].fi) {
                    dfs2(e, true, c, c, true);
                }
                else if(e == sn[c].se) {
                    dfs2(e, true, c, c, false);
                } else {
                    dfs2(e, false, c);
                }
            }
        }
    } else {
        if(cn[c] == NO) {
            if(zr) {
                chain[head].fi = c;
            } else {
                chain[head].se = c;
            }
        }
        for(auto e : g[c]) {
            if(e!=p) {
                if(e== cn[c]) {
                    dfs2(e, true, c, head, zr);
                } else {
                    dfs2(e, false, c);
                }
            }
        }
    }
}
void solve() {
    cin >> n;
    rep(i, n-1) {
        int s, t; cin >> s >> t;
        g[s].pb(t); g[t].pb(s);
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; ++i) {
        chain[i] = {NO, NO};
    }
    dfs2(1, false);
    vector<pair<pi, pi>> res;
    int lst = chain[1].fi;
    assert(lst != -1);
    for(int i = 2; i <= n; ++i) {
        if(chain[i].fi != NO) {
            res.pb({{i, par[i]}, {chain[i].fi, lst}});
            lst = chain[i].se;
        }
    }
    cout << res.size() << '\n';
    for(auto e : res) {
        cout << e.fi.fi << ' ' << e.fi.se << ' ' << e.se.fi << ' ' << e.se.se << '\n';
    }
    for(int i = 1; i <= n; ++i) {
        g[i].clear(); sn[i] = {NO, NO}; cn[i] = NO; chain[i] = {NO, NO};
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