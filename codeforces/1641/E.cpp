/****************************** begin /template.h ******************************/

/***********************************************************************
 * [?] APIO 2021 Template
 * [+] Made By: Lior Yehezkely, FiveSixFiveFour
 * [~] Apples are ORZ
 * *********************************************************************/

/*** begin #define flags ***/
// #define USE_ORDERED_STATISTICS
// #define BIG_BIGINT
/*** end #define flags ***/

/*** begin includes ***/
#include <bits/stdc++.h>

#ifdef USE_ORDERED_STATISTICS
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
#endif

using namespace std;
/*** end includes ***/

/*** begin typedefs ***/
typedef long long int ll;
#ifdef BIG_BIGINT
    typedef __int128_t bigint;
#else
    typedef ll bigint;
#endif
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

template<class T> using func = function<T>;

#ifdef USE_ORDERED_STATISTICS
    typedef tree<
    pl,
    null_type,
    less<pl>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#endif

/*** end typedefs ***/

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
auto dist = uniform_int_distribution<int>(0, INFI); 
auto distll = uniform_int_distribution<ll>(0, INFL); 
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

/****************************** end /template.h ******************************/


/****************************** begin /main.cpp ******************************/


/*** begin #define flags ***/
// #define BRUH_WHY_TESTCASES
//#define PREC 7
// #define INPUT_FILE "maze2.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/














const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;

const ll mod = 998244353;  // I am assuming that this number is prime
ll half_power[maxn];
ll inv_half_power[maxn];
ll pre_half_power[maxn];

int n, m;
ll a[maxn];
ll p[maxm];  // 0 based and sorted increasingly

ll pre_a[maxn]; // prefix sum
ll wl_pre_a[maxn]; // prefix sum weighted linearly (by distance from 0)
ll wl_suf_a[maxn]; // prefix sum weighted linearly (by distance from n-1)
ll dp[maxn];

ll mpow(ll b, ll p) {
    ll res = 1; ll curr = b;
    while(p) {
        if(p%2ll) {
            res *= curr; res %= mod;
        }
        p /= 2ll;
        curr *= curr;
        curr %= mod;
    }
    return res;
}

ll mfix(ll x) {
    ll res = x % mod;
    if(x < 0) res += mod;
    return res;
}
ll minv(ll x) {
    return mpow(x, mod-2);
}
ll mmul(ll l, ll r) {
    return mfix((l*r));
}

ll madd(ll l, ll r) {
    return mfix(l+r);
}

ll msub(ll l, ll r) {
    return mfix(l-r);
}

const ll half = minv(2);
const ll inv_half = 2;

void input() {
    cin >> n >> m;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        cin >> p[i]; p[i]--;
    }
}

void calc_half_caches() {

    half_power[0] = 1;
    pre_half_power[0] = 1;
    inv_half_power[0] = 1;
    for(int i = 1; i <= n+1; i++) {
        half_power[i] = mmul(half, half_power[i-1]);
        inv_half_power[i] = mmul(inv_half, inv_half_power[i-1]);
        pre_half_power[i] = madd(pre_half_power[i-1], half_power[i]);
    }

}

void calc_a_caches() {
    pre_a[0] = a[0];
    wl_pre_a[0] = 0;
    wl_suf_a[n-1] = 0;
    for(int i = 1; i < n; i++) {
        pre_a[i] = madd(a[i], pre_a[i-1]);
        wl_pre_a[i] = madd(wl_pre_a[i-1], mmul(i, a[i]));
    }
    for(int i = n-2; i >= 0; i--) {
        wl_suf_a[i] = madd(wl_suf_a[i+1], mmul(n-1-i, a[i]));
    }

}

ll  asum(int l, int r) {
    return msub(pre_a[r], (l-1>=0?pre_a[l-1]:0));
}

ll  aincsum(int l, int r) {  // 0 * a[l] + 1 * a[l+1] + ...
    return msub(msub(wl_pre_a[r], (l-1>=0?wl_pre_a[l-1]:0)), l*asum(l,r));
}

ll  adecsum(int l, int r) {
    return msub(msub(wl_suf_a[l], (r+1<=n-1?wl_suf_a[r+1]:0)), (n-1-r)*asum(l,r));
}





inline ll gu(int x) {
    if(x<0 || x >n-1) return 0;
    return wl_pre_a[x];
}

inline ll gd(int x) {
    if(x<0 || x >n-1) return 0;
    return wl_suf_a[x];
}

inline ll g(int x) {
    if(x<0 || x >n-1) return 0;
    return pre_a[x];
}


// V(i, j) =  gu(pi + (pj - pi) / 2) - gu(pi - 1) - pi * (g(pi + (pj - pi) / 2) - g(pi - 1))  + gd(pj) - gd(pi + (pj - pi) / 2) - (n - 1- pj)* ( g(pj) - g(pi + (pj - pi) / 2))


inline ll h(int x) {  // the DEC thing
    return madd(mmul((n - 1 - x), g(x/2)), madd(gu(x/2),  gd(x/2+1))); // NOTE: check the x/2 + 1
}


//*********************************************************

const ll root = 15311432;
const ll root_1 = minv(root);
const ll root_pw = 1 << 23;

void fft(vector<ll> & vec, bool invert) {
    ll sz = vec.size();

    for (ll i = 1, j = 0; i < sz; i++) {
        ll bit = sz >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(vec[i], vec[j]);
    }

    for (ll len = 2; len <= sz; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);

        for (ll i = 0; i < sz; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = vec[i+j], v = (ll)(1LL * vec[i+j+len/2] * w % mod);
                vec[i+j] = u + v < mod ? u + v : u + v - mod;
                vec[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = minv(sz);
        for (ll & x : vec)
            x = (ll)(1LL * x * n_1 % mod);
    }
}

vector<ll> multiply(vector<ll> const& aa, vector<ll> const& bb) {
    vector<ll> fa(aa.begin(), aa.end()), fb(bb.begin(), bb.end());
    ll sz = 1;
    while (sz < aa.size() + bb.size()) 
        sz <<= 1;
    fa.resize(sz);
    fb.resize(sz);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < sz; i++) {
        fa[i] *= fb[i];
        fa[i] = mfix(fa[i]);
    }
    fft(fa, true);

    vector<ll> result(sz);
    for (ll i = 0; i < sz; i++)
        result[i] = mfix(fa[i]);
    return result;
}

//*********************************************************



ll res = 0;

// I have no idea what am I even doing at this point
void solvee(int l, int r) {  // the D & E parts, also with the corresponding probability of f(i)
    if (l>=r) return;

    int pl = p[l];
    int pr = p[r];

    const int sz = pr - pl + 1;
    vl p1(sz, 0);
    vl p2(sz, 0);
    int m = l;
    while(m < r && p[m+1] < (pl + pr) / 2) m++;

    for(int i = l; i <= m; i++) {
        p1[p[i]-pl] = inv_half_power[i];
    }

    for(int i = m+1; i <= r; i++) {
        p2[p[i]-pl] = half_power[i+1];
    }

    vl p3 = multiply(p1, p2);

   for(int i = 0; i < csz(p3); i++) {
        res = madd(res, mmul(h(i+2*pl), p3[i]));
    }

    p1.resize(0);
    p2.resize(0);
    p3.resize(0);
    solvee(l, m);
    solvee(m+1, r);

}



void printfr(ll x) {
    bool f = false;
    for(int i = 1; i <= 1000 && !f; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(mmul(i,minv(j)) == x) {
                cout << i << ' ' << j << '\n'; f = true; break;
            }
            if(mmul(-i,minv(j)) == x) {
                cout << -i << ' ' << j << '\n'; f = true; break;
            }
        }
    }
}
void solve(int t) {
    input();
    calc_half_caches();
    calc_a_caches();

    solvee(0, m-1);  // D+E+C

    
    bool f = false;


    ll b = 0;
    ll amul = 0;
    for (ll i = m-1; i >=0; i--) {
        ll pi = p[i];

        if(i < m-1) {
            res = madd(res, mmul(madd(-gu(pi-1), mmul(pi,g(pi-1))), amul));
            res = madd(res, b);
        
        }
        
        b = madd(b, mmul(madd(mmul(-1, gd(pi+1)), mmul(-1,mmul(n - 1- pi, g(pi)))), half));

        b = mmul(b, half);
        amul = madd(amul, half);
        amul  = mmul(amul, half);
    }





    for(int i = 0; i < m; i++) { // L and R
        res = madd(res, mmul(half_power[i+1], adecsum(0,p[i])));
        res = madd(res, mmul(half_power[m-1-i+1], aincsum(p[i],n-1)));
    }


    ll finalres = mmul(res, minv(mmul(inv_half_power[m]-1, minv(inv_half_power[m]))));
    cout <<  finalres << '\n';







}





































signed main()
{
    #ifdef INPUT_FILE
        freopen(INPUT_FILE, "r", stdin);
    #endif
    #ifdef OUTPUT_FILE
        freopen(OUTPUT_FILE, "w", stdout);
    #endif
    GOGOGO
    #ifdef PREC
      cout << fixed << setprecision(PREC);
    #endif
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
            cin >> t;
    #endif
    for(int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/

/****************************** end /main.cpp ******************************/





