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


const int N = 2e5 + 5; const int M = 2e5 + 5;
class UnionFind
{
public:
    int rank[N+1] = { 0 }; int par[N+1]; int _n; int __c; bool f;
    int sz[N+1];
    UnionFind(int __n)
    {
        this->_n = __n;
        this->__c = 0; this->f = false;
        for(int i = 1; i <= this->_n; ++i)
        {
            this->par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == this->par[x]) return x;
        return this->par[x] = find(this->par[x]);
    }
    bool unify(int x, int y)
    {
        x = find(x); y = find(y);
        if (x == y) return false;
        this->__c++;
        if (this->__c == this->_n - 1) f = true;
        if (this->rank[x] > this->rank[y])
        {
            x += y;
            y = x - y;
            x -= y;
        }
        if(this->rank[x] == this->rank[y]) this->rank[y]++;
        this->par[x] = y;
        sz[y] += sz[x];
        return true;
    }
};

const int maxn = 2e5 + 5;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vi g[maxn];
int n, m;
struct lol
{
    int l; int r; int papa;
};
vector<lol> seg;
void solve()
{
    cin >> n >> m;
    rep(i, m)
    {
        int s, t; cin >> s >> t; g[s].pb(t); g[t].pb(s);
    }
    for(int i = 1; i<= n; ++i)
    {
        sort(all(g[i]));
    }
    int nxt = 0;
    for(int i = 1; i<= n; ++i)
    {
        nxt = 1;
        for (auto e : g[i])
        {
            if(e-nxt >= 1)
            {
                seg.pb(lol{nxt, e-1, i});
            }
            nxt = e+1;
        }
        if(n+1-nxt >= 1)
        {
            seg.pb(lol{nxt, n, i});
        }
    }
    sort(all(seg), [&](const lol& a, const lol& b){
            if(a.r == b.r)
            {
                return a.l < b.l;
            }
            return a.r < b.r;});
    set<int> dads;
    int currentL = 0;
    int currentR = 0;
    UnionFind killme(n);
    for(auto e : seg)
    {
        if(e.l == e.r)
        {
            killme.unify(e.l, e.papa);
        }
        if(e.l > currentR)
        {
            if(currentR!=0)
            {
                for(int i = currentL; i < currentR; ++i)
                {
                    killme.unify(i, i+1);
                }
                auto it = dads.begin();
                killme.unify(*it, currentR);
                int old = *it;
                it++;
                while(it != dads.end())
                {
                    killme.unify(old, *it);
                    old = *it;
                    ++it;
                }
            }
            currentR = e.r;
            currentL = e.l;
            dads.clear();
            dads.insert(e.papa);
        }
        else
        {
            dads.insert(e.papa);
            currentR = e.r;
        }
        
    }
    if(currentR!=0)
    {
        for(int i = currentL; i < currentR; ++i)
        {
            killme.unify(i, i+1);
        }
        auto it = dads.begin();
        killme.unify(*it, currentR);
        int old = *it;
        it++;
        while(it != dads.end())
        {
            killme.unify(old, *it);
            old = *it;
            ++it;
        }
    }
    bitset<maxn> vis = 0;
    vi sizes;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[killme.find(i)])
        {
            sizes.pb(killme.sz[killme.find(i)]);
            vis[killme.find(i)] = true;

        }
    }
    sort(all(sizes));
    cout << sizes.size() << '\n';
    for(auto s : sizes)
    {
        cout << s << " ";
    }
    cout << '\n';


}

 
 
 
 
 
 
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