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
//#define PREC 7
//#define USACO "sleepy"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<ll>(0, INFL);

ll grnd()
{
    return DIST(rng);
}

#define EPS 1e-6

const int maxn = 1e3 + 5;
int n, m;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

inline bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}
bitset<maxn> mat[maxn];
bitset<maxn> vis[maxn] = { 0 };
ll d[maxn][maxn] = { 0 };
ll t; 
void solve() {
    cin >> n >> m;
    cin >> t;
    rep(i, n) {
        rep(j, m) {
            char c; cin >> c;
            mat[i][j] = c - '0';
        }
    }
    rep(i, n) {
        rep(j, m) {
            d[i][j] = INFI;
        }
    }
    queue<pi> bfs; queue<pi> nxt;
    rep(i, n) {
        rep(j, m) {
            rep(k, 4) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(valid(ni, nj) && mat[i][j] == mat[ni][nj]) {
                    d[i][j] = 0;
                    nxt.push({i, j});
                    break;
                }
            }
        }
    }
    while(!nxt.empty()) {
        swap(nxt, bfs);
        while(!bfs.empty()) {
            auto c = bfs.front(); bfs.pop();
            int i = c.fi; int j = c.se;
            if(vis[i][j]) continue;
            vis[i][j] = true;
            rep(k, 4) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(valid(ni, nj) && !vis[ni][nj]) {
                    if(mat[i][j] == mat[ni][nj]) {
                        d[ni][nj] = min(d[ni][nj], d[i][j]);
                        bfs.push({ni, nj});
                    } else {
                        d[ni][nj] = min(d[ni][nj], d[i][j]+1);
                        nxt.push({ni, nj});
                    }
    
                }
            }
        }
    }
    /*
    rep(i, n) {
        rep(j, m) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }*/
    rep(_, t) {
        int i, j; cin >> i >> j;
        --i; --j;
        ll p; cin >> p; 
        if(d[i][j] == INFI) {
            cout << mat[i][j] << '\n'; continue;
        }
        p -= d[i][j];
        p = max(p, 0LL);
        cout << ((p%2) ? !mat[i][j] : mat[i][j]) << '\n';
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