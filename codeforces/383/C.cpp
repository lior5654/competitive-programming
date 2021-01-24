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
 
#define popcnt __builtin_popcountll
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

 
 
















 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES

const int maxn = 2e5 + 5;


vi g[maxn]; int st[maxn]; int ist[maxn]; int en[maxn]; ll a[maxn]; int dt = 0; int n, m; bool colr[maxn];
struct Segtree {
    int tl; int tr; int tm; ll val; Segtree* l; Segtree* r;

    Segtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2; val=0; l=r=nullptr;
    }
    void build() {
        if(tl==tr) {
            val=a[ist[tl]];
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(); r->build();
        }
    }
    void add(int ql, int qr, ll off) {
        if(ql > qr || ql > tr || qr < tl) return;
        if(ql == tl && qr == tr) {
            val += off;
        } else {
            l->add(ql, min(qr, tm), off); r->add(max(ql, tm+1), qr, off);
        }
    }
    ll query(int pos) {
        if(tl == tr) return val;
        if(pos <= tm) {
            return val + l->query(pos);
        } else {
            return val + r->query(pos);
        }
    }
};

void dfs(int c, int p=0) {
    colr[c] = !colr[p];
    st[c] = ++dt;
    ist[dt] = c;
    for(auto e : g[c]) {
        if(e != p) dfs(e, c);
    }
    en[c]=dt;
}
void solve() {
    cin >> n >> m;
    rep(i, n) {
        cin >> a[i+1];
    }
    rep(i, n - 1) {
        int s, t; cin >> s >> t;
        g[s].pb(t); g[t].pb(s);
    }
    dfs(1);
    Segtree btree(1,n); Segtree wtree(1,n);
    btree.build(); wtree.build();
    rep(i, m) {
        int type; cin >> type;
        if(type == 1) {
            int x; ll val; cin >> x >> val;
            if(colr[x]) {
                wtree.add(st[x], en[x], val);
                btree.add(st[x], en[x], -val);
            } else {
                wtree.add(st[x], en[x], -val);
                btree.add(st[x], en[x], val);
            }
        } else {
            int x; cin >> x; cout << (colr[x]?wtree.query(st[x]):btree.query(st[x])) << '\n';
        }
    }

}

 





















































 
signed main()
{
    GOGOGO
    //cout << fixed << setprecision(6);
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
