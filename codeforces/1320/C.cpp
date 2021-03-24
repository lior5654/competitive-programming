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
const ll INFL = 1e17 + 5;
 
 
 
template<class T> using func = function<T>;
template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


 
 
 
 
//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

#define WEAPON -1

const int maxn = 2e5 +5;
const int maxm = 2e5 + 5;
const int maxp = 2e5 + 5;

int n, m, p;

struct event {
    ll x; ll c; ll y; // -1 for weapon
};

vector<event> ev;
map<ll, ll> defense_mp;

vl yu; vl yuc;
struct segtree {
    int tl; int tm; int tr; ll val; ll lazy; segtree* l; segtree* r;
    segtree(int _tl, int _tr) {
        tl = _tl; tr = _tr; tm = tl + (tr-tl)/2; val = 0; l=r=nullptr; lazy=0;
    }
    void pull() {
        if(l==nullptr || r==nullptr) return;
        val = max(l->val, r->val);
    }
    void push() {
        if(l==nullptr || r==nullptr) return;
        if(lazy) {
            l->val += lazy; r->val += lazy; l->lazy += lazy; r->lazy += lazy; lazy = 0;
        }
    }
    void build() {
        if(tl == tr) {
            val = -yuc[tl];
        } else {
            l = new segtree(tl, tm); r = new segtree(tm+1, tr);
            l->build(); r->build(); 
            pull();
        }
    }
    void add(int ql, int qr, ll v) {
        if(ql > qr || qr < tl || ql > tr) return;
        if(tl == ql && tr == qr) {
            val += v; lazy += v;
        } else {
            push();
            l->add(ql, min(qr, tm), v); r->add(max(ql,tm+1), qr, v);
            pull();
        }
    }
    ll query() {
        return this->val;
    }
};


void solve() {
    cin >> n >> m >> p;
    rep(i, n) {
        ll a; ll ca; cin >> a >> ca; 
        ev.push_back(event{.x=a, .c=ca, .y=WEAPON});
    }
    rep(i, m) {
        ll b; ll cb; cin >> b >> cb; 
        if(defense_mp.count(b)) {
            defense_mp[b] = min(defense_mp[b], cb);
        } else {
            defense_mp[b] = cb;
        }
    }
    rep(i, p) {
        ll x,y,z; cin >> x >> y >> z;
        ev.pb(event{.x=x, .c=z, .y=y});
    }
    for(const auto& e : defense_mp) {
        yu.pb(e.fi); yuc.pb(e.se);
    }
    ll res = -INFL;
    sort(all(ev), [&](const event& a, const event& b) {
        if(a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });
    segtree st(0, ((int)yu.size())-1);
    st.build();
    for(const auto& e : ev) {
        if(e.y == WEAPON) {
            res = max(res, st.query()-e.c);
        }
        else {
            auto it = upper_bound(all(yu), e.y);
            if(it != yu.end()){
                st.add((it-yu.begin()), ((int)yu.size())-1, e.c);
            }
        }
    }
    cout << res << '\n';



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
 
 
 
 
 
 
 
 
 
 
 
 