

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
//#define BRUH_WHY_TESTCASES
//#define PREC 7
//#define INPUT_FILE "hi.in"
//#define OUTPUT_FILE "hi.out"
/*** end #define flags ***/


struct Segtree {
    int tl; int tr; int tm; ll val; ll lazy; Segtree* l; Segtree* r;
    Segtree(){}
    Segtree(int _tl, int _tr) {
        tl=_tl; tr=_tr; tm = tl+(tr-tl)/2; l=r=nullptr; val=0; lazy = 0;
    }
    void pull() {
        val = l->val + r->val;
    }
    void push() {
        if(l==nullptr || r==nullptr) return;
        if(lazy) {
            l->val += lazy*(l->tr-l->tl+1); r->val += lazy*(r->tr-r->tl+1);
            l->lazy += lazy; r->lazy += lazy;
            lazy = 0;
        }
    }
    void build(ll* x) {  // NO INITIAL ARRAY
        if(tl == tr) {
            val = x[tl]; 
        } else {
            l = new Segtree(tl, tm); r = new Segtree(tm+1, tr);
            l->build(x); r->build(x);
            pull();
        }
    }
    void update(int ql, int qr, ll v) {
        if(ql > qr || qr < tl || ql > tr) return;
        if(ql == tl && qr == tr) {
            val += v*(tr-tl+1); lazy += v;
        } else {
            push();
            l->update(ql, min(tm, qr), v); r->update(max(ql,tm+1), qr, v);
            pull();
        }
    }
    ll query(int ql, int qr) {
        if(ql > qr || qr < tl || ql > tr) return 0;
        if(ql == tl && qr == tr) return val;
        push();
        return l->query(ql, min(tm, qr)) + r->query(max(ql,tm+1), qr);
    }
};

const int maxn = 2e5 + 5;


Segtree st; int n;

ll a[maxn]; ll k[maxn];



void solve() {
    cin >> n;
    rep(i, n) {
        cin >> a[i];
    } rep(i, n-1) {
        cin >> k[i];
    }

    set<int> bad_indicies;
    rep(i, n-1) {
        if(a[i+1] - a[i] > k[i]) {
            bad_indicies.insert(i);
        }
    }
    st = Segtree(0, n-1);
    st.build(a);
    int q; cin >> q;
    rep(_, q) {
        char type; cin >> type;
        if(type == '+') {
            int ind; ll val; cin >> ind >> val;
            if(val == 0) continue;
            
            ind--;
            if(ind != 0) {
                bad_indicies.insert(ind-1);
            }

            while(val && ind < n-1) {
                ll my_val = st.query(ind, ind);
                ll next_val = st.query(ind+1, ind+1);
                
                if(next_val - my_val - val >= k[ind]) {
                    st.update(ind, ind, val);
                    if(my_val + val == next_val - k[ind]) {
                        bad_indicies.erase(ind);
                    }
                    val = 0; break;
                }
                st.update(ind, ind, next_val - k[ind] - my_val);
                val -= next_val - my_val - k[ind] ;
                bad_indicies.erase(ind);
                
                auto next_it = bad_indicies.upper_bound(ind);
                if(next_it == bad_indicies.end()) break;
                int next_index = *next_it;
                st.update(ind, next_index - 1, val);
                ind = next_index;
            }
            if(ind < n) {
                st.update(ind, n-1, val);
            }
        } else {
            assert(type == 's'); int l, r; cin >> l >> r; --l; --r;
            cout << st.query(l, r) << '\n';
        }
    }

    


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

/****************************** end /main.cpp ******************************/





