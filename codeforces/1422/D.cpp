
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

const int maxm = 1e5 + 5;
int n, m;
pl st; pl en;
int xid[maxm];
int yid[maxm];
pl tls[maxm];
vpl g[maxm];
ll d[maxm];
bitset<maxm> vis = 0;
void dijkstra()
{
    rep(i, m + 1)
    {
        d[i] = INFL;
    }
    priority_queue<pl, vpl, greater<pl>> pq;
    d[0] = 0;
    pq.push({0, 0});
    while(!pq.empty())
    {
        ll cr = pq.top().se; pq.pop();
        if(vis[cr]) continue;
        vis[cr] = true;
        for(auto e : g[cr])
        {
            if(d[cr] + e.se < d[e.fi])
            {
                d[e.fi] = d[cr] + e.se;
                pq.push({d[e.fi], e.fi});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> st.fi >> st.se >> en.fi >> en.se;
    rep(i, m)
    {
        cin >> tls[i+1].fi >> tls[i+1].se;
        xid[i+1] = i+1;
        yid[i+1] = i+1;
        
    }
    tls[0] = st;
    xid[0] = 0;
    yid[0] = 0;
    sort(xid, xid + m + 1, [&](int a, int b){return tls[a].fi < tls[b].fi;});
    sort(yid, yid + m + 1, [&](int a, int b){return tls[a].se < tls[b].se;});
    rep(i, m)
    {
        g[xid[i]].emplace_back(xid[i+1], tls[xid[i+1]].fi - tls[xid[i]].fi);
        g[yid[i]].emplace_back(yid[i+1], tls[yid[i+1]].se - tls[yid[i]].se);
        g[xid[i+1]].emplace_back(xid[i], tls[xid[i+1]].fi - tls[xid[i]].fi);
        g[yid[i+1]].emplace_back(yid[i], tls[yid[i+1]].se - tls[yid[i]].se);
    }
    dijkstra();
    ll res = INFL;
    rep(i, m + 1)
    {
        res = min(res, d[i] + abs(tls[i].fi - en.fi) + abs(tls[i].se - en.se));
    }
    cout << res <<'\n';

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