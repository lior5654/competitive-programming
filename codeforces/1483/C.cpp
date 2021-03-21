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

const int maxn = 3e5 +5;

struct segtree{
    int tl; int tm; int tr; ll val; segtree* l; segtree* r;
    segtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm=tl+(tr-tl)/2; val = 0; l=r=nullptr;
    }
    void build() {
        if(tl != tr) {
            l = new segtree(tl, tm); r = new segtree(tm+1, tr);
            l->build(); r->build();
        }
    }
    void set(int pos, ll v) {
        if(tl == tr) {
            assert(tl == pos); val = v;
        } else {
            if(pos <= tm) {
                l->set(pos, v);
            } else {
                r->set(pos, v);
            }
            val = max(l->val, r->val);
        }
    }
    ll query(ll ql, ll qr) {
        if(ql > qr || qr < tl || ql > tr) return -INFL;
        if(tl == ql && qr == tr) {
            return val;
        }
        return max(l->query(ql, min(qr, (ll)tm)), r->query(max(ql, (ll)tm+1), qr));
    }
};

int fl[maxn]; int n;
ll h[maxn];
ll b[maxn];
ll dp[maxn];
void solve() {
    cin >> n;
    for(int i =1; i <= n; ++i) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    stack<int> s;
    for(int i = 1; i <= n; ++i) {
        while(!s.empty() && h[s.top()] >= h[i]) s.pop();
        if(s.empty()) fl[i] = 0;
        else fl[i] = s.top();
        s.push(i);
    }
    cout << endl;
    segtree st(0,n);
    st.build();
    for(int i = 1; i <= n; ++i) {
        dp[i] = st.query(fl[i], i-1) + b[i];
        if(fl[i]!=0) {
            dp[i] = max(dp[i], dp[fl[i]]);
        }
        st.set(i, dp[i]);
    }
    cout << dp[n] << '\n';

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
 
 
 
 
 
 
 
 
 
 
 
 