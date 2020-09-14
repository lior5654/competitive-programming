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

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ


































const int maxn = 1e5 + 5;

//#define BRUH_WHY_TESTCASES
int n, m, q;
map<string, int> wid;
ll rnk[maxn];
int p[maxn];
array<si, 2> lol[maxn];
int find(int x)
{
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
bool unify(int x, int y, int same)
{
    //cout << x << " " << y << " " << same << endl;
    int px = find(x); int py = find(y);
    int tx = 0; int ty = 0;
    if(lol[px][1].find(x) != lol[px][1].end())
    {
        tx = 1;
    }
    if(lol[py][1].find(y) != lol[py][1].end())
    {
        ty = 1;
    }
    if(px == py)
    {
        return tx ^ ty ^ same;
    }
    if(rnk[px] > rnk[py])
    {
        swap(px, py);
        swap(x, y);
        swap(tx, ty);
    }
    rnk[py] += rnk[px];
    p[px] = py;
    for(auto u : lol[px][tx])
    {
        lol[py][!(ty ^ same)].insert(u);
    }
    for(auto u : lol[px][!tx])
    {
        lol[py][(ty ^ same)].insert(u);
    }
    return true;

}
void solve()
{
    cin >> n >> m >> q; clrcin
    rep(i, n)
    {
        string cr;
        cin >> cr;
        wid[cr] = i;
        p[i] = i;
        lol[i][0].insert(i);
        rnk[i] = 1;
    }
    rep(i, m)
    {
        int type; string s, t; cin >> type; 
        cin>> s >> t;
        cout << (unify(wid[s], wid[t], !(type-1)) ? "YES" : "NO") << endl;
    }
    rep(i, q)
    {
        string u; string l; cin >> u >> l;
        if(find(wid[u]) != find(wid[l]))
        {
            cout << 3 << endl; continue;
        }
        int p =find(wid[u]);
        cout << ((lol[p][0].find(wid[u]) != lol[p][0].end() ^ lol[p][0].find(wid[l]) != lol[p][0].end()) ? 2 : 1) << endl;
    }



}










































int main()
{
    //GOGOGO
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