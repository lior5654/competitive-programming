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
pi,
null_type,
less<pi>,
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

 
 
 
 
 







typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(str.size()+1), pw(ha) {
		pw[0] = 1;
		for(int i = 0; i < str.size(); ++i)     
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (str.size() < length) return {};
	H h = 0, pw = 1;
	for(int i = 0; i < length; ++i)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	for(int i = length; i < str.size(); ++i) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}


















 
 
 
 
 
 
 
 
//#define BRUH_WHY_TESTCASES

const int maxn = 1e5 + 5;

const ll mod = 1e9 + 7;


ll bexp(ll b, ll p) {
    ll curr = b; ll res = 1;
    while(p) {
        if(p%2LL){
            res *= curr;
            res %= mod;
        } 
        curr *= curr;
        curr %= mod;
        p /= 2LL;
    }

    return res;
}




ll a[maxn];
ll b[maxn];
ll dpg[maxn];
ll dpe[maxn];
void solve() {
    ll n, m; cin >> n >> m;
    const ll invm = bexp(m, mod - 2);
    const ll SP =((((((((m-1LL) * m) % mod) * invm) % mod) * invm) % mod) * bexp(2, mod - 2)  % mod); 
    rep(i, n) {
        cin >> a[i+1];
    } rep(i,n) {
        cin >> b[i+1];
    }

    dpe[0] = 1;
    dpg[0] = 0;

    bool f = false;
    for(int i = 1; i <= n; ++i) {
        if(a[i] != 0 && b[i] != 0 && a[i] != b[i]) {
            cout << (dpg[i-1] + (a[i] > b[i] ? dpe[i-1] : 0)) % mod << '\n';
            return;
        }
        if(a[i] == 0){
            dpe[i] = dpe[i-1] * invm;
            dpe[i] %= mod;
            dpg[i] = dpg[i-1] + (dpe[i-1] * (((b[i] == 0 ? SP : (((m-b[i]) * invm)))) % mod)) % mod;
            dpg[i] %= mod;
        } else if (b[i] == 0) {
            dpe[i] = dpe[i-1] * invm;
            dpe[i] %= mod;
            dpg[i] = dpg[i-1] + (dpe[i-1] * (((a[i] == 0 ? SP : (((a[i]-1LL) * invm)))) % mod)) % mod;
            dpg[i] %= mod;
        } else {
            dpe[i] = dpe[i-1];
            dpe[i] %= mod;
            dpg[i] = dpg[i-1];
            dpg[i] %= mod;
        }
        f |= a[i] != 0 && b[i] != 0;

    }
    cout << dpg[n] << '\n';

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
