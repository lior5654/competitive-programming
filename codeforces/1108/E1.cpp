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







typedef struct Segtree{
    int tl,tr,tm; int mn; int mx; int lazy;
    Segtree* l; Segtree* r;
    Segtree(int _tl, int _tr)
    {
        tl=_tl; tr=_tr; tm=tl + (tr-tl)/2;
        l=r=0; mn=mx=lazy=0;
    }
    void pull()
    {
        if(!l||!r)return;
        mn = min(l->mn, r->mn);
        mx = max(l->mx, r->mx);
    }
    void push()
    {
        if(!l||!r||!lazy) return;
        l->mn += lazy; r->mn += lazy;
        l->mx += lazy; r->mx += lazy;
        l->lazy += lazy; r->lazy += lazy;
        lazy=0;
    }
    void build(int ini[])
    {
        if(tl==tr)
        {
            mn=mx=ini[tl];
        }
        else
        {
            l = new Segtree(tl, tm); r = new Segtree(tm + 1, tr);
            l->build(ini); r->build(ini); pull();
        }
        
    }
    void radd(int ql, int qr, int v)
    {
        if(ql > qr || qr < tl || ql > tr) return;
        if(ql <= tl && tr <= qr)
        {
            mn += v; mx += v; lazy += v;
        }
        else
        {
            push();
            l->radd(ql, min(tm, qr), v); r->radd(max(ql, tm+1), qr, v);
            pull();
        }
        
    }
    int query()
    {
        return mx - mn;   
    }
} Segtree;


const int maxn = 1e5 + 5;
int a[maxn];
pi seg[301];
pair<vi, vi> g[maxn];
//#define BRUH_WHY_TESTCASES
void solve()
{
    int n, m; cin >> n >> m;
    aread(a+1, n);
    int best = -1;
    Segtree st(1, n);
    st.build(a);
    int ans = st.query();
    rep(i, m)
    {
        cin >> seg[i].fi >> seg[i].se; 
        g[seg[i].fi].fi.pb(i); g[seg[i].se].se.pb(i);

    }
    rep(i, m)
    {
        st.radd(seg[i].fi, seg[i].se, -1);
    }

    repk(i, 1, n+1)
    {
        for(auto e : g[i].fi)
        {
            st.radd(seg[e].fi, seg[e].se, +1);
        }
        for(auto e : g[i-1].se)
        {
            st.radd(seg[e].fi, seg[e].se, -1);
        }
        int maybe = st.query();
        if(maybe > ans)
        {
            ans = maybe; best = i;
        }
        ans = max(ans, st.query());
    }
    cout << ans << endl;
    if(best == -1)
    {
        cout << 0 << endl; return;
    }
    else
    {
        vi apply; for(int i = 0; i < m; ++i) {
            if(seg[i].se < best || seg[i].fi > best) apply.pb(i+1);
        }
        cout << apply.size() << endl;
        for(auto e : apply) cout << e << " ";
        cout << endl;
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