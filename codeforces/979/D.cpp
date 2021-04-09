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
template<class T> void aread(T* arr, int _n)
{
    rep(i, _n)
    {
        cin >> arr[i];
    }
}
 
 
 
 
 
//#define BRUH_WHY_TESTCASES
//#define PREC 10
//#define USACO "sleepy"

const int maxk = 1e5 + 5;
const int maxh = 17;
struct trie {
    static const int root = 0;
    vector<array<int, 2>> t;
    vector<array<int, 2>> tm;
    int next_id = 1;
    trie() {
        t.pb(array<int, 2>({-1, -1}));
        tm.pb(array<int, 2>({INFI, INFI}));
    }
    void insert(int u) { // insert u into the trie
        int bits[maxh];
        int ou = u;
        rep(i, maxh) {
            bits[maxh-1-i] = u&1;
            u /= 2;
        }
        int curr = root;
        int i = 0;
        for(; i < maxh && t[curr][bits[i]] != -1; ++i) { tm[curr][bits[i]] = min(tm[curr][bits[i]], ou); curr = t[curr][bits[i]]; }
        for(; i < maxh; ++i) {t[curr][bits[i]] = next_id++; tm[curr][bits[i]] = ou; t.pb(array<int, 2>({-1, -1})); tm.pb(array<int, 2>({INFI, INFI})); curr = t[curr][bits[i]]; }
    }
    int query(int x, int c) { // return max(x^v) where v <= c
        int oc = c;
        int xbits[maxh]; int cbits[maxh];
        rep(i, maxh) {
            xbits[maxh-1-i] = x&1; cbits[maxh-1-i] = c&1; x /= 2; c /= 2;
        }
        int curr = root;
        bool c_limit = true;
        int v = 0;
        for(int i = 0; i < maxh; ++i) {
            assert(curr !=-1);
            if(c_limit && t[curr][1] == -1 || tm[curr][1] > oc) {
                if(t[curr][0] == -1) return -1;
                curr = t[curr][0];
            } else {
                if(xbits[i] == 0) {
                    if(t[curr][1] != -1) {
                        curr = t[curr][1];
                        v += 1 << (maxh - 1 - i);
                    } else {
                        c_limit = false;
                        curr = t[curr][0];
                    }
                } else {
                    if(t[curr][0] != -1) {
                        c_limit = false;
                        curr = t[curr][0];
                    } else {
                        curr = t[curr][1];
                        v += 1 << (maxh - 1 - i);
                    }
                }
            }
        }
        return v;
    }
} ds[maxk];
int sieve[maxk];
int q;

void init_sieve() {
    sieve[1] = 0;
    for(int i = 2; i < maxk; ++i) {
        if(!sieve[i]) {
            for(int j = i; j < maxk; j += i) {
                sieve[j] = i;
            }
        }
    }
}
void insert_number(int u, int lft, int taken=1) { // O(number of divisors)
    if(lft == 1) {
        ds[taken].insert(u);
    } else {
        int x = sieve[lft];
        int cnt = 0;
        while(sieve[lft] == x) {
            cnt++;
            lft /= x;
        }
        int tadd = 1;
        rep(i, cnt+1) {
            insert_number(u, lft, taken * tadd);
            tadd *= x;
        }
    }
}
void solve() {
    init_sieve();
    cin >> q;
    rep(i, q) {
        int type; cin >> type;
        if(type == 1) {
            int u; cin >> u; // add u
            insert_number(u, u);
        } else {
            int x, k, s; cin >> x >> k >> s;
            if(x%k || x > s) {
                cout << -1 << '\n'; continue;
            } else {
                cout << ds[k].query(x, s-x) << '\n';
            }
        }
    }
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
 
 
 
 
 
 
 
 
 
 
 
 