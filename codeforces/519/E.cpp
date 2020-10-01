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


































const int maxn = 1e5 +5 ;
const int maxh = 18;
int n;
int p[maxh][maxn];
int d[maxn];
int sz[maxn];
int dt = 0;
int st[maxn];
int en[maxn];
vi g[maxn];

void dfs(int c, int par = 0, int dd = 0)
{
    p[0][c] = par;
    st[c] = ++dt;
    d[c] = dd;
    sz[c] = 1;
    for(auto e : g[c])
    {
        if(e!=par) {
            dfs(e, c, dd+1);
            sz[c] += sz[e];
        }
    }
    en[c] = dt;
}

void init()
{
    for(int h = 1; h < maxh; ++h)
    {
        for(int i = 1; i <= n; ++i)
        {
            p[h][i] = p[h-1][p[h-1][i]];
        }
    }
}
int raise(int b, int k)
{
    int h = 0;
    while (k)
    {
        if(k%2)
        {
            b = p[h][b];
        }
        h++;
        k /= 2;
    }
    return b;
}
int lca(int a, int b)
{
    if(a == b) return a;
    if(d[a] > d[b]) swap(a, b);
    b = raise(b, d[b] - d[a]);
    if(a == b) return a;
    for(int h = maxh - 1; h >= 0; --h)
    {
        if(p[h][a] != p[h][b])
        {
            a = p[h][a];
            b = p[h][b];
        }
    }
    return p[0][a];
}
/*
int dist(int a, int b)
{
    return d[a] + d[b] - 2*d[lca(a,b)];
}*/

//#define BRUH_WHY_TESTCASES
void solve()
{
    cin >> n;
    rep(i, n-1)
    {
        int s, t; cin >> s >> t;
        g[s].pb(t); g[t].pb(s);
    }
    dfs(1);
    init();
    int m; cin >> m;
    rep(i, m)
    {
        int x, y; cin >> x >> y;
        if(x == y)
        {
            cout << n << '\n';
            continue;
        }
        int lc = lca(x, y);
        int dxy = d[x] + d[y] - 2*d[lc];
        //cout << dxy << endl;
        // x farther from lca
        if(d[x] < d[y]) swap(x, y);
        if(dxy % 2)
        {
            cout << 0 << '\n'; continue;
        }
        int b = raise(x, dxy/2 - 1);
        int d = raise(y, dxy/2 - 1);
        int cent = p[0][b];
        int out = sz[cent] - sz[b];
        if(cent == lc)
        {
            out += sz[1] - sz[cent] - sz[d];
        }
        cout << out << '\n';


    }

}










































int main()
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