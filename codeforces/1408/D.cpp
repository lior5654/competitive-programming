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


































const int maxn = 2e3 + 5;
int n, m;
pi rob[maxn];
pi ser[maxn];
vpi sr;
vpi rb;
//#define BRUH_WHY_TESTCASES
void solve()
{
    cin >> n >> m;
    rep(i, n)
    {
        cin >> rob[i].fi >> rob[i].se;
    }
    rep(i, m)
    {
        cin >> ser[i].fi >> ser[i].se;
    }
    vpi annoying;
    rep(i, n)
    {
        rep(j, m)
        {
            if(rob[i].fi <= ser[j].fi && rob[i].se <= ser[j].se)
            {
                annoying.pb({ser[j].fi -rob[i].fi + 1, ser[j].se - rob[i].se + 1});
            }
        }
    }
    int sz = annoying.size();
    if(!sz)
    {
        cout << 0 << '\n'; return;
    }
    sort(all(annoying));
    vi mx(sz+1);
    mx[sz] = 0;
    for(int i = sz - 1; i >= 0; --i)
    {
        mx[i] = max(mx[i+1], annoying[i].se);
    }
    int res = INFI;
    for(int i = 0; i < sz; ++i)
    {
        res = min(res, annoying[i].fi + mx[i+1]);
    }
    res = min(res, mx[0]);
    res = min(res, annoying[sz-1].fi);
    cout << res << '\n';

    /*
    sort(rob, rob + n, [&](const pi& a, const pi& b){return a.fi < b.fi;});
    sort(ser, ser + m, [&](const pi& a, const pi& b){return a.se > b.se;});
    int lx = -1;
    for(int i = 0; i < m; ++i)
    {
        if(ser[i].fi > lx)
        {
            sr.pb(ser[i]);
            lx = ser[i].fi;
        }
    }
    int ly = INFI;
    for(int i = 0; i < n; ++i)
    {
        if(rob[i].se < ly)
        {
            rb.pb(rob[i]);
            ly = rob[i].se;
        }
    }
    int sz = sr.size();
    int rsz = rb.size();
    vi yc(rsz, 0);
    vi xc(rsz, 0);

    int cs = 0;

    for(auto r : rb)
    {
        while(cs < m && r.fi > sr[cs].fi)
        {
            ++cs;
        }
        if(cs == m) continue;
        if(sr[cs].se < r.se) continue;

    }*/




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