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

#define EPS 1e-9 // epsilon for comparing doubles

template<class T> struct pt {
    T x; T y;
    pt() : x(0), y(0) {}
    pt(T _x, T _y) : x(_x), y(_y) {}
    pt& operator += (const pt& other) { x+=other.x; y+=other.y; return *this; }
    pt operator +(const pt& other) const { return pt(x+other.x, y+other.y); } 
    pt& operator -= (const pt& other) { x-=other.x; y-=other.y; return *this; }
    pt operator -(const pt& other) const { return pt(x-other.x, y-other.y); }
    pt& operator*=(T c) { x*=c; y*=c; return *this; }
    pt operator*(T c) const { return pt(c*x, c*y); }
    pt operator/(T c) const { assert(abs(c) > EPS); return pt(x/c, y/c); }
    pt& operator/=(T c) { assert(abs(c) > EPS); x/=c; y/=c; return *this; }
    T operator *(const pt& other) const { return x*other.x + y*other.y;}  // dot product
    T operator %(const pt& other) const { return x*other.y - y*other.x;}  // cross product
    friend ostream& operator << (ostream &os, const pt<T> &p) {
        return os << p.x << ' ' << p.y;
    }
    friend istream& operator >> (istream &is, pt<T> &p) {
        return is >> p.x >> p.y;
    }
};
using ptl = pt<ll>; // use for integer coords
using ptd = pt<ld>; // use for double coords

template<class T> T sgn(T x) { // sign(x) = 1 if x is > 0, 0 if x is 0, negative 1 otherwise
    if(x > EPS) return 1;
    if(x < -EPS) return -1;
    return 0;
}
template<class T> T dir(const pt<T>& o, const pt<T>& d, const pt<T>& t) { // orientation
    return sgn((d-o) % (t-o));
}
template<class T> bool intersect1d(T l1, T r1, T l2, T r2) {
    if(r1<l1) swap(l1, r1);
    if(r2<l2) swap(l2, r2);
    return max(l1, l2) <= min(r1, r2);
}
bool intersect(const ptl& a1, const ptl& a2, const ptl& b1, const ptl& b2) {
    return dir(a1,a2,b1) * dir(a1,a2,b2) <= 0 &&
           dir(b1,b2,a1) * dir(b1,b2,a2) <= 0 &&
           intersect1d(a1.x,a2.x,b1.x,b2.x) && intersect1d(a1.y,a2.y,b1.y,b2.y);
}

struct Seg {
    int tl; int tr; int tm; ll val; Seg* l; Seg* r;
    Seg(int _tl, int _tr) {
        tl = _tl; tr = _tr; tm = tl + (tr - tl) / 2; l=r=0; val = INFL;
    }
    void pull() {
        if(!l || !r) return;
        val = min(l->val, r->val);
    }
    void build() {
        if(tl == tr) {
            val = INFL;
        }
        else {
            l = new Seg(tl, tm); r = new Seg(tm+1, tr);
            l->build(); r->build();
        }
    }
    void update(int pos, ll v) {
        if(tl == tr) {
            assert(tl == pos);
            val = v;
        } else {
            if(pos <= tm) {
                l->update(pos, v);
            } else {
                r->update(pos, v);
            }
            pull();
        }
    }
    ll query(int ql, int qr) {
        if(ql > qr || qr < tl || ql > tr) {
            return INFL;
        }
        if(tl == ql && tr == qr) {
            return val;
        } return min(l->query(ql, min(tm, qr)), r->query(max(ql, tm+1), qr));
    }
};
const int maxn = 1e5 + 5;
ll dp[maxn];


struct node {
    ll a; ll c;
    bool operator < (const node& other) const {
        return a < other.a;
    }
} nodes[maxn];

int n;
void solve() {
    cin >> n;
    ll res = 0;
    rep(i, n) {
        cin >> nodes[i].a >> nodes[i].c;
        res += nodes[i].c;
    }
    sort(nodes, nodes+n, [&](const node& a, const node& b) {
        return a.a < b.a;
    });
    dp[n-1] = 0;
    Seg s1(0, n-1); Seg s2(0, n-1);
    s1.build(); s2.build();
    s1.update(n-1, 0);
    s2.update(n-1, nodes[n-1].a);
    for(int i = n-2; i >= 0; --i) {
        int ind = (upper_bound(nodes, nodes+n, node{.a=nodes[i].c + nodes[i].a, .c=69}) - nodes) - 1;
        dp[i] = min(s1.query(i+1, ind), s2.query(max(ind+1, i+1), n-1) -nodes[i].a -nodes[i].c);
        s1.update(i, dp[i]);
        s2.update(i, dp[i] + nodes[i].a);
    }
    cout << dp[0] + res << '\n';
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
 
 
 
 
 
 
 
 
 
 
 
 